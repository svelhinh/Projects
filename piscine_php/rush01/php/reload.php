<?php
	include_once("../class/Map.class.php");
	include_once("../class/Player.class.php");
	include_once("../class/Explozer.class.php");
	include_once("../class/NewOrk.class.php");
	require_once("connection.php");

$data2 = $db->prepare('SELECT player1, player2, round FROM games_in_progress WHERE id_game=?;');
$data2->execute(array( $_GET['id'] ));
$data = $data2->fetch();

$player1 = unserialize($data['player1']);
$player2 = unserialize($data['player2']);
$round = $data['round'];

?>
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
	else
				{
					if ($player1->getShip()->destructed())
						echo "<script>alert('Player \"" . $player2->getName() . "\" wins !!!');</script>";
					else
						echo "<script>alert('Player \"" . $player1->getName() . "\" wins !!!');</script>";
					echo "<meta http-equiv='refresh' content='0;url=php/lobby.php' />";
				}
	?>
</span>