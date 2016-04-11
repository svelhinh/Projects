<?php
	session_start();
?>

<!DOCTYPE html>
<html>
	<head>
		<title>Wine Advisor</title>
		<meta charset=utf-8>
		<meta name=viewport content="width=device-width, initial-scale=1">
		<link rel="stylesheet" type="text/css" href="css/style.css">
		<link rel="stylesheet" type="text/css" href="css/panier.css">
		<link rel="stylesheet" type="text/css" href="css/vitrine.css">
	</head>
	<body>

		<div id="site">
			<header id="title">
				<a href="index.php">
					<h1>Wine advisor</h1>
					<h5>Votre sommerlier attitré</h5>
				</a>
			</header>
			<div id="shop">
				<aside id="side">
					<section id="login">
						<header><div><?php echo ($_SESSION["login"] ? "Bienvenue " . $_SESSION["login"] : "Connectez vous" )?></div></header>
						 <?php include("php/login.php") ?>
					</section>
					<section id="categories">
						<header><div>Categories</div></header>
							<?php include("php/categories.php"); ?>
						</form>
					</section>
					<section id=panier>
						<header><div>Panier</div></header>
						<?php include("php/panier.php"); ?>
					</section>
				</aside>
				<section id="vitrine">
					<?php include("php/vitrine.php"); ?>
				</section>

			</section>
		</div>

	</body>
</html>
