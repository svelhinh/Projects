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

?>
