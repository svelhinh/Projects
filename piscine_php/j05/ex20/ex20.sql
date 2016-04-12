SELECT genre.id_genre 'id_genre', genre.nom 'nom genre', distrib.id_distrib 'id_distrib',
distrib.nom 'nom distrib', film.titre 'titre film' FROM film
INNER JOIN genre ON film.id_genre = genre.id_genre
INNER JOIN distrib ON film.id_distrib = distrib.id_distrib
WHERE genre.id_genre BETWEEN 4 AND 8;