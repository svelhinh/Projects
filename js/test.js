// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   test.js                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/02/21 17:22:33 by svelhinh          #+#    #+#             //
//   Updated: 2016/02/21 17:22:36 by svelhinh         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

var nicks = [], nick;

while (nick = prompt('Entrez un prenom :'))
	nicks.push(nick); // Ajoute le nouveau prénom ainsi qu'une espace juste après

nicks.length > 0 ? alert(nicks.join(' ')) : alert("Aucun prenom n'a ete saisi");
