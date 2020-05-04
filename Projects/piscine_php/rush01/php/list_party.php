<?php
try
{
    $bdd = new PDO('mysql:host=localhost;dbname=rush01', 'root', 'root');
}
catch (Exception $e)
{
    die('Erreur : ' . $e->getMessage());
}
$requete = $bdd->query("SELECT * FROM `games_in_progress` WHERE groupe = 'waiting';");
while($donnees = $requete->fetch())
{
    $i = 0;
    foreach ($donnees as $val)
        if (!isset($val))
            $i++;
    $i = 4 - ($i / 2);
    echo "<p>Game " . $donnees['id_game'] . ": Player " . $i . "/4 <a href='start_game.php?id=" . $donnees['id_game'] . "'>Join !</a></p>";
}
$requete->closeCursor();
?>