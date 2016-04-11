<?php
function get_prod($db, $p_name)
{
  foreach ($db as $p_tab)
    if ($p_tab['nom'] == $p_name)
      return ($p_tab);
}

function replace_db($p_data, $path)
{
  $db = unserialize(file_get_contents("../data/product"));
  foreach ($db as $id => $prod)
  {
    if($prod['nom'] == $p_data['nom'])
      {
        $db[$id] = $p_data;
      }
  }
  file_put_contents("../data/product", serialize($db));
}

session_start();
$product_list = unserialize(file_get_contents("../data/product"));
foreach ($product_list as $product_id)
{
	if ($_POST['name'] == $product_id['nom'])
		$to_print = $product_id;
}
echo "<link rel='stylesheet' type='text/css' href='../css/modif_stock.css'>";
?>
<div id="all">
  <form method="post">
<div id="index_line"><h5 id="modif_index">Nom</h5><h5 id="modif_stock">Stock</h5><h5 id="modif_prix">Prix</h5><h5 id="modif_tags">Mot cles</h5><h5 id="modif_descri">Description</h5><h5 id="modif_suppr">Supprimer</h5></div>
<div id="modif_line">
    <img href="imagelink"/>
    <input id="modif_index2" type="text" name="nom" value="<?=$to_print['nom']?>" size="20"/>
    <input id="modif_stock2" type="number" min="0"  name="quantite" value="<?=$to_print['quantite']?>"/>
    <input id="modif_prix2"type="number" min="0"  name="prix" value="<?=$to_print['prix']?>"/>
    <input id="modif_tags2"type="text" name="tags" value="<?=$to_print['tags']?>"/>
    <input id="modif_descri2"type="text" name="description" value="<?=$to_print['description']?>"/>
    <input id="modif_suppr2" type="checkbox" name="delete" value="delete"/>
    <input id="modif_submit" type="submit" name="submit" value="Valider"/>
  </form>
</div>
<?php
if($_POST['submit'] == "Valider")
{
  $product_list = unserialize(file_get_contents("../data/product"));
  $product_data = get_prod($product_list, $_POST['nom']);
  $product_data['nom'] = $_POST['nom'];
  $product_data['quantite'] = $_POST['quantite'];
  $product_data['prix'] = $_POST['prix'];
  $product_data['tags'] = $_POST['tags'];
  $product_data['description'] = $_POST['description'];
  replace_db($product_data, "../data/product");
  echo "<META HTTP-EQUIV='Refresh' Content='0; URL=./admprod.php'/>";
}
?>
