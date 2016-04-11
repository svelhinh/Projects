<?php
	header('Location: ../index.php');
	session_start();
	unset($_SESSION["panier"]);
	unset($_SESSION["login"]);
	unset($_SESSION["adm"]);
	exit;
?>