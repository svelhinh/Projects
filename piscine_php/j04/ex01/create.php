<?php

$dir = "../private";
$file = "../private/passwd";

function check($file)
{
	$tab = unserialize(file_get_contents($file));
	if ($tab)
	{
		foreach ($tab as $i)
		{
			if ($i['login'] == $_POST['login'])
				return 0;
		}
	}
	return 1;
}

function add($tab)
{
	$i = 0;
	while ($tab[$i])
		$i++;
	return $i;
}

if ($_POST['submit'] == "OK")
{
	if (!file_exists($dir))
		mkdir($dir);
	if (!file_exists($file))
		file_put_contents($file, "");
	if (check($file) && $_POST['login'] && $_POST['passwd'])
	{
		$tab = unserialize(file_get_contents($file));
		$i = add($tab);
		$tab[$i]['login'] = $_POST['login'];
		$tab[$i]['passwd'] = hash("whirlpool", $_POST['passwd']);
		$str = serialize($tab);
		file_put_contents($file, $str."\n");
		echo "OK\n";
	}
	else
		echo "ERROR\n";
}
else
	echo "ERROR\n";

?>
