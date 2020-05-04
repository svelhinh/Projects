<?php

session_start();

if ($_GET['submit'] == "OK")
{
	$_SESSION['login'] = $_GET['login'];
	$_SESSION['passwd'] = $_GET['passwd'];
}

?>
<html><body>
<form method="get">
	Identifiant: <input name="login" value="<?php echo $_SESSION['login']; ?>" />
	<br />
	Mot de passe: <input name="passwd" value="<?php echo $_SESSION['passwd']; ?>" />
	<input type="submit" name="submit" value="OK" />
</form>
</body></html>
