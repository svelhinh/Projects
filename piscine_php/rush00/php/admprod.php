<?PHP

session_start();
$i = 0;
$product_list = unserialize(file_get_contents("../data/product"));
while ($product_list[$i])
{
?>

<div class="....">
<h4 class="titre...."<?=$product_list[$i]["nom"]?></h4>
<h4 class="number..."<?=$product_list[$i]["quantite"]?></h4>
<img class="produit_image..." title="<?php echo $product_list[$i]["description"]?>" src="<?php echo "../".$product_list[$i]['image'];?>" alt="<?$product_list[$i]['nom'];?>"/>
<form method="post" action="admin_modif_stock.php">
<input class="...." type="submit" name="name"value="<?=$product_list[$i]['nom']; ?>"
<?PHP
	$value = 0;
	while ($product_list[$value]["nom"])
	{
		if ($_POST[$product_list[$value]["name"]] == "Modif")
		{
			$_SESSION['modif_print'] = $product_list[$value];
		}
		$value++;
	}
?>/>
</form>
</div>

<?PHP
	$i++;
}
$i = 0;
while ($product_list[$i])
{
	if ($_POST[$product_list[$i]["name"]] == "Modif")
	{
		$_SESSION['modif_product'] = $product_list[$i];
		echo '<META HTTP-EQUIV="Refresh" Content="0; URL=./admin_modif_stock.php"/>';
	}
	$i++;
}
?>

<div class="..."
<h4 class="retour"></h4>
<form method="post" action = "../admin_page.php">
<input class="press it" type="submit" name="retour" value="RETOUR"/>
</form>
</div>

<?PHP

if ($POST['retour'] == "RETOUR")
{
	echo '<META HTTP-EQUIV="Refresh" Content="0; URL=./admin_page.php"/>';
}

?>

<div class="..."
<h4 class="ajout"></h4>
<form method="post" action = "admin_modif_stock.php">
<input class="press out" type="submit" name="ajout" value="AJOUTER UN PRODUIT"/>
</form>
</div>

<?PHP

if ($POST['ajout'] == "AJOUTER UN PRODUIT")
{
	$_SESSION['modif_product'] = array();
	echo '<META HTTP-EQUIV="Refresh" Content="0; URL=./admin_modif_stock.php"/>';
}

?>
