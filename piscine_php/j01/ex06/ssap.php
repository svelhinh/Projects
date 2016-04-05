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
	$i = 1;
	while ($i != $argc)
	{
		$tab[$i - 1] = ft_split($argv[$i]);
		$i++;
	}
}
else
	echo "\n";

?>
