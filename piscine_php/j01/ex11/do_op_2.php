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

if ($argc == 2)
{
	$tab = ft_split($argv[1]);
	print_r($tab);
//	echo "$nb\n";
}
else
	echo "Incorrect Parameters\n";

?>
