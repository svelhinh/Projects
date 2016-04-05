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

if ($argc == 2)
{
	$tab = ft_split($argv[1]);
	$j = 0;
	foreach ($tab as $i)
	{
		echo "$i";
		if ($j < $argc)
			echo " ";
		else
			echo "\n";
		$j++;
	}
}
else
	echo "\n";

?>
