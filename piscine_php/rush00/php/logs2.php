
<?php
function get_prod($tab)
{
	$i = 0;
	foreach ($tab as $key => $value)
	{
		$tab[] = $value['nom'];
		$i++;
	}
	while ($i > 0)
	{
		array_shift($tab);
		$i--;
	}
	return (implode(", ", $tab));
}

	session_start();
	$command_log = unserialize(file_get_contents("../data/admin_log"));

foreach ($command_log as $key => $value)
{
  echo $value['time']." <b>".$value['login']."</b> Montant :".$value['total']." Produits :".get_prod($value['produits']).'<br />';
}
?>
