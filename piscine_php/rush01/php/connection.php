<?php

$host = "localhost";
$user = "root";
$pass = "root";

$db_name = "rush01";

try
{
	$db = new PDO("mysql:host=$host; dbname=$db_name", $user, $pass);
	$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
}
catch(PDOException $e)
{
	echo "Connection failed: " . $e->getMessage();
	die();
}

?>
