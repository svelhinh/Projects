<?php
session_start();
if (!isset($_SESSION['login']))
	header("Location: login.php");
if ($_POST['submit'] == 'Logout')
{
	unset($_SESSION['login']);
	unset($_SESSION['id']);
	header("Location: login.php");
}
?>
<!DOCTYPE html>
<hmtl>
<head>
	<title>Lobby</title>
	<link rel="stylesheet" type="text/css" href="../css/style.css" />
</head>
<body>
	<div id="page_lobby">
		<?php
			if ($_POST['submit'] == "Create")
				include "create_party.php";
			else
				include "list_party.php";
		?>
	</div>
	<div id="menu_lobby">
	<form method="post">
		<input type="submit" name="submit" value="Create" class="sub">
		<br />
		<input type="submit" name="submit" value="Join" class="sub"/>
		<br />
		<input type="submit" name="submit" value="Logout" class="sub"/>
	</div>
	<iframe src="chat.php" id="chat" scrolling="auto">
		<p>Your browser does not support iframes.</p>
	</iframe>
	<form method="POST" action="traitement.php">
    	<input name="message" id="message" size="255" />
    	<input type="submit" id="envoi" name="submit" value="Envoyer" class="sub"/>
	</form>
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js"></script>
	<script src="../js/chat.js"></script>
</form>
</body>
</hmtl>