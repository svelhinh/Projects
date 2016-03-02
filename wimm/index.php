<!Doctype html>
<html>

	<head>
		<title>Home</title>
		<meta charset="utf-8">
	</head>

	<body>
		<form method="get" name="auth">
			<input type="text" name="login"><br /><br />
			<input type="submit" value="login">
		</form>
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
			if (!empty($login))
			{
				$reponse = $bdd->query("SELECT Nom FROM clientsTableDetailed WHERE Nom='$login'");
				$data = $reponse->fetch();
				if (!empty($data))
					header("Location: home.php?login=$login");
			}
		?>
	</body>

</html>
