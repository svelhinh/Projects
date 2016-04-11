<?php
    session_start();
    $path = "../data/user";
    if (!$_SESSION['login'])
        echo "Vous n'êtes pas connecté.";
    else
    {
        $data = unserialize(file_get_contents($path));
        foreach ($data as $user)
            if ($user['login'] == $_SESSION['login']) { $modif = $user; break ; }
        if (!$modif)
            echo "Utilisateur introuvable";
        else
        {
            if ($_POST['annuler']) { header('Location: ./modif_compte.php'); exit(); }
            if ($_POST['supprimer'])
            {
		        $data = unserialize(file_get_contents($path));
		        foreach ($data as $id => $user)
		            if ($user['login'] == $_SESSION['login']) { unset($data[$id]); break ; }
		        file_put_contents($path, serialize($data));
		        $_SESSION['login'] = NULL;
		        header('Location: ../index.php');
		        exit();
            }
?>
<form id="delete" action="delete_account.php" method="POST">

	<center><p>Vous êtes sur le point de supprimer le compte <?$login?></p></center>
	<center><p>Cette action est irréversible</p></center>

	<center><input type="submit" name="annuler" value="ANULER">&nbsp;&nbsp;&nbsp;<input type="submit" name="supprimer" value="SUPPRIMER"></center>
        <br />
        <br />
    <?php echo $msg; ?>
</form>
<?php
        }
    }
?>







