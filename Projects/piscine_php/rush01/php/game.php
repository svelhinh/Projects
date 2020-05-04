<?php

session_start();
include_once("../class/Map.class.php");
include_once("../class/Player.class.php");
include_once("../class/Explozer.class.php");
include_once("../class/NewOrk.class.php");
require_once("connection.php");

$data3 = $db->prepare('SELECT player1, player2, round FROM games_in_progress WHERE id_game=?;');
$data3->execute(array( $_SESSION['id'] ));
$data1 = $data3->fetch();

$player1 = unserialize($data1['player1']);
$player2 = unserialize($data1['player2']);
$round = $data1['round'];

// print_r($_POST);
// echo $round;

// print_r($_POST);

if ($round % 2 == 0)
{
	// echo $player1->ship->x . "<br />";
	// echo $player1->ship->y . "<br />";
	// echo $player1->ship->direction . "<br />";
	// echo "1";
	if ($_POST['direction'] == 'up')
		$player1->getShip()->moveup($player2->getShip());
	if ($_POST['direction'] == 'down')
		$player1->getShip()->movedown($player2->getShip());
	if ($_POST['direction'] == 'left')
		$player1->getShip()->moveleft($player2->getShip());
	if ($_POST['direction'] == 'right')
		$player1->getShip()->moveright($player2->getShip());
	if ($_POST['shoot'] == "shoot")
		$range = $player1->getShip()->shoot($player2->getShip());
	$round++;
	// echo $player1->ship->x . "<br />";
	// echo $player1->ship->y . "<br />";
	// echo $player1->ship->direction . "<br />";
}
else
{
	// echo $player2->getShip()->getX() . "<br />";
	// echo $player2->getShip()->getY() . "<br />";
	// echo $player2->getShip()->getDirection() . "<br />";
	// echo "2";
	if ($_POST['direction'] == 'up')
		$player2->getShip()->moveup($player1->getShip());
	if ($_POST['direction'] == 'down')
		$player2->getShip()->movedown($player1->getShip());
	if ($_POST['direction'] == 'left')
		$player2->getShip()->moveleft($player1->getShip());
	if ($_POST['direction'] == 'right')
		$player2->getShip()->moveright($player1->getShip());
	if ($_POST['shoot'] == "shoot")
		$player2->getShip()->shoot($player1->getShip());
	$round++;
	// echo $player1->ship->x . "<br />";
	// echo $player1->ship->y . "<br />";
	// echo $player1->ship->direction . "<br />";
}

$update = $db->prepare("UPDATE `games_in_progress` SET `player1`=?,`player2`=?,`round`=? WHERE `id_game`=?");
$update->execute(array(
	serialize($player1),
	serialize($player2),
	$round,
	$_SESSION['id'] ));

?>
