<?php

function decroissant($tab, $tab2)
{
	$j = 0;
	$nb = 1;
	foreach ($tab2 as $i)
	{
		if ($i != $tab[$j])
		{
			$nb = 0;
			break ;
		}
		$j++;
	}
	return $nb;
}

function croissant($tab, $tab2)
{
	$j = 0;
	$nb = 1;
	foreach ($tab2 as $i)
	{
		if ($i != $tab[$j])
		{
			$nb = 0;
			break ;
		}
		$j++;
	}
	return $nb;
}

function ft_is_sort($tab)
{
	$nb = 1;
	$nb1 = 1;
	$tab2 = $tab;
	sort($tab2);
	$nb = croissant($tab, $tab2);
	rsort($tab2);
	$nb1 = decroissant($tab, $tab2);
	return $nb == 0 && $nb1 == 0 ? 0 : 1;
}

?>
