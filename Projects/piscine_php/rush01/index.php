<?php
	session_start();
	include_once("class/Map.class.php");
	include_once("class/Player.class.php");
	include_once("class/Explozer.class.php");
	include_once("class/NewOrk.class.php");
	include_once("php/data.php");
?>

<!DOCTYPE html>

<html>

	<head>
		<title>Warhammer 40000</title>
		<meta charset="utf-8" />
		<link rel="stylesheet" type="text/css" href="css/game.css" />
	</head>

	<body>
	<span class="submits">
		<?php $_SESSION['id'] = $_GET['id']; ?>
		<form action='php/game.php' method='post'>
			<input type='submit' name='direction' value='up' id='up'>
			<br/>
			<input type='submit' name='direction' value='left' id='left'><input type='submit' name='direction' value='right' id='right'>
			<br/>
			<input type='submit' name='direction' value='down' id='down'>
			<br/>
			<input type='hidden' value='1' id='play'>
			<input type='submit' name='shoot' value='shoot' id='shoot'>
		</form>
	</span>	
	<span id="load_map">
		<?php
			$map = new Map();
			$map->loadMap($player1, $player2);
				echo "<div class='buttons'>";
				if (!$player1->getShip()->destructed() && !$player2->getShip()->destructed())
				{	
					if ($round % 2 != 0)
						echo "<h1>" . $player1->getName() . "</h1>";
					else
						echo "<h1>" . $player2->getName() . "</h1>";
					echo "<div class='player1'>";
					print $player1;
					echo "</div>";
					echo "<div class='player2'>";
					print $player2;
					echo "</div>";
				}
		?>
	</div>
</span>
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js"></script>
    	<script src="js/play.js"></script>
	</body>

</html>