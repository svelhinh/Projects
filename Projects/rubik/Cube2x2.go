/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube2x2.go                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:59:42 by oseng             #+#    #+#             */
/*   Updated: 2018/04/12 18:34:45 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

package main

import (
	"fmt"
	"reflect"
	"strings"
)

const (
	NIL_2x2 Cubie = 0
	U0_2x2  Cubie = 1
	U1_2x2  Cubie = 2
	U2_2x2  Cubie = 3
	U3_2x2  Cubie = 4

	L0_2x2 Cubie = 5
	L1_2x2 Cubie = 6
	L2_2x2 Cubie = 7
	L3_2x2 Cubie = 8

	F0_2x2 Cubie = 9
	F1_2x2 Cubie = 10
	F2_2x2 Cubie = 11
	F3_2x2 Cubie = 12

	R0_2x2 Cubie = 13
	R1_2x2 Cubie = 14
	R2_2x2 Cubie = 15
	R3_2x2 Cubie = 16

	B0_2x2 Cubie = 17
	B1_2x2 Cubie = 18
	B2_2x2 Cubie = 19
	B3_2x2 Cubie = 20

	D0_2x2 Cubie = 21
	D1_2x2 Cubie = 22
	D2_2x2 Cubie = 23
	D3_2x2 Cubie = 24
)

var faces2x2 = make([]CubieInfo, 25)

type Cube2x2 struct {
	size       int
	rowSize    int
	columnSize int
	nbMoves    int
	moves      []int
	goal       []Cubie
	cube       []Cubie
	finalPath  [][]Cubie
}

func New2x2Cube(startMoves string) *Cube2x2 {
	cube := new(Cube2x2)
	cube.size = 48
	cube.rowSize = 8
	cube.columnSize = 6

	cube.initFaces()
	cube.generateGoal()
	cube.shuffle(startMoves)
	return cube
}

func (cube *Cube2x2) initFaces() {
	faces2x2[NIL_2x2] = CubieInfo{}

	faces2x2[U0_2x2] = CubieInfo{Vector3{0, 0, 1}, 2}
	faces2x2[U1_2x2] = CubieInfo{Vector3{1, 0, 1}, 3}
	faces2x2[U2_2x2] = CubieInfo{Vector3{0, 0, 0}, 10}
	faces2x2[U3_2x2] = CubieInfo{Vector3{1, 0, 0}, 11}

	faces2x2[L0_2x2] = CubieInfo{Vector3{0, 0, 1}, 16}
	faces2x2[L1_2x2] = CubieInfo{Vector3{0, 0, 1}, 17}
	faces2x2[L2_2x2] = CubieInfo{Vector3{0, 1, 1}, 24}
	faces2x2[L3_2x2] = CubieInfo{Vector3{0, 1, 0}, 25}

	faces2x2[F0_2x2] = CubieInfo{Vector3{0, 0, 0}, 18}
	faces2x2[F1_2x2] = CubieInfo{Vector3{1, 0, 0}, 19}
	faces2x2[F2_2x2] = CubieInfo{Vector3{0, 1, 0}, 26}
	faces2x2[F3_2x2] = CubieInfo{Vector3{1, 1, 0}, 27}

	faces2x2[R0_2x2] = CubieInfo{Vector3{0, 0, 0}, 20}
	faces2x2[R1_2x2] = CubieInfo{Vector3{0, 0, 1}, 21}
	faces2x2[R2_2x2] = CubieInfo{Vector3{0, 1, 0}, 28}
	faces2x2[R3_2x2] = CubieInfo{Vector3{0, 1, 1}, 29}

	faces2x2[B0_2x2] = CubieInfo{Vector3{1, 0, 0}, 22}
	faces2x2[B1_2x2] = CubieInfo{Vector3{0, 0, 0}, 23}
	faces2x2[B2_2x2] = CubieInfo{Vector3{1, 1, 0}, 30}
	faces2x2[B3_2x2] = CubieInfo{Vector3{0, 1, 0}, 31}

	faces2x2[D0_2x2] = CubieInfo{Vector3{0, 0, 0}, 34}
	faces2x2[D1_2x2] = CubieInfo{Vector3{1, 0, 0}, 35}
	faces2x2[D2_2x2] = CubieInfo{Vector3{0, 0, 1}, 42}
	faces2x2[D3_2x2] = CubieInfo{Vector3{1, 0, 1}, 43}
}

func (cube *Cube2x2) generateGoal() {
	cube.goal = make([]Cubie, cube.size)

	for faceInfoI, faceInfo := range faces2x2 {
		cube.goal[faceInfo.index] = Cubie(faceInfoI)
	}
}

func (cube Cube2x2) printCube2x2(cubeArr []Cubie, indexes bool, cubiesNumbers bool) {
	for cubieI, cubie := range cubeArr {
		if cubieI/cube.rowSize != 0 && cubieI%cube.rowSize == 0 {
			fmt.Println()
		}
		if cubie >= U0_2x2 && cubie <= U3_2x2 {
			fmt.Print("\033[107m")
		} else if cubie >= L0_2x2 && cubie <= L3_2x2 {
			fmt.Print("\033[42m")
		} else if cubie >= F0_2x2 && cubie <= F3_2x2 {
			fmt.Print("\033[41m")
		} else if cubie >= R0_2x2 && cubie <= R3_2x2 {
			fmt.Print("\033[44m")
		} else if cubie >= B0_2x2 && cubie <= B3_2x2 {
			fmt.Print("\033[45m")
		} else if cubie >= D0_2x2 {
			fmt.Print("\033[43m")
		} else {
			fmt.Print("\033[0m     ")
			continue
		}
		if indexes {
			fmt.Printf(" %3d ", cubieI)
		} else if cubiesNumbers {
			fmt.Printf(" %3d ", cubie)
		} else {
			fmt.Printf("     ")
		}
		fmt.Print("\033[0m")
	}
	fmt.Println()
}

func (cube *Cube2x2) moveFace(upLeft int, clockwise bool, cubeToMove []Cubie) []Cubie {
	tmpCube := make([]Cubie, cube.size)
	copy(tmpCube, cubeToMove)

	upLeftPlusRowSize := upLeft + cube.rowSize

	if clockwise {
		tmpCube[upLeft] = cubeToMove[upLeftPlusRowSize]
		tmpCube[upLeft+1] = cubeToMove[upLeft]
		tmpCube[upLeftPlusRowSize] = cubeToMove[upLeftPlusRowSize+1]
		tmpCube[upLeftPlusRowSize+1] = cubeToMove[upLeft+1]
	} else {
		tmpCube[upLeft] = cubeToMove[upLeft+1]
		tmpCube[upLeft+1] = cubeToMove[upLeftPlusRowSize+1]
		tmpCube[upLeftPlusRowSize] = cubeToMove[upLeft]
		tmpCube[upLeftPlusRowSize+1] = cubeToMove[upLeftPlusRowSize]
	}
	return tmpCube
}

func (cube *Cube2x2) moveUp(clockwise bool, cubeToMove []Cubie) []Cubie {

	// UP
	tmpCube := cube.moveFace(2, clockwise, cubeToMove)

	if clockwise {
		// LEFT, FRONT, RIGHT
		for cubie := 16; cubie < 22; cubie++ {
			tmpCube[cubie] = cubeToMove[cubie+2]
		}

		// BACK
		tmpCube[22] = cubeToMove[16]
		tmpCube[23] = cubeToMove[17]
	} else {

		// LEFT
		tmpCube[16] = cubeToMove[22]
		tmpCube[17] = cubeToMove[23]

		// FRONT, RIGHT, BACK
		for cubie := 18; cubie < 24; cubie++ {
			tmpCube[cubie] = cubeToMove[cubie-2]
		}
	}

	return tmpCube
}

func (cube *Cube2x2) moveDown(clockwise bool, cubeToMove []Cubie) []Cubie {

	// DOWN
	tmpCube := cube.moveFace(34, clockwise, cubeToMove)

	if clockwise {

		// LEFT
		tmpCube[24] = cubeToMove[30]
		tmpCube[25] = cubeToMove[31]

		// FRONT, RIGHT, BACK
		for cubie := 26; cubie < 32; cubie++ {
			tmpCube[cubie] = cubeToMove[cubie-2]
		}
	} else {

		// LEFT, FRONT, RIGHT
		for cubie := 24; cubie < 30; cubie++ {
			tmpCube[cubie] = cubeToMove[cubie+2]
		}

		// BACK
		tmpCube[30] = cubeToMove[24]
		tmpCube[31] = cubeToMove[25]
	}
	return tmpCube
}

func (cube *Cube2x2) moveRight(clockwise bool, cubeToMove []Cubie) []Cubie {

	// RIGHT
	tmpCube := cube.moveFace(20, clockwise, cubeToMove)

	if clockwise {

		// UP, FRONT
		for cubie := 3; cubie < 28; cubie += 8 {
			tmpCube[cubie] = cubeToMove[cubie+8*2]
		}

		// DOWN
		tmpCube[35] = cubeToMove[30]
		tmpCube[43] = cubeToMove[22]

		// BACK
		tmpCube[22] = cubeToMove[11]
		tmpCube[30] = cubeToMove[3]
	} else {

		// UP
		tmpCube[3] = cubeToMove[30]
		tmpCube[11] = cubeToMove[22]

		// FRONT, DOWN
		for cubie := 19; cubie < 44; cubie += 8 {
			tmpCube[cubie] = cubeToMove[cubie-8*2]
		}

		// BACK
		tmpCube[22] = cubeToMove[43]
		tmpCube[30] = cubeToMove[35]
	}

	return tmpCube
}

func (cube *Cube2x2) moveLeft(clockwise bool, cubeToMove []Cubie) []Cubie {

	// LEFT
	tmpCube := cube.moveFace(16, clockwise, cubeToMove)

	if clockwise {

		// UP
		tmpCube[2] = cubeToMove[31]
		tmpCube[10] = cubeToMove[23]

		// FRONT, DOWN
		for cubie := 18; cubie < 43; cubie += 8 {
			tmpCube[cubie] = cubeToMove[cubie-8*2]
		}

		// BACK
		tmpCube[23] = cubeToMove[42]
		tmpCube[31] = cubeToMove[34]
	} else {

		// UP, FRONT
		for cubie := 2; cubie < 27; cubie += 8 {
			tmpCube[cubie] = cubeToMove[cubie+8*2]
		}

		// DOWN
		tmpCube[34] = cubeToMove[31]
		tmpCube[42] = cubeToMove[23]

		// BACK
		tmpCube[23] = cubeToMove[10]
		tmpCube[31] = cubeToMove[2]
	}

	return tmpCube
}

func (cube *Cube2x2) moveFront(clockwise bool, cubeToMove []Cubie) []Cubie {

	// FRONT
	tmpCube := cube.moveFace(18, clockwise, cubeToMove)

	if clockwise {

		// UP
		tmpCube[10] = cubeToMove[25]
		tmpCube[11] = cubeToMove[17]

		// LEFT
		tmpCube[17] = cubeToMove[34]
		tmpCube[25] = cubeToMove[35]

		// RIGHT
		tmpCube[20] = cubeToMove[10]
		tmpCube[28] = cubeToMove[11]

		// DOWN
		tmpCube[34] = cubeToMove[28]
		tmpCube[35] = cubeToMove[20]
	} else {

		// UP
		tmpCube[10] = cubeToMove[20]
		tmpCube[11] = cubeToMove[28]

		// LEFT
		tmpCube[17] = cubeToMove[11]
		tmpCube[25] = cubeToMove[10]

		// RIGHT
		tmpCube[20] = cubeToMove[35]
		tmpCube[28] = cubeToMove[34]

		// DOWN
		tmpCube[34] = cubeToMove[17]
		tmpCube[35] = cubeToMove[25]
	}
	return tmpCube
}

func (cube *Cube2x2) moveBack(clockwise bool, cubeToMove []Cubie) []Cubie {

	// BACK
	tmpCube := cube.moveFace(22, clockwise, cubeToMove)

	if clockwise {

		// UP
		tmpCube[2] = cubeToMove[21]
		tmpCube[3] = cubeToMove[29]

		// LEFT
		tmpCube[16] = cubeToMove[3]
		tmpCube[24] = cubeToMove[2]

		// RIGHT
		tmpCube[21] = cubeToMove[43]
		tmpCube[29] = cubeToMove[42]

		// DOWN
		tmpCube[42] = cubeToMove[16]
		tmpCube[43] = cubeToMove[24]
	} else {

		// UP
		tmpCube[2] = cubeToMove[24]
		tmpCube[3] = cubeToMove[16]

		// LEFT
		tmpCube[16] = cubeToMove[42]
		tmpCube[24] = cubeToMove[43]

		// RIGHT
		tmpCube[21] = cubeToMove[2]
		tmpCube[29] = cubeToMove[3]

		// DOWN
		tmpCube[42] = cubeToMove[29]
		tmpCube[43] = cubeToMove[21]
	}
	return tmpCube
}

func (cube *Cube2x2) parseMove(move byte, clockwise bool) {
	switch move {
	case 'F':
		cube.cube = cube.moveFront(clockwise, cube.cube)
		break
	case 'R':
		cube.cube = cube.moveRight(clockwise, cube.cube)
		break
	case 'L':
		cube.cube = cube.moveLeft(clockwise, cube.cube)
		break
	case 'D':
		cube.cube = cube.moveDown(clockwise, cube.cube)
		break
	case 'B':
		cube.cube = cube.moveBack(clockwise, cube.cube)
		break
	case 'U':
		cube.cube = cube.moveUp(clockwise, cube.cube)
		break
	default:
		fmt.Printf("%c", move)
		runError(MOVE_ERR)
	}
}

func (cube *Cube2x2) shuffle(startMoves string) {

	cube.cube = make([]Cubie, cube.size)
	copy(cube.cube, cube.goal)

	splittedStartMoves := strings.Split(startMoves, " ")

	for _, move := range splittedStartMoves {
		if len(move) == 1 {
			cube.parseMove(move[0], true)
		} else if len(move) == 2 {
			if move[1] == '2' {
				cube.parseMove(move[0], true)
				cube.parseMove(move[0], true)
			} else if move[1] == '\'' {
				cube.parseMove(move[0], false)
			} else {
				fmt.Printf("%s", move)
				runError(MOVE_ERR)
			}
		} else {
			fmt.Printf("%s", move)
			runError(MOVE_ERR)
		}
	}
}

func (cube *Cube2x2) solve() ([][]Cubie, int) {

	var path [][]Cubie
	var g int

	bound := manhattanDistance3D(cube.goal, cube.cube, faces2x2)
	path = append(path, cube.cube)

	for {
		t := cube.search(path, g, bound)
		if t == -1 {
			return cube.finalPath, cube.nbMoves
		}
		if t == 1000000000000 {
			return cube.finalPath, -1
		}
		bound = t
	}
}

func (cube *Cube2x2) search(path [][]Cubie, g int, bound int) int {
	node := path[len(path)-1]

	f := g + manhattanDistance3D(cube.goal, node, faces2x2)

	if f > bound {
		return f
	}

	if reflect.DeepEqual(node, cube.goal) {
		return -1
	}

	min := 1000000000000

	for i, succ := range cube.successors(node, g) {

		if !contains(path, succ) {
			path = append(path, succ)
			t := cube.search(path, g+2, bound)
			if t == -1 {
				cube.finalPath = append(cube.finalPath, path[len(path)-1])
				cube.nbMoves++
				cube.moves = append(cube.moves, i)
				return -1
			}
			if t < min {
				min = t
			}
			path = append(path[:len(path)-1], path[len(path):]...)
		}
	}

	return min
}

func (cube *Cube2x2) successors(cubeToTest []Cubie, g int) [][]Cubie {

	var possibleCubes [][]Cubie

	possibleCubes = append(possibleCubes, cube.moveUp(true, cubeToTest), cube.moveUp(false, cubeToTest), cube.moveLeft(true, cubeToTest), cube.moveLeft(false, cubeToTest), cube.moveRight(true, cubeToTest), cube.moveRight(false, cubeToTest), cube.moveDown(true, cubeToTest), cube.moveDown(false, cubeToTest), cube.moveBack(true, cubeToTest), cube.moveBack(false, cubeToTest), cube.moveFront(true, cubeToTest), cube.moveFront(false, cubeToTest))

	return possibleCubes
}
