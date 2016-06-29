<?php
session_start();
include_once("connection.php");
if (isset($_SESSION['login']))
	header("Location: lobby.php");
if (isset($_POST['signup']) && isset($_POST['login']) && isset($_POST['pass1']) && isset($_POST['pass2']))
{
	$login = $_POST['login'];
	$pass1 = $_POST['pass1'];
	$pass2 = $_POST['pass2'];
	if ($pass1 == $pass2)
	{
		$count = $db->prepare("SELECT login FROM `user` WHERE login = ?");
		$count->execute(array($login));
		$boum = $count->fetch();
		if (strlen($login) > 8)
			echo "Your login is too long.";
		else if ($boum['login'] === $login)
			echo "This user exists.";
		else 
		{
			$hash = hash('whirlpool', $pass1);
			$count = $db->prepare("INSERT INTO `user` (login, pass) VALUES (?, ?)");
			$count->execute(array($login, $hash));
			echo "Successful !";
		}
	}
	else
		echo "Error !";
}
else if ($_POST['signin'] && isset($_POST['login']) && isset($_POST['passwd']))
{
	$login = $_POST['login'];
	$hash = hash('whirlpool', $_POST['passwd']);
	$count = $db->prepare("SELECT id, login FROM `user` WHERE login = ? AND pass = ?");
	$count->execute(array($login, $hash));
	$boum = $count->fetch();
	if ($boum['login'] === $login)
	{
		$_SESSION['id'] = $boum['id'];
		$_SESSION['login'] = $boum['login'];
		header("Location: lobby.php");
	}
	else
	{
		$_SESSION['login'] = '';
		$_SESSION['id'] = '';
		echo "Error !";
	}
}
?>

<!DOCTYPE hmtl>
<hmtl>
<head>
	<title>Warhammer 40000</title>
	<link rel="stylesheet" type="text/css" href="../css/style.css">
</head>
<body>
	<header>
		<img src="../img/Warhammer40000.png" alt="Warhammer 40000" title="Warhammer 40000" />
	</header>
	<div id="middle">
		<div id="login">
			<h1>Log In</h1>
			<form method="post">
			<input type="text" name="login" placeholder="Username">
			<br>
			<input type="password" name="passwd" placeholder="Password">
			<br>
			<input type="hidden" value="submit">
			<input type="submit" name="signin" value="Valider" class="sub">
			</form>
		</div>
		<div id="signup">
			<h1>Sign up</h1>
			<form method="post">
			<input type="text" name="login" placeholder="Username">
			<br>
			<input type="password" name="pass1" placeholder="Password">
			<br>
			<input type="password" name="pass2" placeholder="Verify Password">
			<br>
			<input type="hidden" value="submit">
			<input type="submit" name="signup" value="Valider" class="sub">
			</form>
		</div>
		<div class="shadow"></div>
		<div class="shadow2"></div>
	</div>
</body>
</html>