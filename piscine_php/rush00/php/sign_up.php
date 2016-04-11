<?php

function find_log($login)
{
    $data = seri_depack("../data/user");
       foreach ($data as $tab)
       {
            foreach($tab as $user)
            {
                if ($user == $_POST['login'])
                    return (TRUE);
            }
       }
    return (FALSE);
}
function seri_depack($path)
{
    $data = unserialize(file_get_contents($path));
    return ($data);
}
function seri_pack($data, $path)
{
    file_put_contents("../data/user", serialize($data));
}

if ((!$_POST['login'] || !$_POST['passwd'] || !$_POST['nom'] || !$_POST['prenom'] || !$_POST['mail'] || !$_POST['adresse']) && $_POST['valider'])
    $msg = "Un ou plusieurs champs n'ont pas été remplis<br />Veuillez remplir tous les champs svp";
else
{
    if ($_POST['valider'] == "VALIDER" && find_log($_POST['login']))
        $msg = "deja la";
    else if ($_POST['valider'] == "VALIDER")
    {
        $nom = $_POST['nom'];
        $prenom = $_POST['prenom'];
        $user = $_POST['login'];
        $mdp = hash('whirlpool', $_POST['passwd']);
        $mail= $_POST['mail'];
        $adrs = $_POST['adresse'];
        $tab = array('nom' => $nom, 'prenom' => $prenom,'login' => $user, 'passwd' => $mdp,'mel' => $mail,'adresse' => $adrs);
        $path = "../data/user";
        if (file_exists($path))
            $data = seri_depack($path);
        $data[] = $tab;
        seri_pack($data, $path);
        $msg = "Redirection en cours veuillez patienter";
        echo '<meta http-equiv="refresh" content="1; URL=../index.php">';
    }
}
?>
    <form id="signup" action="sign_up.php" method="POST">

        Nom : <input size="16" name="nom" type="text" value="<?php echo $_POST['nom'] ?>"/><br />
        Prénom : <input size="16" name="prenom" type="text" value="<?php echo $_POST['prenom'] ?>"/><br />
        Login : <input size="16" name="login" type="text" value="<?php echo $_POST['login'] ?>"/><br />    
        Mot de passe : <input size="16" name="passwd" type="password" value=""/><br />
        E-mail : <input size="16" name="mail" type="text" value="<?php echo $_POST['mail'] ?>"/><br />
        Adresse : <input size="16" name="adresse" type="text" value="<?=$_POST['adresse']?>"/><br />
       <input type="submit" id="valider" name="valider" value="VALIDER"><br />
        <?php echo $msg; ?>
    </form>