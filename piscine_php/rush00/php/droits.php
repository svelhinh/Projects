<?PHP

session_start();
$user_list = unserialize(file_get_contents("../data/user"));
$_SESSION['userlist'] = $user_list;
include('droits2.php');
?>
