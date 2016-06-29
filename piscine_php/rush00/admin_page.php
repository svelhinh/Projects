<?php
function check_admin($login, $paswd)
{
  $db = unserialize(file_get_contents("./data/user"));
  foreach ($db as $user)
   if($user['acces'] == "OK")
    return(TRUE);
  return(FALSE);
}

session_start();
echo '<link rel="stylesheet" type="text/css" href="css/admin_page.css">';
//if (check_admin($_SESSION['login'], $_SESSION['password']))
//{
?>
<div id="all">
<div id="frame"><a href="./php/logs.php"><h4>Historique des commandes</h4></a></div>
<div id="modif_account"><a href="./php/droits.php"><h4>Modifier les comptes</h4></a></div>
<div id="modif_prod"><a href='./php/admprod.php'><h4>Modifier produit</h4></a></div>
<!-- <div id="modif_categorie"><a href="./php/modifcategorie.php"><h4>Modifier un categorie</h4></a></div> -->
<div id="modif_acceuil"><a href="./index.php"><h4>Retour sur le site</h4></a></div>
<?php
//}
// else
// echo "<META HTTP-EQUIV='Refresh' Content='0; URL=/rush00/index.php'/>";
?>
</div>
