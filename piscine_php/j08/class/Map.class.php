<?php

class Map
{
	const X = 150;
	const Y = 100;

	function loadMap ( Player $player1, Player $player2 )
	{
		echo "<table class='map'>";
		for ($y=0; $y < self::Y; $y++)
		{
			echo "<tr>";
			for ($x=0; $x < self::X; $x++)
			{
				if ($player1->getShip()->getX() == $x && $player1->getShip()->getY() == $y)
					echo "<td><img title='" . $player1->getShip()->getName() . "' src='". $player1->getShip()->getSprite() . "' class='" . $player1->getShip()->getDirection() . "' />";
				else if ($player2->getShip()->getX() == $x && $player2->getShip()->getY() == $y)
					echo "<td><img title='" . $player2->getShip()->getName() . "' src='". $player2->getShip()->getSprite() . "' class='" . $player2->getShip()->getDirection() . "' />";
				else
					echo "<td></td>";
			}
			echo "</tr>";
		}
		echo "</table>";
	}
	public static function doc()
	{
		echo file_get_contents("Map.doc.txt");
	}
}

?>