<?php
	include_once("class/Map.class.php");
	include_once("class/Player.class.php");
	include_once("class/Explozer.class.php");
	include_once("class/NewOrk.class.php");
	session_start();

	function resetGame()
	{
		session_start();
		if (isset($_SESSION['player1']))
			unset($_SESSION['player1']);
		if (isset($_SESSION['player2']))
			unset($_SESSION['player2']);
		if (!$_GET['player1'] || !$_GET['player2'] || $_GET['player1'] === "null" || $_GET['player2'] === "null")
			echo '<script type="text/javascript" >
					var player1 = prompt("Nom Joueur 1 :");
					var player2 = prompt("Nom Joueur 2 :");
					location.href="./index.php?player1="+player1+"&player2="+player2;
				</script>';
		$_SESSION['round'] = 0;
		$ship1 = new Explozer( array('x' => 1, 'y' => 1, 'direction' => 'right') );
		$ship2 = new NewOrk( array('x' => 148, 'y' => 98, 'direction' => 'left') );
		if ($_GET['player1'] && $_GET['player2'] && $_GET['player1'] !== "null" && $_GET['player2'] !== "null")
		{
			$_SESSION['player1'] = new Player( array('name' => $_GET['player1'], 'ship' => $ship1 ) );
			$_SESSION['player2'] = new Player( array('name' => $_GET['player2'], 'ship' => $ship2 ) );
		}
	}

	if ($_POST['reset'] == 'reset')
	{
		resetGame();
		unset($_POST['reset']);
	}

	if (!isset($_SESSION['player1']) || !isset($_SESSION['player2']))
		resetGame();
?>

<!DOCTYPE html>

<html>

	<head>
		<title>Warhammer 40000</title>
		<meta charset="utf-8" />
		<link rel="stylesheet" type="text/css" href="css/game.css" />
	</head>

	<body>
		<?php
			include_once("php/game.php");
			$map = new Map();
			$map->loadMap($_SESSION['player1'], $_SESSION['player2']);
		echo "<div class='buttons'>";
			if (!$_SESSION['player1']->getShip()->destructed() && !$_SESSION['player2']->getShip()->destructed())
			{	
				if ($_SESSION['round'] % 2 != 0)
					echo "<h1>" . $_SESSION['player1']->getName() . "</h1>";
				else
					echo "<h1>" . $_SESSION['player2']->getName() . "</h1>";
				echo "<div class='player1'>";
				print $_SESSION['player1'];
				echo "</div>";
				echo "<div class='player2'>";
				print $_SESSION['player2'];
				echo "</div>";
			}
			else
			{
				if ($_SESSION['player1']->getShip()->destructed())
					echo "<script>alert('Player \"" . $_SESSION['player2']->getName() . "\" wins !!!');</script>";
				else
					echo "<script>alert('Player \"" . $_SESSION['player1']->getName() . "\" wins !!!');</script>";
				echo "<form action='index.php' method='post'>
							<input type='submit' name='reset' value='reset'>
						</form>";
				exit();
			}
		?>
		<div class="submits">
		<form action='index.php' method='post'>
			<input type='submit' name='direction' value='up'>
			<br/>
			<input type='submit' name='direction' value='left'><input type='submit' name='direction' value='right'>
			<br/>
			<input type='submit' name='direction' value='down'>
			<br/>
			<input type='hidden' value='1'>
			<input type='submit' name='shoot' value='shoot'>
			<p>
			<input type='submit' name='reset' value='reset'>
			</p>
		</form>
	</div>
	</div>
	</body>

</html>