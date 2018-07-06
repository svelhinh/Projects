/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors.go                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:59:39 by svelhinh          #+#    #+#             */
/*   Updated: 2018/04/11 16:03:49 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

package main

import (
	"fmt"
	"os"
)

const (
	MOVE_ERR    = " move doesn't exist\nF, F', F2, R, R', R2, L, L', L2, B, B', B2, D, D', D2, U, U', U2"
	ARGSYNT_ERR = "Wrong syntax for an argument"
	ARGNB_ERR   = "Wrong number of arguments"
	VBSVB_ERR   = "You can't have both verbose and super verbose"
	GEN_ERR     = "Can't generate cube"
	HELP_ERR    = "-h\t\t->\thelp\n-s [2/3]\t->\tchoose between 2x2 or 3x3 cube (3x3 cube by default)\n-v\t\t->\tverbose, display all steps of cube resolution\n-sv\t\t->\tsuper verbose, like verbose but in slow motion\n-g [number > 0]\t->\tgenerate a cube with [number] movements\n\n"
)

func runError(what string) {
	fmt.Printf("%s\n", what)
	os.Exit(1)
}
