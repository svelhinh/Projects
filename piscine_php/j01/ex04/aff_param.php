#!/usr/bin/php
<?php

$j = 0;
foreach ($argv as $i)
{
	if ($j != 0)
	echo "$i\n";
	$j++;
}

?>
