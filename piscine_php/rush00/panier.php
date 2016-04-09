<?php

session_start();

$_POST["image"] = "images/vins/blanc/blanc-bordeaux-nadeau.jpg";
$_POST["nom"] = "Nadeau";
$_POST["quantite"] = "2";
$_POST["prix"] = "3.5";

if ($_POST && $_POST["submit"] == "Ajouter")
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
		<form method="post">
			<input type="submit" name="submit" value="Ajouter" />
		</form>
		<div class="panier">
			<img style="width: 30%;" src="images/panier.png" />
<?php
if ($_SESSION['panier'])
{
	echo '<div class="produits">';
	$total = 0;
	$quantite = 0;
	foreach ($_SESSION['panier'] as $products)
	{
		echo '<div>';
		echo '<img class="vin" src="'.$products["image"].'"/>';
		echo '<div class="nom">'.$products["nom"].'</div>';
		echo '<div class="quantite">'.$products["quantite"].'</div>';
		echo '<div class="prix">'.$products["prix"].'&euro;</div>';
		echo '</div>';
		echo '<hr class="line" />';
		$total += $products["prix"];
		$quantite += $products["quantite"];
	}
	echo '<div class="total">TOTAL : </div>';
	echo '<div class="quantite">'.$quantite.'</div>';
	echo '<div class="prix">'.$total.'&euro;</div>';
	echo '<hr class="line" />';
	echo '<input class="valider" type="button" value="Valider" />';
	echo '<form method="post">';
	echo '<input class="corbeille" type="image" name="submit" src="images/corbeille.jpg" value="Vider" />';
	echo '</form>';
	echo '</div>';
}
else
	echo '<div class="vide"><p class="panier_vide">PANIER VIDE</p></div>';
?>
		</div>
	</body>
</html>
