#!/usr/bin/php
<?php

function ft_split($str)
{
	$str = explode(" ", $str);
	$str2 = array();
	$j = 0;
	foreach ($str as $i)
	{
		if ($i != NULL)
		{
			$str2[$j] = $i;
			$j++;
		}
	}
	return $str2;
}

if ($argc >= 2)
{
	$tab = ft_split($argv[1]);
	$first = array_shift($tab);
	array_push($tab, $first);
	$j = 0;
	foreach ($tab as $i)
	{
		echo $i;
		if ($j < count($tab) - 1)
			echo " ";
		else
			echo "\n";
		$j++;
	}
}
else
	echo "\n";

?>
