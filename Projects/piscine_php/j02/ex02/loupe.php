#!/usr/bin/php
<?php

function title($tab)
{
	return $tab[1].strtoupper($tab[2]);
}

function other($tab)
{
	return $tab[1].strtoupper($tab[2]);
}

function upper($tab)
{
	$str = preg_replace_callback('/(title[^=]*=[^"]*")([^"]*)/s', "title", $tab[0]);
	$str = preg_replace_callback('/(>)([^<]*)/s', "other", $str);
	return ($str);
}

$fd = fopen($argv[1], "r");
$i = 0;
while (!feof($fd))
{
	$tab[$i] = fgets($fd);
	$i++;
}
fclose($fd);
$str = implode("", $tab);
$str = preg_replace_callback("/<\s*a.*?<\/a[^>]*>/s", "upper", $str);
echo $str;

?>
