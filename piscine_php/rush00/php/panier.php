<?php
function check_stock($product)
{
	if (!$_SESSION['panier'])
		return 1;
	if ($_SESSION['to_print'])
	{
		foreach ($_SESSION['to_print'] as $prod)
			if ($prod['nom'] == $product['nom'])
			{
				$max = $prod['quantite'];
				break ;
			}		
	}
	else
	{
		foreach ($_SESSION['selection'] as $prod)
			if ($prod['nom'] == $product['nom'])
			{
				$max = $prod['quantite'];
				break ;
			}	
	}
	$tmp = 0;
	foreach ($_SESSION['panier'] as $prod)
		if ($prod['nom'] == $product['nom'])
		{
			$tmp = 1;
			if ($prod['quantite'] + $product['quantite'] <= $max)
				return 1;
		}
	if ($tmp == 1)
	{
		echo '<script>alert("Stock insuffisant !")</script>';
		return 0;
	}
	else
		return 1;
}
  $product_list = unserialize(file_get_contents('data/product'));
  $i = 0;
  foreach ($_POST as $key2 => $value)
  {
    if ($i == 1)
		$key = $key2;
    $i++;
  }
  foreach ($product_list as $name)
  {
    if ($name['nom'] == $key)
    {
      $product = $name;
      break ;
    }
  }
  $product['quantite'] = $_POST['quantite'];

  if ($_POST['submit'] == "Commander")
  {
  	if (!file_exists("data/user_log"))
		file_put_contents("data/user_log", "");  		
  	if (!file_exists("data/admin_log"))
		file_put_contents("data/admin_log", "");
    $user_logs = unserialize(file_get_contents("data/user_log"));
    $admin_log = unserialize(file_get_contents("data/admin_log"));

  	date_default_timezone_set('Europe/Paris');

	$time = date("[j:m:Y]");
	$login = $_SESSION['login'];
	$produits = array();
  	$total = 0;

  	if ($_SESSION['panier'])
  	{
 	 	foreach ($_SESSION['panier'] as $prod)
		{
			array_push($produits, array("nom" => $prod['nom'], "quantites" => $prod["quantites"]));
			$total += $prod['prix'] * $prod['quantite'];
		} 		
  	}
 
  	if ($user_log[$login] == NULL)
 		$user_log[$login] = [];
 	if (!is_array($admin_log))
 		$admin_log = array();

 	array_push($admin_log, array("time" => $time, "login" => $login, "produits" => $produits, "total" => $total));
	array_push($user_log[$login],  array("time" => $time, "produits" => $produits, "total" => $total));

  	file_put_contents("data/user_log", serialize($user_log));
  	file_put_contents("data/admin_log", serialize($admin_log));

	unset($_SESSION['panier']);
  }


	if ($_POST['submit'] == "Ajouter" && check_stock($product))
	{
		if (!$_SESSION['panier'])
			$_SESSION['panier'] = array($product);
		else
		{
			$i = 0;
			$j = 0;
			foreach ($_SESSION['panier'] as $prod)
			{
				if ($prod['nom'] == $product['nom'])
				{
					$_SESSION['panier'][$j]['quantite'] += $product['quantite'];
					$i = 1;
					break ;
				}
				$j++;
			}
			if ($i == 0)
				array_push($_SESSION['panier'], $product);
		}
	}
	else if ($_POST['submit'] == "Vider" || $_POST['submit'] == "Annuler")
	{
		unset($_SESSION['panier']);
		unset($_SESSION['type']);
		unset($_SESSION['region']);
		unset($_SESSION['degre']);
		unset($_SESSION['prix']);
	}
	if ($_SESSION['panier'] || $_POST['submit'] == "Ajouter")
	{
		echo '<div class="produits">';
		$total = 0;
		$quantite = 0;
		foreach ($_SESSION['panier'] as $products)
		{
			echo '<table>';
			echo '<td class="nom">'.$products["nom"].'</td>';
			echo '<td class="quantite">'.$products["quantite"].'</td>';
			echo '<td class="prix">'.$products["prix"].'&euro;</td>';
			echo '</table>';
			echo '<hr class="line" />';
			$total += $products["prix"] * $products['quantite'];
			$quantite += $products["quantite"];
		}
		echo '<div class="total">TOTAL : </div>';
		echo '<div class="quantite">'.$quantite.'</div>';
		echo '<div class="prix">'.$total.'&euro;</div>';
		echo '<hr class="line" />';
		if ($_SESSION['login'])
		{
			echo '<form action="php/paiement.php" method="post">';
			echo '<input class="valider" type="submit" name="submit" value="Valider" />';
			echo '</form>';
		}
		echo '<form action="index.php" method="post">';
		echo '<input class="corbeille" type="image" name="submit" src="img/corbeille.jpg" value="Vider" />';
		echo '</form>';
		echo '</div>';
	}
	else
		echo '<div class="produits"><p>PANIER VIDE</p></div>';
?>
