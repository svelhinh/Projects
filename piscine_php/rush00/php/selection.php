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
    if ($name['nom'] == $key)
    {
      $product = $name;
      break ;
	}
?>
<div id="vitrine-center" >
  <div class="vitrine-encart" id="vitrine-meilleursvente">
    <h4 class="vitrine-titre">Meilleurs ventes</h4>
    <!-- FORMULAIRE POUR LE PANIER  -->
    <form method="post" action="index.php">
      <input class="vitrine-qt" type="number" maxlength="2" max="<?=$_SESSION['selection'][0]['quantite']?>" min="1" name="quantite" value="1"/>
      <input type="hidden" name="<?=$_SESSION['selection'][0]['nom']?>" value="<?=$_SESSION['selection'][0]?>">
      <input class="vitrine-sub" type="submit" name="submit" value="Ajouter"/>
    </form>
    <!-- ************************** -->
    <img class="vitrine-img" title="<?php echo $_SESSION['selection'][0]['description'];?>" src="<?php echo $_SESSION['selection'][0]['image'];?>" alt="<?$_SESSION['selection'][0]['nom'];?>"/>
  </div>
  <div class="vitrine-encart" id="vitrine-lebonplan">
    <h4 class="vitrine-titre">Le Bon Plan</h4>
    <!-- FORMULAIRE POUR LE PANIER  -->
    <form method="post" action="index.php">
      <input class="vitrine-qt" type="number" maxlength="2" min="1" name="quantite" max="<?=$_SESSION['selection'][1]['quantite']?>" value="1"/>
      <input type="hidden" name="<?=$_SESSION['selection'][1]['nom']?>" value="<?=$_SESSION['selection'][1]?>">
      <input class="vitrine-sub" type="submit" name="submit" value="Ajouter"/>
    </form>
    <!-- ************************** -->
    <img class="vitrine-img" title="<?php echo $_SESSION['selection'][1]['description'];?>" src="<?php echo $_SESSION['selection'][1]['image'];?>" alt="<?$_SESSION['selection'][1]['nom'];?>"/>
  </div>
  <div class="vitrine-encart" id="vitrine-lanouvelle">
    <h4 class="vitrine-titre">La Nouvelle</h4>
    <!-- FORMULAIRE POUR LE PANIER  -->
    <form method="post" action="index.php">
      <input class="vitrine-qt" type="number" maxlength="2" min="1" name="quantite" value="1" max="<?=$_SESSION['selection'][2]['quantite']?>"/>
      <input type="hidden" name="<?=$_SESSION['selection'][2]['nom']?>" value="<?=$_SESSION['selection'][2]?>">
      <input class="vitrine-sub" type="submit" name="submit" value="Ajouter"/>
    </form>
    <!-- ************************** -->
    <img class="vitrine-img" title="<?php echo $_SESSION['selection'][2]['description'];?>" src="<?php echo $_SESSION['selection'][2]['image'];?>" alt="<?$_SESSION['selection'][2]['nom'];?>"/>
  </div>
  <div class="vitrine-encart" id="vitrine-laselection">
    <h4 class="vitrine-titre">Notre Selection</h4>
    <!-- FORMULAIRE POUR LE PANIER  -->
    <form method="post" action="index.php">
      <input class="vitrine-qt" type="number" maxlength="2" min="1" name="quantite" value="1" max="<?=$_SESSION['selection'][3]['quantite']?>"/>
      <input type="hidden" name="<?=$_SESSION['selection'][3]['nom']?>" value="<?=$_SESSION['selection'][3]?>">
      <input class="vitrine-sub" type="submit" name="submit" value="Ajouter"/>
    </form>
    <!-- ************************** -->
    <img class="vitrine-img" title="<?php echo $_SESSION['selection'][3]['description'];?>" src="<?php echo $_SESSION['selection'][3]['image'];?>" alt="<?$_SESSION['selection'][3]['nom'];?>"/>
  </div>
</div>
