<?php
function get_log($login, $logs)
{
    foreach ($logs as $key)
    {
      if ($key["nom"] == $login)
        $str = $str.", ".$key['produits'];
    }
    return($str);
}
    session_start();
    $path = "../data/user";
    if (!$_SESSION['login'])
        echo "Veuillez d'abord vous connecter.";
    else
    {
        $data = unserialize(file_get_contents($path));
        foreach ($data as $user)
            if ($user['login'] == $_SESSION['login']) { $modif = $user; break ; }
        if (!$modif)
            echo "Utilisateur introuvable";
        else
        {
            if ($_POST['valider'])
            {
                $doit = 0;
                if (!$_POST['mail'] || !$_POST['adresse'])
                    $msg = "Veuillez renseigner votre e-mail ainsi que votre adresse.";
                else
                {
                    if ($_POST['oldpw'])
                    {
                        if (hash('whirlpool', $_POST['oldpw']) != $modif['passwd'])
                                $msg = "L'ancien mot de pass ne correspond pas";
                        else if (!$_POST['newpw'] || !$_POST['confpw'])
                            $msg = "Pour changer votre mot de pass Veuillez remplir tous les champs concerné";
                        else if ($_POST['newpw'] != $_POST['confpw'])
                            $msg = "Le nouveau mot de passe et la confirmation ne corresponde pas";
                        else
                            $doit = 1;
                    }
                    else
                        $doit = 1;
                    if ($doit)
                    {
                        $msg = "Modification enregistré";
                        $modif['mel'] = $_POST['mail'];
                        $modif['adresse'] = $_POST['adresse'];
                        if ($_POST['oldpw'])
                            $modif['passwd'] = hash('whirlpool', $_POST['newpw']);
                        $data = unserialize(file_get_contents($path));
                        foreach ($data as $id => $user)
                            if ($user['login'] == $_SESSION['login']) { $data[$id] = $modif; break ; }
                        file_put_contents($path, serialize($data));
                    }
                }
            }
?>
 <form id="signup" action="mon_compte.php" method="POST">

    Login : <input name="login" type="text" disabled="disabled" value="<?=$modif['login']?>"/><br />
    Ancien mot de passe : <input id="oldpw" size="16" name="oldpw" type="password" value=""/><br />
    Nouveau mot de passe : <input id="newpw" size="16" name="newpw" type="password" value=""/><br />
    Confirmer le mot de passe : <input id="confpw" size="16" name="confpw" type="password" value=""/><br />
    E-mail : <input name="mail" type="text" value="<?=$modif['mel']?>" size="32" /><br />
    Adresse : <input name="adresse" type="text" value="<?=$modif['adresse']?>" size="32" /><br />
    <a href="delete_account.php">Supprimer le compte</a><br />
    <a href="../index.php"> Revenir a la page d'accueil</a>
    <br />
    <br />
    <input type="submit" id="valider" name="valider" value="VALIDER">

    <?php echo $msg; ?>
</form>
<div><strong>DERNIERES COMMANDES</strong></div>
<?php
        }
    }
 include("last_orders.php");
?>
