#!/usr/bin/php
<?php

function ft_split($str)
{
	$str = explode(" ", $str);
	$tab = array();
	$j = 0;
	foreach ($str as $i)
	{
		if ($i)
		{
			$tab[$j] = $i;
			$j++;
		}
	}
	return $tab;
}

function merge($nb, $alpha, $other)
{
	return array_merge($alpha, array_merge($nb, $other));
}

function tab_split($tab)
{
	$j = 0;
	$k = 0;
	$l = 0;
	foreach ($tab as $i)
	{
		if (is_numeric($i[0]))
		{
			$nb[$j] = $i;
			$j++;
		}
		else if (ctype_alpha($i[0]))
		{
			$alpha[$k] = $i;
			$k++;
		}
		else
		{
			$other[$l] = $i;
			$l++;
		}
	}
	$tab = merge($nb, $alpha, $other);
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
	sort($tab2, SORT_STRING | SORT_FLAG_CASE);
	$tab2 = tab_split($tab2);
	foreach ($tab2 as $j)
		echo "$j\n";
}
else
	echo "\n";

?>
