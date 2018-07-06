/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3x3.go                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:59:35 by svelhinh          #+#    #+#             */
/*   Updated: 2018/04/18 19:50:51 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

package main

import (
	"fmt"
	"math"
	"strings"
)

const (
	NIL_3x3 Cubie = 0
	U0_3x3  Cubie = 1
	U1_3x3  Cubie = 2
	U2_3x3  Cubie = 3
	U3_3x3  Cubie = 4
	U4_3x3  Cubie = 5
	U5_3x3  Cubie = 6
	U6_3x3  Cubie = 7
	U7_3x3  Cubie = 8
	U8_3x3  Cubie = 9
	L0_3x3  Cubie = 10
	L1_3x3  Cubie = 11
	L2_3x3  Cubie = 12
	L3_3x3  Cubie = 13
	L4_3x3  Cubie = 14
	L5_3x3  Cubie = 15
	L6_3x3  Cubie = 16
	L7_3x3  Cubie = 17
	L8_3x3  Cubie = 18
	F0_3x3  Cubie = 19
	F1_3x3  Cubie = 20
	F2_3x3  Cubie = 21
	F3_3x3  Cubie = 22
	F4_3x3  Cubie = 23
	F5_3x3  Cubie = 24
	F6_3x3  Cubie = 25
	F7_3x3  Cubie = 26
	F8_3x3  Cubie = 27
	R0_3x3  Cubie = 28
	R1_3x3  Cubie = 29
	R2_3x3  Cubie = 30
	R3_3x3  Cubie = 31
	R4_3x3  Cubie = 32
	R5_3x3  Cubie = 33
	R6_3x3  Cubie = 34
	R7_3x3  Cubie = 35
	R8_3x3  Cubie = 36
	B0_3x3  Cubie = 37
	B1_3x3  Cubie = 38
	B2_3x3  Cubie = 39
	B3_3x3  Cubie = 40
	B4_3x3  Cubie = 41
	B5_3x3  Cubie = 42
	B6_3x3  Cubie = 43
	B7_3x3  Cubie = 44
	B8_3x3  Cubie = 45
	D0_3x3  Cubie = 46
	D1_3x3  Cubie = 47
	D2_3x3  Cubie = 48
	D3_3x3  Cubie = 49
	D4_3x3  Cubie = 50
	D5_3x3  Cubie = 51
	D6_3x3  Cubie = 52
	D7_3x3  Cubie = 53
	D8_3x3  Cubie = 54
)

var faces3x3 = make([][]int, 108)

type Cube3x3 struct {
	size       int
	rowSize    int
	columnSize int
	nbMoves    int
	moves      []int
	goal       []Cubie
	cube       []Cubie
	finalPath  [][]Cubie
}

func New3x3Cube(startMoves string) *Cube3x3 {
	cube := new(Cube3x3)
	cube.size = 108
	cube.rowSize = 12
	cube.columnSize = 9

	cube.initFaces()
	cube.generateGoal()
	cube.shuffle(startMoves)
	return cube
}

func (cube *Cube3x3) initFaces() {

	faces3x3[3] = make([]int, 4)
	faces3x3[3][0] = 0
	faces3x3[3][1] = 0
	faces3x3[3][2] = 2
	faces3x3[3][3] = 1

	faces3x3[4] = make([]int, 4)
	faces3x3[4][0] = 1
	faces3x3[4][1] = 0
	faces3x3[4][2] = 2
	faces3x3[4][3] = 2

	faces3x3[5] = make([]int, 4)
	faces3x3[5][0] = 2
	faces3x3[5][1] = 0
	faces3x3[5][2] = 2
	faces3x3[5][3] = 3

	faces3x3[15] = make([]int, 4)
	faces3x3[15][0] = 0
	faces3x3[15][1] = 0
	faces3x3[15][2] = 1
	faces3x3[15][3] = 4

	faces3x3[16] = make([]int, 4)
	faces3x3[16][0] = 1
	faces3x3[16][1] = 0
	faces3x3[16][2] = 1
	faces3x3[16][3] = 5

	faces3x3[17] = make([]int, 4)
	faces3x3[17][0] = 2
	faces3x3[17][1] = 0
	faces3x3[17][2] = 1
	faces3x3[17][3] = 6

	faces3x3[27] = make([]int, 4)
	faces3x3[27][0] = 0
	faces3x3[27][1] = 0
	faces3x3[27][2] = 0
	faces3x3[27][3] = 7

	faces3x3[28] = make([]int, 4)
	faces3x3[28][0] = 1
	faces3x3[28][1] = 0
	faces3x3[28][2] = 0
	faces3x3[28][3] = 8

	faces3x3[29] = make([]int, 4)
	faces3x3[29][0] = 2
	faces3x3[29][1] = 0
	faces3x3[29][2] = 0
	faces3x3[29][3] = 9

	faces3x3[36] = make([]int, 4)
	faces3x3[36][0] = 0
	faces3x3[36][1] = 0
	faces3x3[36][2] = 2
	faces3x3[36][3] = 10

	faces3x3[37] = make([]int, 4)
	faces3x3[37][0] = 0
	faces3x3[37][1] = 0
	faces3x3[37][2] = 1
	faces3x3[37][3] = 11

	faces3x3[38] = make([]int, 4)
	faces3x3[38][0] = 0
	faces3x3[38][1] = 0
	faces3x3[38][2] = 0
	faces3x3[38][3] = 12

	faces3x3[48] = make([]int, 4)
	faces3x3[48][0] = 0
	faces3x3[48][1] = 1
	faces3x3[48][2] = 2
	faces3x3[48][3] = 13

	faces3x3[49] = make([]int, 4)
	faces3x3[49][0] = 0
	faces3x3[49][1] = 1
	faces3x3[49][2] = 1
	faces3x3[49][3] = 14

	faces3x3[50] = make([]int, 4)
	faces3x3[50][0] = 0
	faces3x3[50][1] = 1
	faces3x3[50][2] = 0
	faces3x3[50][3] = 15

	faces3x3[60] = make([]int, 4)
	faces3x3[60][0] = 0
	faces3x3[60][1] = 2
	faces3x3[60][2] = 2
	faces3x3[60][3] = 16

	faces3x3[61] = make([]int, 4)
	faces3x3[61][0] = 0
	faces3x3[61][1] = 2
	faces3x3[61][2] = 1
	faces3x3[61][3] = 17

	faces3x3[62] = make([]int, 4)
	faces3x3[62][0] = 0
	faces3x3[62][1] = 2
	faces3x3[62][2] = 0
	faces3x3[62][3] = 18

	faces3x3[39] = make([]int, 4)
	faces3x3[39][0] = 0
	faces3x3[39][1] = 0
	faces3x3[39][2] = 0
	faces3x3[39][3] = 19

	faces3x3[40] = make([]int, 4)
	faces3x3[40][0] = 1
	faces3x3[40][1] = 0
	faces3x3[40][2] = 0
	faces3x3[40][3] = 20

	faces3x3[41] = make([]int, 4)
	faces3x3[41][0] = 2
	faces3x3[41][1] = 0
	faces3x3[41][2] = 0
	faces3x3[41][3] = 21

	faces3x3[51] = make([]int, 4)
	faces3x3[51][0] = 0
	faces3x3[51][1] = 1
	faces3x3[51][2] = 0
	faces3x3[51][3] = 22

	faces3x3[52] = make([]int, 4)
	faces3x3[52][0] = 1
	faces3x3[52][1] = 1
	faces3x3[52][2] = 0
	faces3x3[52][3] = 23

	faces3x3[53] = make([]int, 4)
	faces3x3[53][0] = 2
	faces3x3[53][1] = 1
	faces3x3[53][2] = 0
	faces3x3[53][3] = 24

	faces3x3[63] = make([]int, 4)
	faces3x3[63][0] = 0
	faces3x3[63][1] = 2
	faces3x3[63][2] = 0
	faces3x3[63][3] = 25

	faces3x3[64] = make([]int, 4)
	faces3x3[64][0] = 1
	faces3x3[64][1] = 2
	faces3x3[64][2] = 0
	faces3x3[64][3] = 26

	faces3x3[65] = make([]int, 4)
	faces3x3[65][0] = 2
	faces3x3[65][1] = 2
	faces3x3[65][2] = 0
	faces3x3[65][3] = 27

	faces3x3[42] = make([]int, 4)
	faces3x3[42][0] = 0
	faces3x3[42][1] = 0
	faces3x3[42][2] = 0
	faces3x3[42][3] = 28

	faces3x3[43] = make([]int, 4)
	faces3x3[43][0] = 0
	faces3x3[43][1] = 0
	faces3x3[43][2] = 1
	faces3x3[43][3] = 29

	faces3x3[44] = make([]int, 4)
	faces3x3[44][0] = 0
	faces3x3[44][1] = 0
	faces3x3[44][2] = 2
	faces3x3[44][3] = 30

	faces3x3[54] = make([]int, 4)
	faces3x3[54][0] = 0
	faces3x3[54][1] = 1
	faces3x3[54][2] = 0
	faces3x3[54][3] = 31

	faces3x3[55] = make([]int, 4)
	faces3x3[55][0] = 0
	faces3x3[55][1] = 1
	faces3x3[55][2] = 1
	faces3x3[55][3] = 32

	faces3x3[56] = make([]int, 4)
	faces3x3[56][0] = 0
	faces3x3[56][1] = 1
	faces3x3[56][2] = 2
	faces3x3[56][3] = 33

	faces3x3[66] = make([]int, 4)
	faces3x3[66][0] = 0
	faces3x3[66][1] = 2
	faces3x3[66][2] = 0
	faces3x3[66][3] = 34

	faces3x3[67] = make([]int, 4)
	faces3x3[67][0] = 0
	faces3x3[67][1] = 2
	faces3x3[67][2] = 1
	faces3x3[67][3] = 35

	faces3x3[68] = make([]int, 4)
	faces3x3[68][0] = 0
	faces3x3[68][1] = 2
	faces3x3[68][2] = 2
	faces3x3[68][3] = 36

	faces3x3[45] = make([]int, 4)
	faces3x3[45][0] = 2
	faces3x3[45][1] = 0
	faces3x3[45][2] = 0
	faces3x3[45][3] = 37

	faces3x3[46] = make([]int, 4)
	faces3x3[46][0] = 1
	faces3x3[46][1] = 0
	faces3x3[46][2] = 0
	faces3x3[46][3] = 38

	faces3x3[47] = make([]int, 4)
	faces3x3[47][0] = 0
	faces3x3[47][1] = 0
	faces3x3[47][2] = 0
	faces3x3[47][3] = 39

	faces3x3[57] = make([]int, 4)
	faces3x3[57][0] = 2
	faces3x3[57][1] = 1
	faces3x3[57][2] = 0
	faces3x3[57][3] = 40

	faces3x3[58] = make([]int, 4)
	faces3x3[58][0] = 1
	faces3x3[58][1] = 1
	faces3x3[58][2] = 0
	faces3x3[58][3] = 41

	faces3x3[59] = make([]int, 4)
	faces3x3[59][0] = 0
	faces3x3[59][1] = 1
	faces3x3[59][2] = 0
	faces3x3[59][3] = 42

	faces3x3[69] = make([]int, 4)
	faces3x3[69][0] = 2
	faces3x3[69][1] = 2
	faces3x3[69][2] = 0
	faces3x3[69][3] = 43

	faces3x3[70] = make([]int, 4)
	faces3x3[70][0] = 1
	faces3x3[70][1] = 2
	faces3x3[70][2] = 0
	faces3x3[70][3] = 44

	faces3x3[71] = make([]int, 4)
	faces3x3[71][0] = 0
	faces3x3[71][1] = 2
	faces3x3[71][2] = 0
	faces3x3[71][3] = 45

	faces3x3[75] = make([]int, 4)
	faces3x3[75][0] = 0
	faces3x3[75][1] = 0
	faces3x3[75][2] = 0
	faces3x3[75][3] = 46

	faces3x3[76] = make([]int, 4)
	faces3x3[76][0] = 1
	faces3x3[76][1] = 0
	faces3x3[76][2] = 0
	faces3x3[76][3] = 47

	faces3x3[77] = make([]int, 4)
	faces3x3[77][0] = 2
	faces3x3[77][1] = 0
	faces3x3[77][2] = 0
	faces3x3[77][3] = 48

	faces3x3[87] = make([]int, 4)
	faces3x3[87][0] = 0
	faces3x3[87][1] = 0
	faces3x3[87][2] = 1
	faces3x3[87][3] = 49

	faces3x3[88] = make([]int, 4)
	faces3x3[88][0] = 1
	faces3x3[88][1] = 0
	faces3x3[88][2] = 1
	faces3x3[88][3] = 50

	faces3x3[89] = make([]int, 4)
	faces3x3[89][0] = 2
	faces3x3[89][1] = 0
	faces3x3[89][2] = 1
	faces3x3[89][3] = 51

	faces3x3[99] = make([]int, 4)
	faces3x3[99][0] = 0
	faces3x3[99][1] = 0
	faces3x3[99][2] = 2
	faces3x3[99][3] = 52

	faces3x3[100] = make([]int, 4)
	faces3x3[100][0] = 1
	faces3x3[100][1] = 0
	faces3x3[100][2] = 2
	faces3x3[100][3] = 53

	faces3x3[101] = make([]int, 4)
	faces3x3[101][0] = 2
	faces3x3[101][1] = 0
	faces3x3[101][2] = 2
	faces3x3[101][3] = 54
}

func (cube *Cube3x3) generateGoal() {
	cube.goal = make([]Cubie, cube.size)

	for faceInfoI, faceInfo := range faces3x3 {
		if faceInfo != nil {
			cube.goal[faceInfoI] = Cubie(faceInfo[3])
			continue
		}
		cube.goal[faceInfoI] = NIL_3x3
	}
}

func (cube Cube3x3) printCube3x3(cubeArr []Cubie, indexes bool, cubiesNumbers bool) {
	for cubieI, cubie := range cubeArr {
		if cubieI/cube.rowSize != 0 && cubieI%cube.rowSize == 0 {
			fmt.Println()
		}
		if cubie >= U0_3x3 && cubie <= U8_3x3 {
			fmt.Print("\033[107m")
		} else if cubie >= L0_3x3 && cubie <= L8_3x3 {
			fmt.Print("\033[42m")
		} else if cubie >= F0_3x3 && cubie <= F8_3x3 {
			fmt.Print("\033[41m")
		} else if cubie >= R0_3x3 && cubie <= R8_3x3 {
			fmt.Print("\033[44m")
		} else if cubie >= B0_3x3 && cubie <= B8_3x3 {
			fmt.Print("\033[45m")
		} else if cubie >= D0_3x3 {
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

func (cube *Cube3x3) moveFace(upLeft int, clockwise bool, cubeToMove []Cubie) []Cubie {
	tmpCube := make([]Cubie, cube.size)
	copy(tmpCube, cubeToMove)

	if clockwise {
		tmpCube[upLeft] = cubeToMove[upLeft+cube.rowSize*2]
		tmpCube[upLeft+1] = cubeToMove[upLeft+cube.rowSize]
		tmpCube[upLeft+2] = cubeToMove[upLeft]
		tmpCube[upLeft+cube.rowSize] = cubeToMove[upLeft+cube.rowSize*2+1]
		tmpCube[upLeft+cube.rowSize+2] = cubeToMove[upLeft+1]
		tmpCube[upLeft+cube.rowSize*2] = cubeToMove[upLeft+cube.rowSize*2+2]
		tmpCube[upLeft+cube.rowSize*2+1] = cubeToMove[upLeft+cube.rowSize+2]
		tmpCube[upLeft+cube.rowSize*2+2] = cubeToMove[upLeft+2]
	} else {
		tmpCube[upLeft] = cubeToMove[upLeft+2]
		tmpCube[upLeft+1] = cubeToMove[upLeft+cube.rowSize+2]
		tmpCube[upLeft+2] = cubeToMove[upLeft+cube.rowSize*2+2]
		tmpCube[upLeft+cube.rowSize] = cubeToMove[upLeft+1]
		tmpCube[upLeft+cube.rowSize+2] = cubeToMove[upLeft+cube.rowSize*2+1]
		tmpCube[upLeft+cube.rowSize*2] = cubeToMove[upLeft]
		tmpCube[upLeft+cube.rowSize*2+1] = cubeToMove[upLeft+cube.rowSize]
		tmpCube[upLeft+cube.rowSize*2+2] = cubeToMove[upLeft+cube.rowSize*2]
	}
	return tmpCube
}

func (cube *Cube3x3) moveUp(clockwise bool, cubeToMove []Cubie) []Cubie {

	// UP
	tmpCube := cube.moveFace(3, clockwise, cubeToMove)

	if clockwise {
		// LEFT, FRONT, RIGHT
		for cubie := 36; cubie < 45; cubie++ {
			tmpCube[cubie] = cubeToMove[cubie+3]
		}

		// BACK
		tmpCube[45] = cubeToMove[36]
		tmpCube[46] = cubeToMove[37]
		tmpCube[47] = cubeToMove[38]
	} else {

		// LEFT
		tmpCube[36] = cubeToMove[45]
		tmpCube[37] = cubeToMove[46]
		tmpCube[38] = cubeToMove[47]

		// FRONT, RIGHT, BACK
		for cubie := 39; cubie < 48; cubie++ {
			tmpCube[cubie] = cubeToMove[cubie-3]
		}
	}

	return tmpCube
}

func (cube *Cube3x3) moveDown(clockwise bool, cubeToMove []Cubie) []Cubie {

	// DOWN
	tmpCube := cube.moveFace(75, clockwise, cubeToMove)

	if clockwise {

		// LEFT
		tmpCube[60] = cubeToMove[69]
		tmpCube[61] = cubeToMove[70]
		tmpCube[62] = cubeToMove[71]

		// FRONT, RIGHT, BACK
		for cubie := 63; cubie < 72; cubie++ {
			tmpCube[cubie] = cubeToMove[cubie-3]
		}
	} else {

		// LEFT, FRONT, RIGHT
		for cubie := 60; cubie < 69; cubie++ {
			tmpCube[cubie] = cubeToMove[cubie+3]
		}

		// BACK
		tmpCube[69] = cubeToMove[60]
		tmpCube[70] = cubeToMove[61]
		tmpCube[71] = cubeToMove[62]
	}
	return tmpCube
}

func (cube *Cube3x3) moveRight(clockwise bool, cubeToMove []Cubie) []Cubie {

	// RIGHT
	tmpCube := cube.moveFace(42, clockwise, cubeToMove)

	if clockwise {

		// UP, FRONT
		for cubie := 5; cubie < 66; cubie += 12 {
			tmpCube[cubie] = cubeToMove[cubie+12*3]
		}

		// DOWN
		tmpCube[77] = cubeToMove[69]
		tmpCube[89] = cubeToMove[57]
		tmpCube[101] = cubeToMove[45]

		// BACK
		tmpCube[45] = cubeToMove[29]
		tmpCube[57] = cubeToMove[17]
		tmpCube[69] = cubeToMove[5]
	} else {

		// UP
		tmpCube[5] = cubeToMove[69]
		tmpCube[17] = cubeToMove[57]
		tmpCube[29] = cubeToMove[45]

		// FRONT, DOWN
		for cubie := 41; cubie < 102; cubie += 12 {
			tmpCube[cubie] = cubeToMove[cubie-12*3]
		}

		// BACK
		tmpCube[45] = cubeToMove[101]
		tmpCube[57] = cubeToMove[89]
		tmpCube[69] = cubeToMove[77]
	}

	return tmpCube
}

func (cube *Cube3x3) moveLeft(clockwise bool, cubeToMove []Cubie) []Cubie {

	// LEFT
	tmpCube := cube.moveFace(36, clockwise, cubeToMove)

	if clockwise {

		// UP
		tmpCube[3] = cubeToMove[71]
		tmpCube[15] = cubeToMove[59]
		tmpCube[27] = cubeToMove[47]

		// FRONT, DOWN
		for cubie := 39; cubie < 100; cubie += 12 {
			tmpCube[cubie] = cubeToMove[cubie-12*3]
		}

		// BACK
		tmpCube[47] = cubeToMove[99]
		tmpCube[59] = cubeToMove[87]
		tmpCube[71] = cubeToMove[75]
	} else {

		// UP, FRONT
		for cubie := 3; cubie < 64; cubie += 12 {
			tmpCube[cubie] = cubeToMove[cubie+12*3]
		}

		// DOWN
		tmpCube[75] = cubeToMove[71]
		tmpCube[87] = cubeToMove[59]
		tmpCube[99] = cubeToMove[47]

		// BACK
		tmpCube[47] = cubeToMove[27]
		tmpCube[59] = cubeToMove[15]
		tmpCube[71] = cubeToMove[3]
	}

	return tmpCube
}

func (cube *Cube3x3) moveFront(clockwise bool, cubeToMove []Cubie) []Cubie {

	// FRONT
	tmpCube := cube.moveFace(39, clockwise, cubeToMove)

	if clockwise {

		// UP
		tmpCube[27] = cubeToMove[62]
		tmpCube[28] = cubeToMove[50]
		tmpCube[29] = cubeToMove[38]

		// LEFT
		tmpCube[38] = cubeToMove[75]
		tmpCube[50] = cubeToMove[76]
		tmpCube[62] = cubeToMove[77]

		// RIGHT
		tmpCube[42] = cubeToMove[27]
		tmpCube[54] = cubeToMove[28]
		tmpCube[66] = cubeToMove[29]

		// DOWN
		tmpCube[75] = cubeToMove[66]
		tmpCube[76] = cubeToMove[54]
		tmpCube[77] = cubeToMove[42]
	} else {

		// UP
		tmpCube[27] = cubeToMove[42]
		tmpCube[28] = cubeToMove[54]
		tmpCube[29] = cubeToMove[66]

		// LEFT
		tmpCube[38] = cubeToMove[29]
		tmpCube[50] = cubeToMove[28]
		tmpCube[62] = cubeToMove[27]

		// RIGHT
		tmpCube[42] = cubeToMove[77]
		tmpCube[54] = cubeToMove[76]
		tmpCube[66] = cubeToMove[75]

		// DOWN
		tmpCube[75] = cubeToMove[38]
		tmpCube[76] = cubeToMove[50]
		tmpCube[77] = cubeToMove[62]
	}
	return tmpCube
}

func (cube *Cube3x3) moveBack(clockwise bool, cubeToMove []Cubie) []Cubie {

	// BACK
	tmpCube := cube.moveFace(45, clockwise, cubeToMove)

	if clockwise {

		// UP
		tmpCube[3] = cubeToMove[44]
		tmpCube[4] = cubeToMove[56]
		tmpCube[5] = cubeToMove[68]

		// LEFT
		tmpCube[36] = cubeToMove[5]
		tmpCube[48] = cubeToMove[4]
		tmpCube[60] = cubeToMove[3]

		// RIGHT
		tmpCube[44] = cubeToMove[101]
		tmpCube[56] = cubeToMove[100]
		tmpCube[68] = cubeToMove[99]

		// DOWN
		tmpCube[99] = cubeToMove[36]
		tmpCube[100] = cubeToMove[48]
		tmpCube[101] = cubeToMove[60]
	} else {

		// UP
		tmpCube[3] = cubeToMove[60]
		tmpCube[4] = cubeToMove[48]
		tmpCube[5] = cubeToMove[36]

		// LEFT
		tmpCube[36] = cubeToMove[99]
		tmpCube[48] = cubeToMove[100]
		tmpCube[60] = cubeToMove[101]

		// RIGHT
		tmpCube[44] = cubeToMove[3]
		tmpCube[56] = cubeToMove[4]
		tmpCube[68] = cubeToMove[5]

		// DOWN
		tmpCube[99] = cubeToMove[68]
		tmpCube[100] = cubeToMove[56]
		tmpCube[101] = cubeToMove[44]
	}
	return tmpCube
}

func (cube *Cube3x3) parseMove(move byte, clockwise bool) {
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

func (cube *Cube3x3) shuffle(startMoves string) {

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

func (cube *Cube3x3) solve() ([][]Cubie, int) {

	var path [][]Cubie
	var g int
	var bound int

	// for i := 0; i < 2; i++ {
	bound = manhattanDistance3D(cube.goal, cube.cube, faces3x3 /*, int8(i)*/)
	path = append(path, cube.cube)

	for {
		t := cube.search(path, g, bound /*, int8(i)*/)
		if t == -1 {
			// break
			return cube.finalPath, cube.nbMoves
		}
		if t == math.MaxInt32 {
			// break
			return cube.finalPath, -1
		}
		bound = t
		// fmt.Println(bound)
	}
	/*fmt.Println("dfghjdfg")
	cube.printCube3x3(cube.finalPath[0], false, true)
	fmt.Println("dfghjdfg")*/
	// 	cube.cube = cube.finalPath[0]
	// }
	// return cube.finalPath, cube.nbMoves
}

func (cube *Cube3x3) search(path [][]Cubie, g int, bound int /*, goalNumber int8*/) int {
	node := path[len(path)-1]

	f := g + manhattanDistance3D(cube.goal, node, faces3x3 /*, goalNumber*/)

	if f > bound {
		return f
	}

	// switch goalNumber {
	// case 0:
	// 	isEqual := true
	// 	if node[3] != cube.goal[3] || node[5] != cube.goal[5] || node[27] != cube.goal[27] || node[29] != cube.goal[29] || node[75] != cube.goal[75] || node[77] != cube.goal[77] {
	// 		isEqual = false
	// 	}
	// 	if isEqual {
	// 		return -1
	// 	}
	// 	break
	// case 1:
	// 	isEqual := true
	// 	for cubieI := range node {
	// 		if cubieI != 0 && node[cubieI] != cube.cube[cubieI] {
	// 			isEqual = false
	// 			break
	// 		}
	// 	}
	// 	if isEqual && node[99] != cube.goal[99]/* || node[101] != cube.goal[101] */{
	// 		isEqual = false
	// 	}
	// 	if isEqual {
	// 		/*fmt.Println("Node")
	// 		cube.printCube3x3(node, false, true)
	// 		fmt.Println("Node")*/
	// 		return -1
	// 	}
	// 	break
	//case 2:
	isEqual := true
	for cubieI := range node {
		if cubieI != 0 && node[cubieI] != cube.goal[cubieI] {
			isEqual = false
			break
		}
	}
	if isEqual {
		// fmt.Println(node)
		// fmt.Println(cube.goal)
		return -1
	}
	// }

	min := math.MaxInt32

	for i, succ := range cube.successors(node) {

		if !contains(path, succ) {
			path = append(path, succ)
			t := cube.search(path, g+2, bound /*, goalNumber*/)
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

func (cube *Cube3x3) successors(cubeToTest []Cubie) [][]Cubie {

	var possibleCubes [][]Cubie
	// c := make(chan []Cubie)

	possibleCubes = append(possibleCubes, cube.moveUp(true, cubeToTest), cube.moveUp(false, cubeToTest), cube.moveLeft(true, cubeToTest), cube.moveLeft(false, cubeToTest), cube.moveRight(true, cubeToTest), cube.moveRight(false, cubeToTest), cube.moveDown(true, cubeToTest), cube.moveDown(false, cubeToTest), cube.moveBack(true, cubeToTest), cube.moveBack(false, cubeToTest), cube.moveFront(true, cubeToTest), cube.moveFront(false, cubeToTest))

	// go cube.moveUpNew(true, cubeToTest, c)
	// go cube.moveUpNew(false, cubeToTest, c)
	// go cube.moveLeftNew(true, cubeToTest, c)
	// go cube.moveLeftNew(false, cubeToTest, c)
	// go cube.moveRightNew(true, cubeToTest, c)
	// go cube.moveRightNew(false, cubeToTest, c)
	// go cube.moveDownNew(true, cubeToTest, c)
	// go cube.moveDownNew(false, cubeToTest, c)
	// go cube.moveBackNew(true, cubeToTest, c)
	// go cube.moveBackNew(false, cubeToTest, c)
	// go cube.moveFrontNew(true, cubeToTest, c)
	// go cube.moveFrontNew(false, cubeToTest, c)

	// i := 0
	// var stopLoop bool
	// for {
	// 	select {
	// 	case v := <-c:
	// 		possibleCubes = append(possibleCubes, v)
	// 		if i == 11 {
	// 			stopLoop = true
	// 		}
	// 		i++
	// 	}
	// 	if stopLoop {
	// 		break
	// 	}
	// }

	return possibleCubes
}

// func (cube *Cube3x3) moveUpNew(clockwise bool, cubeToMove []Cubie, c chan []Cubie) {

// 	// UP
// 	tmpCube := cube.moveFace(3, clockwise, cubeToMove)

// 	if clockwise {
// 		// LEFT, FRONT, RIGHT
// 		for cubie := 36; cubie < 45; cubie++ {
// 			tmpCube[cubie] = cubeToMove[cubie+3]
// 		}

// 		// BACK
// 		tmpCube[45] = cubeToMove[36]
// 		tmpCube[46] = cubeToMove[37]
// 		tmpCube[47] = cubeToMove[38]
// 	} else {

// 		// LEFT
// 		tmpCube[36] = cubeToMove[45]
// 		tmpCube[37] = cubeToMove[46]
// 		tmpCube[38] = cubeToMove[47]

// 		// FRONT, RIGHT, BACK
// 		for cubie := 39; cubie < 48; cubie++ {
// 			tmpCube[cubie] = cubeToMove[cubie-3]
// 		}
// 	}

// 	c <- tmpCube
// }

// func (cube *Cube3x3) moveDownNew(clockwise bool, cubeToMove []Cubie, c chan []Cubie) {

// 	// DOWN
// 	tmpCube := cube.moveFace(75, clockwise, cubeToMove)

// 	if clockwise {

// 		// LEFT
// 		tmpCube[60] = cubeToMove[69]
// 		tmpCube[61] = cubeToMove[70]
// 		tmpCube[62] = cubeToMove[71]

// 		// FRONT, RIGHT, BACK
// 		for cubie := 63; cubie < 72; cubie++ {
// 			tmpCube[cubie] = cubeToMove[cubie-3]
// 		}
// 	} else {

// 		// LEFT, FRONT, RIGHT
// 		for cubie := 60; cubie < 69; cubie++ {
// 			tmpCube[cubie] = cubeToMove[cubie+3]
// 		}

// 		// BACK
// 		tmpCube[69] = cubeToMove[60]
// 		tmpCube[70] = cubeToMove[61]
// 		tmpCube[71] = cubeToMove[62]
// 	}
// 	c <- tmpCube
// }

// func (cube *Cube3x3) moveRightNew(clockwise bool, cubeToMove []Cubie, c chan []Cubie) {

// 	// RIGHT
// 	tmpCube := cube.moveFace(42, clockwise, cubeToMove)

// 	if clockwise {

// 		// UP, FRONT
// 		for cubie := 5; cubie < 66; cubie += 12 {
// 			tmpCube[cubie] = cubeToMove[cubie+12*3]
// 		}

// 		// DOWN
// 		tmpCube[77] = cubeToMove[69]
// 		tmpCube[89] = cubeToMove[57]
// 		tmpCube[101] = cubeToMove[45]

// 		// BACK
// 		tmpCube[45] = cubeToMove[29]
// 		tmpCube[57] = cubeToMove[17]
// 		tmpCube[69] = cubeToMove[5]
// 	} else {

// 		// UP
// 		tmpCube[5] = cubeToMove[69]
// 		tmpCube[17] = cubeToMove[57]
// 		tmpCube[29] = cubeToMove[45]

// 		// FRONT, DOWN
// 		for cubie := 41; cubie < 102; cubie += 12 {
// 			tmpCube[cubie] = cubeToMove[cubie-12*3]
// 		}

// 		// BACK
// 		tmpCube[45] = cubeToMove[101]
// 		tmpCube[57] = cubeToMove[89]
// 		tmpCube[69] = cubeToMove[77]
// 	}

// 	c <- tmpCube
// }

// func (cube *Cube3x3) moveLeftNew(clockwise bool, cubeToMove []Cubie, c chan []Cubie) {

// 	// LEFT
// 	tmpCube := cube.moveFace(36, clockwise, cubeToMove)

// 	if clockwise {

// 		// UP
// 		tmpCube[3] = cubeToMove[71]
// 		tmpCube[15] = cubeToMove[59]
// 		tmpCube[27] = cubeToMove[47]

// 		// FRONT, DOWN
// 		for cubie := 39; cubie < 100; cubie += 12 {
// 			tmpCube[cubie] = cubeToMove[cubie-12*3]
// 		}

// 		// BACK
// 		tmpCube[47] = cubeToMove[99]
// 		tmpCube[59] = cubeToMove[87]
// 		tmpCube[71] = cubeToMove[75]
// 	} else {

// 		// UP, FRONT
// 		for cubie := 3; cubie < 64; cubie += 12 {
// 			tmpCube[cubie] = cubeToMove[cubie+12*3]
// 		}

// 		// DOWN
// 		tmpCube[75] = cubeToMove[71]
// 		tmpCube[87] = cubeToMove[59]
// 		tmpCube[99] = cubeToMove[47]

// 		// BACK
// 		tmpCube[47] = cubeToMove[27]
// 		tmpCube[59] = cubeToMove[15]
// 		tmpCube[71] = cubeToMove[3]
// 	}

// 	c <- tmpCube
// }

// func (cube *Cube3x3) moveFrontNew(clockwise bool, cubeToMove []Cubie, c chan []Cubie) {

// 	// FRONT
// 	tmpCube := cube.moveFace(39, clockwise, cubeToMove)

// 	if clockwise {

// 		// UP
// 		tmpCube[27] = cubeToMove[62]
// 		tmpCube[28] = cubeToMove[50]
// 		tmpCube[29] = cubeToMove[38]

// 		// LEFT
// 		tmpCube[38] = cubeToMove[75]
// 		tmpCube[50] = cubeToMove[76]
// 		tmpCube[62] = cubeToMove[77]

// 		// RIGHT
// 		tmpCube[42] = cubeToMove[27]
// 		tmpCube[54] = cubeToMove[28]
// 		tmpCube[66] = cubeToMove[29]

// 		// DOWN
// 		tmpCube[75] = cubeToMove[66]
// 		tmpCube[76] = cubeToMove[54]
// 		tmpCube[77] = cubeToMove[42]
// 	} else {

// 		// UP
// 		tmpCube[27] = cubeToMove[42]
// 		tmpCube[28] = cubeToMove[54]
// 		tmpCube[29] = cubeToMove[66]

// 		// LEFT
// 		tmpCube[38] = cubeToMove[29]
// 		tmpCube[50] = cubeToMove[28]
// 		tmpCube[62] = cubeToMove[27]

// 		// RIGHT
// 		tmpCube[42] = cubeToMove[77]
// 		tmpCube[54] = cubeToMove[76]
// 		tmpCube[66] = cubeToMove[75]

// 		// DOWN
// 		tmpCube[75] = cubeToMove[38]
// 		tmpCube[76] = cubeToMove[50]
// 		tmpCube[77] = cubeToMove[62]
// 	}
// 	c <- tmpCube
// }

// func (cube *Cube3x3) moveBackNew(clockwise bool, cubeToMove []Cubie, c chan []Cubie) {

// 	// BACK
// 	tmpCube := cube.moveFace(45, clockwise, cubeToMove)

// 	if clockwise {

// 		// UP
// 		tmpCube[3] = cubeToMove[44]
// 		tmpCube[4] = cubeToMove[56]
// 		tmpCube[5] = cubeToMove[68]

// 		// LEFT
// 		tmpCube[36] = cubeToMove[5]
// 		tmpCube[48] = cubeToMove[4]
// 		tmpCube[60] = cubeToMove[3]

// 		// RIGHT
// 		tmpCube[44] = cubeToMove[101]
// 		tmpCube[56] = cubeToMove[100]
// 		tmpCube[68] = cubeToMove[99]

// 		// DOWN
// 		tmpCube[99] = cubeToMove[36]
// 		tmpCube[100] = cubeToMove[48]
// 		tmpCube[101] = cubeToMove[60]
// 	} else {

// 		// UP
// 		tmpCube[3] = cubeToMove[60]
// 		tmpCube[4] = cubeToMove[48]
// 		tmpCube[5] = cubeToMove[36]

// 		// LEFT
// 		tmpCube[36] = cubeToMove[99]
// 		tmpCube[48] = cubeToMove[100]
// 		tmpCube[60] = cubeToMove[101]

// 		// RIGHT
// 		tmpCube[44] = cubeToMove[3]
// 		tmpCube[56] = cubeToMove[4]
// 		tmpCube[68] = cubeToMove[5]

// 		// DOWN
// 		tmpCube[99] = cubeToMove[68]
// 		tmpCube[100] = cubeToMove[56]
// 		tmpCube[101] = cubeToMove[44]
// 	}
// 	c <- tmpCube
// }
