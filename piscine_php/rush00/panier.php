<?php

session_start();

$_POST["image"] = "images/vins/blanc/blanc-bordeaux-nadeau.jpg";
$_POST["nom"] = "Nadeau";
$_POST["quantite"] = "2";
$_POST["prix"] = "3.5";
$_POST['submit'] = "Ajouter";

if ($_POST['submit'] == "Ajouter")
{
	if (!$_SESSION['panier'])
		$_SESSION['panier'] = array($_POST);
	else
		array_push($_SESSION['panier'], $_POST);
}
else if ($_POST['submit'] == "Vider")
	unset($_SESSION['panier']);
?>

<html>
	<head>
		<title>Accueil</title>
		<meta charset="utf-8" />
		<link rel="stylesheet" href="css/panier.css" />
	</head>
	<body>
		<div class="panier">
			<img style="width: 30%;" src="images/panier.png" />
			<div class="produits">
<?php
if ($_SESSION['panier'])
	foreach ($_SESSION['panier'] as $products)
	{
		echo '<div>';
		echo '<img class="vin" src="'.$products["image"].'"/>';
		echo '<div class="nom">'.$products["nom"].'</div>';
		echo '<div class="quantite">'.$products["quantite"].'</div>';
		echo '<div class="prix">'.$products["prix"].'&euro;</div>';
		echo '</div>';
		echo '<hr />';
	}
?>
				<input class="valider" type="button" value="Valider" />
<?php
if (!$_SESSION['panier'])
{
	echo '<form method="post">';
	echo '<input class="vider" type="image" name="submit" src="images/corbeille.jpg" value="Vider" />';
	echo '</form>';
}
?>
			</div>
		</div>
	</body>
</html>
