<!doctype html>
<html>

	<head>
		<meta charset="utf-8">
	</head>

	<body>
		<h1>Détails des comptes</h1>
		<?php
			include("php/accounts.php");
			echo $nom;
			echo " ";
			echo $prenom;
			if ($nom_compte)
			{
				$perf = ($argent - $argent_init)/$argent_init;
				echo '<br />';
				echo '<br />';
				echo 'Nom du compte 1 : ';
				echo $nom_compte;
				echo '<br />';
				echo "Performance : ";
				echo round($perf, 2);
				echo "%";
				if ($nom_compte2)
				{
					$perf2 = ($argent2 - $argent2_init)/$argent2_init;
					echo "<br /><br />";
					echo 'Nom du compte 2 : ';
					echo $nom_compte2;
					echo '<br />';
					echo "Performance : ";
					echo round($perf2, 2);
					echo "%";
				}
				if ($nom_compte3)
				{
					$perf3 = ($argent3 - $argent3_init)/$argent3_init;
					echo "<br /><br />";
					echo 'Nom du compte 3 : ';
					echo $nom_compte3;
					echo '<br />';
					echo "Performance : ";
					echo round($perf3, 2);
					echo "%";
				}
			}
		?>
	</body>

</html>
