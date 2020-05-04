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

if ($argc == 4)
{
	$j = 0;
	foreach ($argv as $i)
	{
		if ($j != 0)
		{
			$tab2[$j - 1] = ft_split($i);
			$tab[$j - 1] = $tab2[$j - 1][0];
		}
		$j++;
	}
	if ($tab[1] == "+")
		$nb = $tab[0] + $tab[2];
	else if ($tab[1] == "-")
		$nb = $tab[0] - $tab[2];
	else if ($tab[1] == "*")
		$nb = $tab[0] * $tab[2];
	else if ($tab[1] == "/")
		$nb = $tab[0] / $tab[2];
	else if ($tab[1] == "%")
		$nb = $tab[0] % $tab[2];
	echo "$nb\n";
}
else
	echo "Incorrect Parameters\n";

?>
