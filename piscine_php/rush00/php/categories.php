<?php

	$cat_method 	= "POST";
	$cat_target 	= "index.php";

	// "Category" Array pattern:

	// Array
	// (
	// 	[0] => (
	// 		[user_tag] 	= "Client-side tag"
	// 		[admin_tag]	= "Server-side tag - DO NOT DISPLAY IT ON CLIENT SIDE"
	// 	)
	// 	...
	// )

	// function make_rolling_list( $array, $name )
	// Take an array and return a string containing html formatted code :
	// <option name=$name size=1> 
	function make_category_array( $array )
	{
		$data = [];
		foreach ($array as $value)
			array_push($data, array("user_tag" => $value, "admin_tag" => strtolower($value)));
		return $data;
	}

	function make_rolling_list( $array, $name )
	{
		$str .= "<select class=list name=" . $name ." size=1>";
		$str .= "<option value=\"\">";		
		foreach ($array as $key => $value)
		{
			$str .= "<option value=" . $value["admin_tag"];
			$str .= ">". $value["user_tag"];			
		}


		$str .= "</select>";
		return $str;
	}

	$type	= make_category_array(["Blanc", "Champagne", "Rouge", "Rose"]);
	$region	= make_category_array([ "Bordeaux", "Rhone", "Bourgogne", "Champagne", "Alsace", "Lorraine", "Armagnac", "Cognac", "Languedoc", "Roussillon", "Provence", "Corse" ]);
	$degre	= make_category_array(["1", "2", "3", "4", "5"]);
	$prix = make_category_array(["1", "2", "3", "4", "5"]);



	$str = "<form method=". $cat_method ." action=" . $cat_target .">";
	$str .= "<span>Type</span> <br />";
	$str .= make_rolling_list( $type, "type");
	$str .= "<br /><span>Region</span> <br />";
	$str .= make_rolling_list( $region, "region");
	$str .= "<br /><span>Degré</span> <br />";
	$str .= make_rolling_list( $degre, "degre");
	$str .= "<br /><span>Prix</span> <br />";
	$str .= make_rolling_list( $prix, "prix");
	$str .= "<br /><button type=submit name=submit value=\"cat\">Filtrer</button></form>";

	echo $str;
?>
