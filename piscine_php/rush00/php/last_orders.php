<?php

	session_start();
	$command_log = unserialize(file_get_contents("../data/user_log"));


	if (!count($command_log[$_SESSION["login"]]))
		echo "<div>Aucune commande effectuée</div>";
	else
		echo "<table><tr><td>Date</td><td>Produits commandes</td><td>Prix</td></tr>";
		foreach ($command_log[$_SESSION["login"]] as $value) {
			echo "<tr><td>" . $value["time"] . "</td>";
			echo "<td>" ;
			echo "<ul>";
			foreach ($value["produits"] as $prods) {
				echo "<li>" . $prods["quantities"] . " " . $prods["nom"]. "</li>";
			}
			echo "</ul>";
			echo "</td>";
			echo "<td>" . $value["total"] . "</td></tr>";
		}
?>
