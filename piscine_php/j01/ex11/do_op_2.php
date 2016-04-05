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

function check_errors($str)
{
	$i = 0;
	while ($i < strlen($str))
	{
		if (!is_numeric($str[$i]) && $str[$i] != "+" && $str[$i] != "-" && $str[$i] != "*" && $str[$i] != "/" && $str[$i] != "%" && $str[$i] != " ")
			return 1;
		$i++;
	}
	return 0;
}

function many_op($str)
{
	if (count($str) != 2)
		return 1;
	return 0;
}

if ($argc == 2)
{
	$str = $argv[1];
	if (!check_errors($str))
	{
		if (strchr($str, "+"))
		{
			$op = 0;
			$str = explode("+", $str);
		}
		else if (strchr($str, "-"))
		{
			$op = 1;
			$str = explode("-", $str);
		}
		else if (strchr($str, "*"))
		{
			$op = 2;
			$str = explode("*", $str);
		}
		else if (strchr($str, "/"))
		{
			$op = 3;
			$str = explode("/", $str);
		}
		else if (strchr($str, "%"))
		{
			$op = 4;
			$str = explode("%", $str);
		}
		$nb = ft_split($str[0]);
		$nb2 = ft_split($str[1]);
		if ($nb && $nb2)
		{
			if ($op == 0)
				$nb3 = $nb[0] + $nb2[0];
			if ($op == 1)
				$nb3 = $nb[0] - $nb2[0];
			if ($op == 2)
				$nb3 = $nb[0] * $nb2[0];
			if ($op == 3)
				$nb3 = $nb[0] / $nb2[0];
			if ($op == 4)
				$nb3 = $nb[0] % $nb2[0];
			echo "$nb3\n";
		}
		else
			echo "Syntax Error\n";
	}
	else
		echo "Syntax Error\n";
}
else
	echo "Incorrect Parameters\n";

?>
