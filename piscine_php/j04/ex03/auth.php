<?php

function auth($login, $passwd)
{

	$dir = "../private";
	$file = "../private/passwd";
	$hpass = hash("whirlpool", $passwd);

	if (file_exists($dir) && file_exists($file))
	{
		$tab = unserialize(file_get_contents($file));
		foreach ($tab as $i)
			if ($i['login'] == $login && $i['passwd'] == $hpass)
				return 1;
	}
	return 0;
}

?>
