// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   tp_nb_lettres.js                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/02/22 10:52:47 by svelhinh          #+#    #+#             //
//   Updated: 2016/02/22 16:01:45 by svelhinh         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

function conversion(nb)
{
	var str = '', c = parseInt(nb / 100), d = parseInt(nb / 10 % 10), u = nb % 10;

	if (c == 1)
		str += 'cent ';
	if (c == 2)
		str += 'deux cents ';
	if (c == 3)
		str += 'trois cents ';
	if (c == 4)
		str += 'quatre cents ';
	if (c == 5)
		str += 'cinq cents ';
	if (c == 6)
		str += 'six cents ';
	if (c == 7)
		str += 'sept cents ';
	if (c == 8)
		str += 'huit cents ';
	if (c == 9)
		str += 'neuf cents ';
	if (d == 1)
	{
		if (u == 1)
			str += 'onze';
		else if (u == 2)
			str += 'douze';
		else if (u == 3)
			str += 'treize';
		else if (u == 4)
			str += 'quatorze';
		else if (u == 5)
			str += 'quinze';
		else if (u == 6)
			str += 'seize';
		else
			str += 'dix ';
	}
	if (d == 2)
		str += 'vingt ';
	if (d == 3)
		str += 'trente ';
	if (d == 4)
		str += 'quarante ';
	if (d == 5)
		str += 'cinquante ';
	if (d == 6)
		str += 'soixante ';
	if (d == 7)
		str += 'soixante-dix ';
	if (d == 8)
		str += 'quatre-vingt ';
	if (d == 9)
		str += 'quatre-vingt-dix ';
	if (u == 1 && d != 1)
		str += 'un';
	if (u == 2 && d != 1)
		str += 'deux';
	if (u == 3 && d != 1)
		str += 'trois';
	if (u == 4 && d != 1)
		str += 'quatre';
	if (u == 5 && d != 1)
		str += 'cinq';
	if (u == 6 && d != 1)
		str += 'six';
	if (u == 7)
		str += 'sept';
	if (u == 8)
		str += 'huit';
	if (u == 9)
		str += 'neuf';
	if (nb == 0)
		str = 'zero';
	return (str);
}

var nb = -1

while (nb)
{
	nb = prompt("Entrez un nombre entre 0 et 999 :");
	if (nb >= 0 && nb <= 999 && nb)
		alert(conversion(nb));
}

