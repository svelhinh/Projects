<?php

$dir = "../private";
$file = "../private/passwd";

if ($_POST['submit'] == "OK")
{
	if (!file_exists($dir) || !file_exists($file) || !$_POST['oldpw'] || !$_POST['newpw'] || !$_POST['login'])
		echo "ERROR\n";
	else
	{
		$tab = unserialize(file_get_contents($file));
		$j = 0;
		foreach ($tab as $i)
		{
			if ($i['login'] == $_POST['login'] && $i['passwd'] == hash("whirlpool", $_POST['oldpw']))
			{
				$tab[$j]['passwd'] = hash("whirlpool", $_POST['newpw']);
				$str = serialize($tab);
				file_put_contents($file, $str."\n");
				echo "OK\n";
				return ;
			}
			$j++;
		}
		echo "ERROR\n";
	}
}
else
	echo "ERROR\n";

?>
