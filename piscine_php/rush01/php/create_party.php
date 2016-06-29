<?php
	include_once("../class/Player.class.php");
	include_once("../class/Explozer.class.php");
	include_once("../class/NewOrk.class.php");
  try
  {
      $bdd = new PDO('mysql:host=localhost;dbname=rush01', 'root', 'root');
  }
  catch (Exception $e)
  {
      die('Erreur : ' . $e->getMessage());
  } 
  $ship = new Explozer( array('x' => 50, 'y' => 50, 'direction' => 'right') );
  $player = new Player( array('name' => $_SESSION['login'], 'ship' => $ship1 ) );
  $bdd->exec('INSERT INTO games_in_progress () VALUES ();');
  $requete = $bdd->query('SELECT id_game FROM games_in_progress ORDER BY id_game DESC LIMIT 1;');
  $donnees = $requete->fetch();
  echo '<meta http-equiv="refresh" content="0;url=start_game.php?id=' . $donnees['id_game'] . '" />';
?>