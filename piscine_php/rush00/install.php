<?PHP
header('Location: index.php');

function	first_user()
{
	$first = array ("login" => "admin", "passwd" => hash('whirlpool', "admin"), "nom" => "Du Guesclin", "prenom" => "Bertrand", "mel" => "Doguenoir@broceliande.fr", "adresse" => "1, rue Even, 22100 Dinan", "adm" => "admin", "commande" => "non");
	$array = array ("0" => $first);
	return ($array);
}

function	set_products()
{
	$bailli = array("nom" => "Bailli", "tags" => "blanc, bordeaux, vitrine", "image" => 'img/vins/blanc/blanc-bordeaux-bailli.jpg', "description" => "Closerie du Bailli 2014, un Cotes de Bourg", "prix" => "8", "quantite" => "20");
	$nadeau = array("nom" => "Nadeau", "tags" => "blanc, bordeaux", "image" => 'img/vins/blanc/blanc-bordeaux-nadeau.jpg',  "description" =>"Vin d'Entre-deux-Mers",  "prix" => "7", "quantite" => "20");
	$navarro = array("nom" => "Navarro", "tags" => "blanc, bordeaux", "image" => 'img/vins/blanc/blanc-bordeaux-navarro.jpg',  "description" => "Vin de Graves AOC",  "prix" => "10", "quantite" => "20");
	$chablis = array("nom" => "Chablis", "tags" => "blanc, bourgogne", "image" => 'img/vins/blanc/blanc-bourgogne-chablis.png',  "description" => "Chablis 2014",  "prix" => "13", "quantite" => "20");
	$chardonnay = array("nom" => "Chardonnay", "tags" => "blanc, bourgogne, vitrine", "image" => 'img/vins/blanc/blanc-bourgogne-chardonnay.jpg',  "description" => "Chablis premier cru vosgros 2013",  "prix" => 20, "quantite" => 20);
	$petitchably = array("nom" => "Petit_chablis", "tags" => "blanc, bourgogne", "image" => 'img/vins/blanc/blanc-bourgogne-petitchablis.jpg',  "description" => "Pas si petit. 2014, Petit Chablis AOC",  "prix" => "11", "quantite" => "20");
	$ardeche = array("nom" => "Ardeche", "tags" => "blanc, rhone", "image" =>'img/vins/blanc/blanc-rhone-ardeche.png',  "description" => "Louis Latour 2013, Grand Ardeche",  "prix" => "10", "quantite" => "20");
	$fondcroze = array("nom" => "Fond_croze", "tags" => "blanc, rhone", "image" => 'img/vins/blanc/blanc-rhone-fondcroze.jpg',  "description" => "Cuvee Confidence 2014",  "prix" => "9", "quantite" => "20");
	$suzienne = array("nom" => "Suzienne", "tags" => "blanc, rhone", "image" => 'img/vins/blanc/blanc-rhone-suzienne.jpg',  "description" => "Le Lutin Blanc 2015, Grignan les Adhemar AOP",  "prix" => "5", "quantite" => "20");
	$clarendelle = array("nom" => "Clarendelle", "tags" => "rose, bordeaux, vitrine", "image" => 'img/vins/rose/rose-bordeaux-clarendelle.jpg',  "description" => "Clarendelle rose 2015, vinifie par l'equipe du chateau Haut-Brion",  "prix" => "10", "quantite" => "20");
	$lamothe = array("nom" => "Lamothe", "tags" => "rose, bordeaux", "image" => 'img/vins/rose/rose-bordeaux-lamothe.jpg',  "description" => "Chateau Lamothe-Vincent, rose 2015",  "prix" => "5", "quantite" => "20");
	$winenote = array("nom" => "Wine_note", "tags" => "rose, bordeaux", "image" => 'img/vins/rose/rose-bordeaux-winenote.jpg',  "description" => "Bordeaux rose, assemblage de Merlot et de Cabernet Franc",  "prix" => "5", "quantite" => "20");
	$mip = array("nom" => "Mip", "tags" => "rose, provence", "image" => 'img/vins/rose/rose-provence-MIP.png',  "description" => "MIP Classic 2015, domaine de sainte Lucie, rose tendance",  "prix" => "10", "quantite" => "20");
	$diables = array("nom" => "Diables", "tags" => "rose, provence, vitrine", "image" => 'img/vins/rose/rose-provence-diables.jpg',  "description" => "Les petits diables 2015, Domaine des diables, Cotes de Provence AOC",  "prix" => "8", "quantite" => "20");
	$enfants = array("nom" => "Enfants", "tags" => "rose, provence", "image" => 'img/vins/rose/rose-provence-enfants.png',  "description" => "Les enfants terribles rose 2015",  "prix" => "8", "quantite" => "20");
	$suzienner = array("nom" => "Suzienne_Rose", "tags" => "rose, rhone", "image" => 'img/vins/rose/rose-rhone-suzienne.jpg',  "description" => "Le lutin rose 2015, la Suzienne",  "prix" => "5", "quantite" => "20");
	$ventou = array("nom" => "Ventou", "tags" => "rose, rhone", "image" => 'img/vins/rose/rose-rhone-ventou.jpg',  "description" => "Grange des dames, rose 2015, vignerons du mont Ventoux",  "prix" => "6", "quantite" => "20");
	$vieilleferme = array("nom" => "Vieilleferme", "tags" => "rose, rhone", "image" => 'img/vins/rose/rose-rhone-vielleferme.jpg',  "description" => "La vieille ferme rose 2015, un incontournable des aperos",  "prix" => "6", "quantite" => "20");
	$manoir = array("nom" => "Manoir", "tags" => "rouge, bordeaux", "image" => 'img/vins/rouge/rouge-bordeaux-manoir.png',  "description" => "Chateau vieux manoir 2012. Vieux manoir, nouvelles sensations",  "prix" => "7", "quantite" => "20");
	$nadeaur = array("nom" => "Nadeau_Rouge", "tags" => "rouge, bordeaux", "image" => 'img/vins/rouge/rouge-bordeaux-nadeau.jpg',  "description" => "Chateau Haut Nadeau 2012, Le plaisir a l'aveugle",  "prix" => "13", "quantite" => "20");
	$pougnan = array("nom" => "Pougnan", "tags" => "rouge, bordeaux, vitrine", "image" => 'img/vins/rouge/rouge-bordeaux-pougnan.png', "description" => "Chateau Haut Pougnan 2013, Il y a tres peu de legerte chez l'Homme. Ce vin y remedie", "prix" => "8", "quantite" => "20");
	$belair = array("nom" => "Belair", "tags" => "rouge, bourgogne", "image" => 'img/vins/rouge/rouge-borgougne-belair.jpg',  "description" => "Coteaux bourguignons grande QV 2014, vignerons de Bel Air. La seduction du plat au dessert",  "prix" => "7", "quantite" => "20");
	$gruber = array("nom" => "Gruber", "tags" => "rouge, bourgogne, vitrine", "image" => 'img/vins/rouge/rouge-bourgogne-gruber.jpg',  "description" => "Hautes Cotes de Nuits 2014, Pierre Gruber. Compagnon des nuits de fortune et d'infortune.",  "prix" => "15", "quantite" => "20");
	$mercurey = array("nom" => "Mercurey", "tags" => "rouge, bourgogne", "image" => "img/vins/rouge/rouge-bourgogne-mercurey.jpg",  "description" => "Mercurey 2013, Domaine de la grangerie. Du corps, de la distinction et de la finesse. Nous ne parlons pas de la chatelaine",  "prix" => "18", "quantite" => "20");
	$saints = array("nom" => "3saints", "tags" => "rouge, rhone, vitrine", "image" => 'img/vins/rouge/rouge-rhone-3saints.png',  "description" => "Cotes du Rhone 2012, 3 saints. Le rouge prime a orange.",  "prix" => "6", "quantite" => "20");
	$guigal = array("nom" => "Guigal", "tags" => "rouge, rhone", "image" => 'img/vins/rouge/rouge-rhone-guigal.jpg',  "description" => "Cotes du Rhone 2012. E.Guigal. Une promenade sur la guarrigue. Certains aiment.",  "prix" => "7", "quantite" => "20");
	$paradox = array("nom" => "Paradox", "tags" => "rouge, rhone", "image" => 'img/vins/rouge/route-rhone-paradox.png',  "description" => "Cotes du Rhone 2012, Rhone Paradox. A Carafer. Un coucher de Soleil sur la table", "prix" => "8", "quantite" => "20");

	$array = array("0" => $bailli, "1" => $nadeau, "2" => $navarro, "3" => $chablis, "4" => $chardonnay, "5" => $petitchably, "6" => $ardeche, "7" => $fondcroze, "8" => $suzienne, "9" => $clarendelle, "10" => $lamothe, "11" => $winenote, "12" => $mip, "13" => $diables, "14" => $enfants, "15" => $suzienner, "16" => $ventou, "17" => $vieilleferme, "18" => $manoir, "19" => $nadeaur, "20" => $pougnan, "21" => $belair, "22" => $gruber, "23" => $mercurey, "24" => $saints, "25" => $guigal, "26" => $paradox);
	return ($array);
}

if (!file_exists("./data"))
	mkdir("./data");
$product = set_products();
file_put_contents("./data/product", serialize($product));
$user = first_user();
file_put_contents("./data/user", serialize($user));
file_put_contents("./data/log", serialize($log));

?>
