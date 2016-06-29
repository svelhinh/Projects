<link rel="stylesheet" type="text/css" href="../css/style.css" />
<?php
try
{
    $bdd = new PDO('mysql:host=localhost;dbname=rush01', 'root', 'root');
}
catch (Exception $e)
{
    die('Erreur : ' . $e->getMessage());
}
if(!empty($_GET['id']))
{
    $id = (int) $_GET['id'];

    $requete = $bdd->prepare('SELECT chat.date, user.login, chat.message, chat.id FROM chat INNER JOIN user ON chat.id_user = user.id WHERE chat.id > ? ORDER BY chat.id;');
    $requete->execute( array($id) );
    $messages = null;

    while($donnees = $requete->fetch())
    {
        $messages .= "<p id=\"" . $donnees['id'] . "\"><span class='date'>" . "[" . $donnees['date'] . "] " . $donnees['login'] . ": </span><span class='mess left'>" . $donnees['message'] . "</span><br /><br /></p>";
    }
    echo $messages;
}

?>