<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Login</title>
    <link rel="stylesheet" type="text/css" href="css/style.css">
    <script src="js/Chart.js"></script>
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap-theme.min.css" integrity="sha384-fLW2N01lMqjakBkx3l/M9EahuwpSfeNvV63J5ezn3uZzapT0u7EYsXMjQV+0En5r" crossorigin="anonymous">
</head>
<body id="body"> <!-- body will be the .nav-button target -->
<aside class="sidebar">
    <nav id="navigation" role="navigation">
		<?php
			$list_account = "list_account.php?login=" . $_GET['login'];
			echo '<a href=';
			echo $list_account;
			echo '>Liste des comptes</a>';
		?>
        <a href="#">Historique</a>
        <a href="#">Cours de la bourse</a>
    </nav>
</aside>
<!-- /aside -->

<div class="wrapper">
    <a href="#body" class="nav-button-open" aria-label="open navigation"></a>
    <a href="#" class="nav-button-close" aria-label="close navigation"></a>
    <header id="header">
        <h1> Where Is My Money ? </h1>
    </header>

    <div class="main">
        <canvas id="myChart" width="400" height="400" style="cursor:pointer;" onclick="montre('blabla');"></canvas>
	</div>
	<?php
		include("php/accounts.php");
		include("js/graph.php");
	?>
</div>
</body>
</html>
