<?php
session_start();
try
{
    $bdd = new PDO('mysql:host=localhost;dbname=rush01', 'root', 'root');
}
catch (Exception $e)
{
    die('Erreur : ' . $e->getMessage());
}
if(!empty($_POST['message']))
{ // si les variables ne sont pas vides

    // $pseudo = mysql_real_escape_string($_POST['pseudo']);
    $message = htmlentities($_POST['message']); // on sécurise nos données
    // puis on entre les données en base de données :
    $date = date("Y-m-d H:i:s");
    $insertion = $bdd->prepare('INSERT INTO chat(message, date, id_user) VALUES(?, ?, ?);');
    $insertion->execute(array(
        $message,
        $date,
        $_SESSION['id']
    ));
}
?>
