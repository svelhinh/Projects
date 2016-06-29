<?PHP

session_start();
$user_list = unserialize(file_get_contents("../data/user"));
?>
<link rel = "stylesheet" type = "text/css" href=".....css">
<?php
$i = 0;
while ($_SESSION['userlist'][$i])
{
?>
<div class="adminuser">
<h4 class = "user-name"><?=$_SESSION['userlist'][$i]['nom']?></h4>
<form method="post">
<input class="user_upgrade" type="submit" name=<?"Upgrade"$_SESSION['userlist'][$i]['login']?> value="UPGRADE"/>
<input class="user_suppress" type="submit" name= <?"SUP"$_SESSION['userlist'][$i]['login']?> value="SUPRESS"/>
</form>
</div>
<?PHP
	$i++;
}
?>
<?PHP
$i = 0;
while ($_SESSION['userlist'][$i])
{
	if ($_POST['Upgrade'$_SESSION['userlist'][$i]["login"]] == "UPGRADE")
	{
		$value = 0;
		foreach($user_list as $user_id)
		{
			if ($_SESSION['userlist'][$i] == $user_id["login"])
			{
				$user_id["admin"] == "admin";
				$_user_list["$value"] = $user_id;
			}
			$value++;
		}
	}
	if ($_POST['SUP'$_SESSION['userlist'][$i]["login"]] == "SUPRESS")
	{
		$value = 0;
		foreach($user_list as $user_id)
		{
			if ($_SESSION['userlist'][$i] == $user_id["login"])
			{
				$user_list[$value] = array();
			}
			$value++;
		}
	}
	$i++;
}
file_put_contents("../data/user", serialize($user_list));
?>
<div class="button">
<h4 class="button-custom"></h4>
<form method="post">
<input class="press it" type="submmit" name="submit" value="ok"/>
</form>
</div>

<?PHP
if ($_POST['submit'] == "ok")
	echo'<META HTTP-EQUIV="Refresh" Content="0"; URL="./adminpage.php"/>';
?>
