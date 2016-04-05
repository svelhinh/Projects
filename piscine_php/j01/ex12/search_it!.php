#!/usr/bin/php
<?php

if ($argc > 2)
{
	$j = 0;
	$tab = array();
	foreach ($argv as $i)
	{
		if ($j > 1)
		{
			$tmp = explode(":", $i);
			$tmp2 = array($tmp[0] => $tmp[1]);
			$tab = array_merge($tab, $tmp2);
		}
		$j++;
	}
	$val = "";
	while ($i = current($tab))
	{
		if ((key($tab) == $argv[1] && !is_int(key($tab))) || (key($tab) == $argv[1] && is_int(key($tab)) && is_numeric($argv[1])))
			$val = $i;
		next($tab);
	}
	echo $val;
}
echo "\n";

?>
