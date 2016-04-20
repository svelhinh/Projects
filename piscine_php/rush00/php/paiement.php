<?php
session_start();
if (!$_SESSION['panier'])
	header("Location: ../index.php");
?>

<!DOCTYPE html>
<html>
	<head>
		<title>Wine Advisor</title>
		<meta charset=utf-8>
		<meta name=viewport content="width=device-width, initial-scale=1">
		<link rel="stylesheet" type="text/css" href="../css/style.css">
		<link rel="stylesheet" type="text/css" href="../css/panier.css">
	</head>
	<body>

		<div id="site">
			<header id="title">
				<a href="../index.php">
					<h1>Wine advisor</h1>
					<h5>Votre sommelier attitré</h5>
				</a>
			</header>
			<div id="shop">
				<section id="paiement">
						<?php
						if (substr($_POST['commande'], strlen($_POST['commande']) - 3, strlen($_POST['commande'])) == "del")
						{
							$name = substr($_POST['commande'], 0, strlen($_POST['commande']) - 3);
							$i = 0;
							foreach ($_SESSION['panier'] as $prods)
							{
								if ($name == $prods['nom'])
									array_splice($_SESSION['panier'], $i, 1);
								$i++;
							}
							if ($_SESSION['panier'])
								$_POST['submit'] = "Valider";
							else
								echo "<META HTTP-EQUIV='Refresh' Content='0'; URL'/paiement.php'/>";
						}
						if ($_POST['submit'] == "Valider")
						{
						  echo '<div>';
						  $total = 0;
						  $quantite = 0;
						  foreach ($_SESSION['panier'] as $products)
						  {
						    echo '<div>';
						    echo '<img class="vin" src="../'.$products["image"].'"/>';
						    echo '<div class="nom">'.$products["nom"].'</div>';
						    echo '<div class="quantite">'.$products["quantite"].'</div>';
						    echo '<div class="prix">'.$products["prix"].'&euro;</div>';
						  echo '<form method="post">';
							echo '<input class="corbeille_paiement" type="image" name="commande" src="../images/corbeille.jpg" value="'.$products["nom"].'del" />';
						  echo '</form>';
						    echo '</div>';
						    echo '<hr class="line" />';
						    $total += $products["prix"] * $products["quantite"];
						    $quantite += $products["quantite"];
						  }
						  echo '<div class="total">TOTAL : </div>';
						  echo '<div class="quantite">'.$quantite.'</div>';
						  echo '<div class="prix">'.$total.'&euro;</div>';
						  echo '<hr class="line" />';
						  echo '<form action="../index.php" method="post">';
						  echo '<input class="annuler" type="submit" name="cart" value="Annuler" />';
						  echo '</form>';
						  echo '<form action="../index.php" method="post">';
						  echo '<input class="commander" type="submit" name="submit" value="Commander" />';
						  echo '</form>';
						}
						?>
				</section>

			</section>
		</div>

	</body>
</html>
