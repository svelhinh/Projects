<?php
	$login = $_GET['login'];
	try
	{
		$bdd = new PDO('mysql:host=mysql.hostinger.fr;dbname=u725261233_test;charset=utf8', 'u725261233_ssd', 'sergiosamueldouglas');
	}
	catch (Exception $e)
	{
		die('Erreur : ' . $e->getMessage());
	}
	$reponse = $bdd->query("SELECT * FROM clientsTableDetailed WHERE Nom='$login'");
	while ($data = $reponse->fetch())
		$tab[] = $data;
	$argent = round($tab[0]['Compte1_MontantActuel'], 2);
	$argent2 = round($tab[0]['Compte2_MontantActuel'], 2);
	$argent3 = round($tab[0]['Compte3_MontantActuel'], 2);
	$argent_init = str_replace(' ', '', $tab[0]['Compte1_MontantInitial']);
	$argent2_init = str_replace(' ', '', $tab[0]['Compte2_MontantInitial']);
	$argent3_init = str_replace(' ', '', $tab[0]['Compte3_MontantInitial']);
	$nom = $tab[0]['Nom'];
	$prenom = $tab[0]['Prénom'];
	$nom_compte = $tab[0]['Compte1_ID'];
	$nom_compte2 = $tab[0]['Compte2_ID'];
	$nom_compte3 = $tab[0]['Compte3_ID'];
	$type_compte = $tab[0]['Compte1_Type'];
	$type_compte2 = $tab[0]['Compte2_Type'];
	$type_compte3 = $tab[0]['Compte3_Type'];
?>
