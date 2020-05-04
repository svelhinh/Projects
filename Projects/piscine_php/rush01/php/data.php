<?php

require_once("php/connection.php");

$data2 = $db->prepare('SELECT id_game, player1, player2, round FROM games_in_progress WHERE id_game=?;');
$data2->execute(array( $_GET['id'] ));
$data = $data2->fetch();

$player1 = unserialize($data['player1']);
$player2 = unserialize($data['player2']);
$round = $data['round'];
$id = $data['id_game'];

?>