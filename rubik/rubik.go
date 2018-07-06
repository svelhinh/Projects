/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rubik.go                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:59:25 by svelhinh          #+#    #+#             */
/*   Updated: 2018/04/18 20:30:25 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

package main

import (
	"flag"
	"fmt"
	"log"
	"math/rand"
	"os"
	"runtime/pprof"
	"strconv"
	"time"
)

var moveNamesList = []string{
	"U", "U'", "L", "L'",
	"R", "R'", "D", "D'",
	"B", "B'", "F", "F'",
}

var verbose = false
var superVerbose = false

var generateDb = false
var databaseCorners [][]Cubie
var databaseScoresCorners []byte
var databaseHalf [][]Cubie
var databaseScoresHalf []byte
var databaseRest [][]Cubie
var databaseScoresRest []byte

// func resolve2x2Cube(cube *Cube2x2) {
// 	if verbose || superVerbose {
// 		fmt.Println("GOAL :\n")
// 		cube.printCube2x2(cube.goal, false, true)
// 		fmt.Println("\n\nCUBE :\n")
// 		cube.printCube2x2(cube.cube, false, true)
// 		fmt.Println()
// 	}

// 	path, nbMoves := cube.solve()
// 	if verbose || superVerbose {
// 		if superVerbose {
// 			for j := 0; j < 5000000000; j++ {

// 			}
// 			print("\033[H\033[2J")
// 		}
// 		for i := len(path) - 1; i >= 0; i-- {
// 			if superVerbose {
// 				print("\033[H\033[2J")
// 			}
// 			cube.printCube2x2(path[i], true, true)
// 			if superVerbose {
// 				for j := 0; j < 5000000000; j++ {

// 				}
// 			}
// 			fmt.Println()
// 			fmt.Println()
// 		}
// 	}
// 	for i := len(path) - 1; i >= 0; i-- {
// 		fmt.Printf("%s ", moveNamesList[cube.moves[i]])
// 	}
// 	fmt.Printf("\nNumber of moves : %d\n", nbMoves)
// }

func resolve3x3Cube(cube *Cube3x3) {
	if verbose || superVerbose {
		fmt.Println("GOAL :\n")
		cube.printCube3x3(cube.goal, true, true)
		fmt.Println("\n\nCUBE :\n")
		cube.printCube3x3(cube.cube, true, true)
		fmt.Println()
	}

	path, nbMoves := cube.solve()
	// fmt.Println(path)
	if verbose || superVerbose {
		if superVerbose {
			for j := 0; j < 5000000000; j++ {

			}
			print("\033[H\033[2J")
		}
		for i := len(path) - 1; i >= 0; i-- {
			if superVerbose {
				print("\033[H\033[2J")
			}
			cube.printCube3x3(path[i], false, true)
			if superVerbose {
				for j := 0; j < 5000000000; j++ {

				}
			}
			fmt.Println()
			fmt.Println()
		}
	}
	for i := len(path) - 1; i >= 0; i-- {
		fmt.Printf("%s", moveNamesList[cube.moves[i]])
		if i > 0 && moveNamesList[cube.moves[i]] == moveNamesList[cube.moves[i-1]] {
			fmt.Print("2")
			i--
		}
		if i > 0 {
			fmt.Print(" ")
		} else {
			fmt.Println()
		}
	}
	if verbose || superVerbose {
		fmt.Printf("\nNumber of moves : %d\n", nbMoves)
	}
}

func generateCube(movementsLen string) string {
	var moveLen int
	if moveLenTmp, err := strconv.ParseInt(movementsLen, 0, 32); err == nil {
		moveLen = int(moveLenTmp)
	} else {
		runError(ARGSYNT_ERR)
	}

	var movements string = ""

	rand.Seed(time.Now().UnixNano())
	for i := 0; i < moveLen; i++ {
		movements += moveNamesList[rand.Intn(11)]
		if i < moveLen-1 {
			movements += " "
		}
	}

	return movements
}

var cpuprofile = flag.String("cpuprofile", "", "write cpu profile to file")

func main() {

	flag.Parse()
	if *cpuprofile != "" {
		f, err := os.Create(*cpuprofile)
		if err != nil {
			log.Fatal(err)
		}
		pprof.StartCPUProfile(f)
		defer pprof.StopCPUProfile()
	}

	var movements string
	// cubeLen := int64(3)

	if len(os.Args) < 2 {
		runError(ARGNB_ERR)
	}

	for i := 0; i < len(os.Args); i++ {
		switch os.Args[i] {
		case "-g":
			if len(os.Args) <= i+1 {
				runError(ARGNB_ERR)
			}
			if movements == "" {
				movements = generateCube(os.Args[i+1])
			}
			i++
			break
		case "-v":
			verbose = true
			break
		case "-sv":
			superVerbose = true
			break
		case "-s":
			if len(os.Args) <= i+1 {
				runError(ARGNB_ERR)
			}
			// if cubeLenTmp, err := strconv.ParseInt(os.Args[i+1], 0, 32); err == nil {
			// 	cubeLen = cubeLenTmp
			// 	i++
			// } else {
			// 	runError(ARGSYNT_ERR)
			// }
			break
		case "-h":
			runError(HELP_ERR)
			break
		default:
			if i > 0 {
				movements = os.Args[i]
			}
		}
	}

	if verbose && superVerbose {
		runError(VBSVB_ERR)
	}

	if verbose || superVerbose {
		fmt.Println("INITIAL MOVEMENTS :")
		fmt.Println(movements + "\n")
	}

	databaseCorners = make([][]Cubie, 0)
	databaseScoresCorners = make([]byte, 0)
	loadDBCorners()

	databaseHalf = make([][]Cubie, 0)
	databaseScoresHalf = make([]byte, 0)
	loadDBHalf()

	databaseRest = make([][]Cubie, 0)
	databaseScoresRest = make([]byte, 0)
	loadDBRest()

	// for _, dataS := range databaseScoresCorners {
	// 	fmt.Println(dataS)
	// }

	// if cubeLen == 2 {
	// 	cube := New2x2Cube(movements)
	// 	resolve2x2Cube(cube)
	// } else {
	cube := New3x3Cube(movements)
	if !generateDb {
		resolve3x3Cube(cube)
	}
	// }

	if generateDb {
		fmt.Println("Corners")
		saveDBCorners(cube)
		fmt.Println("Half")
		saveDBHalf(cube)
		fmt.Println("Rest")
		saveDBRest(cube)
	}

	// fmt.Println("DATABASE\n", databaseCorners, "\n")
	// fmt.Println("\nDATABASE SCORES\n", databaseScoresCorners)

}
