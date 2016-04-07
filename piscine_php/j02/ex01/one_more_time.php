#!/usr/bin/php
<?php

if ($argc == 2)
{
	$date = explode(" ", $argv[1]);
	$hour = explode(":", $date[4]);
	if ($date[0] == "Lundi" || $date[0] == "lundi" || $date[0] == "Mardi" || $date[0] == "mardi" || $date[0] == "Mercredi" || $date[0] == "mercredi" || $date[0] == "Jeudi" || $date[0] == "jeudi" || $date[0] == "Vendredi" || $date[0] == "vendredi" || $date[0] == "Samedi" || $date[0] == "samedi" || $date[0] == "Dimanche" || $date[0] == "dimanche")
	{
		if ($date[2] == "Janvier" || $date[2] == "janvier")
			$month = 1;
		else if ($date[2] == "Fevrier" || $date[2] == "fevrier")
			$month = 2;
		else if ($date[2] == "Mars" || $date[2] == "mars")
			$month = 3;
		else if ($date[2] == "Avril" || $date[2] == "avril")
			$month = 4;
		else if ($date[2] == "Mai" || $date[2] == "mai")
			$month = 5;
		else if ($date[2] == "Juin" || $date[2] == "juin")
			$month = 6;
		else if ($date[2] == "Juillet" || $date[2] == "juillet")
			$month = 7;
		else if ($date[2] == "Aout" || $date[2] == "aout")
			$month = 8;
		else if ($date[2] == "Septembre" || $date[2] == "septembre")
			$month = 9;
		else if ($date[2] == "Octobre" || $date[2] == "octobre")
			$month = 10;
		else if ($date[2] == "Novembre" || $date[2] == "novembre")
			$month = 11;
		else if ($date[2] == "Decembre" || $date[2] == "decembre")
			$month = 12;
		else
			$month = 0;
		if ($month && count($date) && strlen($date[1]) > 0 && strlen($date[1]) < 3 && strlen($date[3]) == 4 && strlen($hour[0]) == 2 && strlen($hour[1]) == 2 && strlen($hour[2]) == 2 && checkdate($month, $date[1], $date[3]) && $hour[0] >= 0 && $hour[0] <= 23 && $hour[1] >= 0 && $hour[1] <= 59 && $hour[2] >= 0 && $hour[2] <= 59 && $date[3] >= 1970)
		{
			date_default_timezone_set("Europe/Paris");
			echo mktime($hour[0], $hour[1], $hour[2], $month, $date[1], $date[3]);
		}
		else
			echo "Wrong Format";
	}
	else
		echo "Wrong Format";
}
echo "\n";

?>
