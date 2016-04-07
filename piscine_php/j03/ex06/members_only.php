<?php

$username = "zaz";
$usermdp = "jaimelespetitsponeys";

if ($_SERVER['PHP_AUTH_USER'])
{
	$name = $_SERVER['PHP_AUTH_USER'];
	$mdp = $_SERVER['PHP_AUTH_PW'];
}

if ($name == $username && $mdp == $usermdp)
{
	$str = file_get_contents("../img/42.png");
	$img = base64_encode($str);
	echo "<html><body>Bonjour Zaz<br /><img src='data:image/png;base64,$img'></body></html>";
}
else
{
	header("WWW-Authenticate: Basic realm=''Espace membres''");
	header('HTTP/1.0 401 Unauthorized');
	echo '<html><body>Cette zone est accessible uniquement aux membres du site</body></html>'."\n";
}

?>
