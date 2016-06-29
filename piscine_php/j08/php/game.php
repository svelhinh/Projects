<?php

require_once("class/Player.class.php");

session_start();

// echo $_SESSION['round'];

if ($_SESSION['round'] % 2 != 0)
{
	// echo $player1->ship->x . "<br />";
	// echo $player1->ship->y . "<br />";
	// echo $player1->ship->direction . "<br />";
	// echo "1";
	if ($_POST['direction'] == 'up')
		$_SESSION['player1']->getShip()->moveup($_SESSION['player2']->getShip());
	if ($_POST['direction'] == 'down')
		$_SESSION['player1']->getShip()->movedown($_SESSION['player2']->getShip());
	if ($_POST['direction'] == 'left')
		$_SESSION['player1']->getShip()->moveleft($_SESSION['player2']->getShip());
	if ($_POST['direction'] == 'right')
		$_SESSION['player1']->getShip()->moveright($_SESSION['player2']->getShip());
	if ($_POST['shoot'] == "shoot")
		$_SESSION['player1']->getShip()->shoot($_SESSION['player2']->getShip());
	$_SESSION['round']++;
	// echo $player1->ship->x . "<br />";
	// echo $player1->ship->y . "<br />";
	// echo $player1->ship->direction . "<br />";
}
else
{
	// echo $player1->ship->x . "<br />";
	// echo $player1->ship->y . "<br />";
	// echo $player1->ship->direction . "<br />";
	// echo "2";
	if ($_POST['direction'] == 'up')
		$_SESSION['player2']->getShip()->moveup($_SESSION['player1']->getShip());
	if ($_POST['direction'] == 'down')
		$_SESSION['player2']->getShip()->movedown($_SESSION['player1']->getShip());
	if ($_POST['direction'] == 'left')
		$_SESSION['player2']->getShip()->moveleft($_SESSION['player1']->getShip());
	if ($_POST['direction'] == 'right')
		$_SESSION['player2']->getShip()->moveright($_SESSION['player1']->getShip());
	if ($_POST['shoot'] == "shoot")
		$_SESSION['player2']->getShip()->shoot($_SESSION['player1']->getShip());
	$_SESSION['round']++;
	// echo $player1->ship->x . "<br />";
	// echo $player1->ship->y . "<br />";
	// echo $player1->ship->direction . "<br />";
}

?>
