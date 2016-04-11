SELECT UPPER(fiche_personne.nom) AS 'NOM', fiche_personne.prenom, abonnement.prix
FROM fiche_personne INNER JOIN membre INNER JOIN abonnement
WHERE fiche_personne.id_perso = membre.id_fiche_perso AND membre.id_abo = abonnement.id_abo
AND  abonnement.prix > 42 ORDER BY fiche_personne.prenom;