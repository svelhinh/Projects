<?php

function recursive_search($to_find, $count, $step, $prod_list)
{
  foreach ($prod_list as $prod_id)
  {
    $tags = explode(",", $prod_id['tags']);
    foreach($tags as $tag)
    {
      if (trim($tag) == $to_find[$step] && $prod_id['quantite'] != "0")
        $tab[] = $prod_id;
    }
  }
  $step += 1;
  if ($count == $step)
    return($tab);
  return(recursive_search($to_find, $count, $step, $tab));
}

session_start();
$product_list = unserialize(file_get_contents('data/product'));

$filter_categories = [];

  if ($_POST['submit'] == "cat")
  {
      $_SESSION["type"] = $_POST["type"];
      $_SESSION["region"] = $_POST["region"];
      $_SESSION["degre"] = $_POST["degre"];
      $_SESSION["prix"] = $_POST["prix"];
  }
    if ($_SESSION["type"])
      array_push($filter_categories, $_SESSION["type"]);
    if ($_SESSION["region"])
      array_push($filter_categories, $_SESSION["region"]);
    if ($_SESSION["degre"])
      array_push($filter_categories, $_SESSION["degre"]);
    if ($_SESSION["prix"])
      array_push($filter_categories, $_SESSION["prix"]);

$nb_tags = count($filter_categories);
$_SESSION['selection'] = array_slice($product_list,0,4);
if (!$filter_categories)
   include('selection.php');
else
{
  if ($filter_categories[0] == "all")
    $_SESSION['to_print'] = $product_list;
  else
  {
     $_SESSION['to_print'] = recursive_search($filter_categories, $nb_tags, 0, $product_list);
  }
  include('product.php');
}


?>
