<?php
session_start();
if ($_POST['valider'])
{
    if ( !$_POST['login'] || !$_POST['passwd'] )
        $msg = "Veuillez remplir tous les champs.";
    else
    {
        $data = unserialize(file_get_contents("data/user"));
        foreach ($data as $user)
        {
            $msg = "Utilisateur Introuvable";
            if ($user['login'] == $_POST['login'] && hash('whirlpool', $_POST['passwd']) == $user['passwd'])
            {
                $_SESSION['login'] = $user['login'];
                if ($user['adm'] == "admin")
                    $_SESSION['adm'] = "admin";
                $msg = 'Bienvenue ' . $user['login'];
                break ;
            }
        }
    }
}

if (!$_SESSION["login"])
{
    ?>
        <form id=modif method=POST <?php if ($_SESSION["login"]) echo "style=display:none;";?> >
            Login <br /><input name=login type=text value="<?php echo $_POST["login"]?>"/><br />
            Mot de passe <br /><input name=passwd type=password value="" /><br /><br />
            <center><input type=submit name=valider value=Connexion></center>
            <center><a href=php/sign_up.php>Créer un compte</a></center>
        </form>
        <?php echo $msg?> 
    <?php 
}
else
{?>
    <div>
        <a href="php/mon_compte.php">Mon compte</a><br />
        <?php if ($_SESSION['adm'] == "admin") { ?>  <a href="admin_page.php">Admin</a><br /> <?php } ?> 
        <a href="php/logout.php">Logout</a><br />
    </div>
<?php
}
?>