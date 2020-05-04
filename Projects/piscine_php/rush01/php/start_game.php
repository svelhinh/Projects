<?php
	session_start();
	echo '<link rel="stylesheet" type="text/css" href="../css/style.css" />';
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
   	
    $requete = $bdd->prepare("SELECT * FROM `games_in_progress` WHERE id_game = ?;");
	  $requete->execute(array($_GET['id']));
    $donnees = $requete->fetch();
    if ($donnees == null  || !isset($_SESSION['login'])) 
      echo '<meta http-equiv="refresh" content="0;url=lobby.php" />';
  	
    $ret;
    $i = 0;
    foreach ($donnees as $key => $val)
    {
   	  if (!isset($val))
   	  {
   	   $ret = $key;
       break ;
      }
      if ($i / 2 == 4)  
        echo '<meta http-equiv="refresh" content="0;url=lobby.php" />';
      $i++;
   	}
    $requete->closeCursor();

    if ($ret == 'player1')
    {
      $x = 0;
      $y= 0;
    }
    else if ($ret == 'player2')
    {
      $x = 149;
      $y= 99;
    }
    else if ($ret == 'player3')
    {
      $x = 0;
      $y= 99;
    }
    else if ($ret == 'player4')
    {
      $x = 149;
      $y= 0;
    }

    $ship = new Explozer( array('x' => $x, 'y' => $y, 'direction' => 'right') );
    $player = new Player( array('name' => $_SESSION['login'], 'ship' => $ship ) );
    $stock_players = $bdd->prepare("UPDATE games_in_progress SET " . $ret . " = ? WHERE id_game = ?;");
    $stock_players->execute( array( serialize($player), $_GET['id'] ) );
    echo "<form action='../index.php' method=get'>
    <input type='hidden' name='id' value='" . $_GET["id"] . "'>
    <input type='submit' value='Launch the game' class='sub'>
    </form>";
?>