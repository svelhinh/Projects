<?php

$host = "localhost";
$user = "root";
$pass = "root";

$db_name = "rush01";

try
{
	$db = new PDO("mysql:host=$host", $user, $pass);
	$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
}
catch(PDOException $e)
{
	echo "Connection failed: " . $e->getMessage();
	die();
}

$requests = "
			CREATE DATABASE IF NOT EXISTS $db_name;
			USE $db_name;
			CREATE TABLE user
			(
				id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
				login VARCHAR(8) UNIQUE KEY DEFAULT 'player',
				pass VARCHAR(512) NOT NULL
			);
			CREATE TABLE ranking
			(
				id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
				victories INT DEFAULT 0 NOT NULL,
				losses INT DEFAULT 0 NOT NULL
			);
			CREATE TABLE chat
			(
				id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
				id_user INT NOT NULL,
				message TEXT,
				date DATETIME NOT NULL
			);
			CREATE TABLE games_in_progress
			(
				id_game INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
				player1 TEXT DEFAULT NULL,
				player2 TEXT DEFAULT NULL,
				player3 TEXT DEFAULT NULL,
				player4 TEXT DEFAULT NULL,
				groupe ENUM ('running', 'waiting') DEFAULT 'waiting' NOT NULL,
				round INT DEFAULT 0 NOT NULL
			);
				";

try
{
    $db->exec($requests);
	header("Location: php/login.php");
}
catch (PDOException $e)
{
    echo $e->getMessage();;
    die();
}
 // $db->exec("DROP DATABASE $db_name;");
//unlink("log/log");

?>
