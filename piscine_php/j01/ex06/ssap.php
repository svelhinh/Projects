#!/usr/bin/php
<?php

function ft_split($str)
{
	$str = explode(" ", $str);
	$tab = array();
	$j = 0;
	foreach ($str as $i)
	{
		if ($i != NULL)
		{
			$tab[$j] = $i;
			$j++;
		}
	}
	return $tab;
}

if ($argc >= 2)
{
	$l = 1;
	while ($l != $argc)
	{
		$tab[$l - 1] = ft_split($argv[$l]);
		$l++;
	}
	$l = 0;
	foreach ($tab as $i)
	{
		foreach ($i as $j)
		{
			$tab2[$l] = $j;
			$l++;
		}
	}
	sort($tab2, SORT_STRING);
	foreach ($tab2 as $j)
		echo "$j\n";
}
else
	echo "\n";

?>
