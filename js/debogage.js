// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   debogage.js                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/02/21 17:22:23 by svelhinh          #+#    #+#             //
//   Updated: 2016/02/22 10:07:24 by svelhinh         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

// La fonction « a » affiche la valeur qu'elle reçoit de « b ».
function a(value) {
    console.log(value);
}

// La fonction « b » incrémente la valeur reçue par « c » puis la passe en paramètre à « a ».
function b(value) {
    a(value + 1);
}

// La fonction « c » incrémente la valeur reçue par la boucle for puis la passe en paramètre à « b ».
function c(value) {
    b(value + 1);
}

// Pour chaque itération, cette boucle passe en paramètre la valeur de « i » à la fonction « c ».
for (var i = 0; i < 10; i++) {
    c(i);
}
