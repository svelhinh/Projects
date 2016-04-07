#!/usr/bin/php
<?php

while (1)
{
	echo "Entrez un nombre: ";

	if (fscanf(STDIN, "%s", $nb) == NULL)
	{
		echo "^D\n";
		break ;
	}
	if (!is_numeric($nb))
		echo "$nb n'est pas un chiffre\n";
	else
	{
		if ($nb % 2 == 0)
			echo "Le chiffre $nb est Pair\n";
		else if ($nb % 2 != 0)
			echo "Le chiffre $nb est Impair\n";
	}
}

?>
