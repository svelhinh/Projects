<?php
session_start();
// **********************Panier********************
$product_list = unserialize(file_get_contents('data/product'));
$i = 0;
  foreach ($_POST as $key2 => $value)
  {
    if ($i == 1)
      $key = $key2;
    $i++;
  }

  foreach ($product_list as $name)
  {
    if ($name['nom'] == $key)
    {
      $product = $name;
      break ;
    }
  }
$i = 0;
while ($_SESSION['to_print'][$i])
{
 ?>
  <div class="vitrine-defaut">
    <h4 class="vitrine-titre"><?=$_SESSION['to_print'][$i]['nom']?></h4>
    <!-- FORMULAIRE POUR LE PANIER  -->
    <form method="post" action="index.php">
      <input class="vitrine-qt" type="number" maxlength="2" min="1" max="<?=$_SESSION['to_print'][$i]['quantite']?>" name="quantite" value="1"/>
      <input type="hidden" name="<?=$_SESSION['to_print'][$i]['nom']?>" value="<?=$_SESSION['to_print'][$i - 1]?>">
      <input class="vitrine-sub" type="submit" name="submit" value="Ajouter"/>
    </form>
    <!-- ************************** -->
    <img class="vitrine-img" title="<?php echo $_SESSION['to_print'][$i]['description'];?>" src="<?php echo $_SESSION['to_print'][$i]['image'];?>" alt="<?$_SESSION['to_print'][$i]['nom'];?>"/>
    <h4 id ="vitrine-prix"><?=$_SESSION['to_print'][$i]['prix']?>€</h4>
  </div>
<?php
$i++;
}
?>
