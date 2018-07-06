/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.go                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:59:40 by svelhinh          #+#    #+#             */
/*   Updated: 2018/04/19 16:02:56 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

package main

import (
	"fmt"
)

type Vector3 struct {
	x int
	y int
	z int
}

type Cubie int

// type CubieInfo struct {
// pos   Vector3
// 	index int
// }

func indexOf(item Cubie, slice []Cubie) int {
	for i := range slice {
		if slice[i] == item {
			return i
		}
	}
	return -1 // Not Found
}

func contains(cubieSlice [][]Cubie, searchCubie []Cubie) bool {
	for _, value := range cubieSlice {
		isEqual := true
		for cubieI := range value {
			if value[cubieI] != searchCubie[cubieI] {
				isEqual = false
				break
			}
		}
		if isEqual {
			return true
		}
	}
	return false
}

func containsCorners(cubieSlice [][]Cubie, searchCubie []Cubie) bool {
	for _, value := range cubieSlice {
		if value[3] != searchCubie[3] || value[5] != searchCubie[5] || value[27] != searchCubie[27] || value[29] != searchCubie[29] || value[75] != searchCubie[75] || value[77] != searchCubie[77] || value[99] != searchCubie[99] || value[101] != searchCubie[101] {
			// fmt.Println("yo")
			return false
		}
	}
	return true
}

func generateDBCorners(cube *Cube3x3) {
	s := make([][]Cubie, 0)
	v := make([]Cubie, cube.size)
	tmp := make([]Cubie, cube.size)

	s = append(s, cube.goal)
	var i int
	for len(s) > 0 {
		copy(v, s[len(s)-1])
		// if i <= 1 {
		// 	fmt.Println("V : ")
		// 	cube.printCube3x3(v, true, true)
		// 	if i == 1 {
		// 		fmt.Println("DB : ")
		// 		cube.printCube3x3(databaseCorners[len(databaseCorners)-1], true, true)
		// 	}
		// }
		s = append(s[:len(s)-1], s[len(s):]...)
		if !containsCorners(databaseCorners, v) || len(databaseCorners) == 0 {
			copy(tmp, v)
			databaseCorners = append(databaseCorners, tmp)
			databaseScoresCorners = append(databaseScoresCorners, byte(manhattanDistance3DCorners(cube.goal, v, faces3x3)))
			// fmt.Println(databaseCorners)
			for _, succ := range cube.successors(v) {
				s = append(s, succ)
			}
		}
		i++
		if i%1000000 == 0 {
			fmt.Println(i)
		}
		// if i == 0 {
		// 	fmt.Println(len(s))
		// }

		// databaseCorners = append(databaseCorners, s[len(s)-1])
		// databaseScoresCorners = append(databaseScoresCorners, byte(manhattanDistance3DCorners(cube.goal, cube.cube, faces3x3)))
		// s = append(s[:len(s)-1], s[len(s):]...)
		// if !containsCorners(databaseCorners, databaseCorners) {
		// 	for _, succ := range cube.successors(cube.cube) {
		// 		generateDBCorners(cube)
		// 	}
		// }
	}
}

func containsHalf(cubieSlice [][]Cubie, searchCubie []Cubie) bool {
	for _, value := range cubieSlice {
		isEqual := true
		if value[4] != searchCubie[4] || value[15] != searchCubie[15] || value[17] != searchCubie[17] || value[28] != searchCubie[28] || value[48] != searchCubie[48] || value[50] != searchCubie[50] {
			isEqual = false
			break
		}
		if isEqual {
			return true
		}
	}
	return false
}

func generateDBHalf(cube *Cube3x3) {
	s := make([][]Cubie, 0)
	v := make([]Cubie, cube.size)
	copy(v, cube.cube)

	s = append(s, v)
	for len(s) > 0 {
		v = s[len(s)-1]
		if !containsHalf(databaseCorners, v) {
			databaseCorners = append(databaseCorners, v)
			databaseScoresCorners = append(databaseScoresCorners, byte(manhattanDistance3DHalf(cube.goal, cube.cube, faces3x3)))
			for _, succ := range cube.successors(v) {
				s = append(s, succ)
			}
		}
	}

	// for _, succ := range cube.successors(cube.cube) {
	// 	if !containsHalf(databaseHalf, succ) {
	// 		databaseHalf = append(databaseHalf, succ)
	// 		databaseScoresHalf = append(databaseScoresHalf, byte(manhattanDistance3DHalf(cube.goal, cube.cube, faces3x3)))
	// 		generateDBHalf(cube)
	// 	}
	// }
}

func containsRest(cubieSlice [][]Cubie, searchCubie []Cubie) bool {
	for _, value := range cubieSlice {
		isEqual := true
		if value[53] != searchCubie[53] || value[56] != searchCubie[56] || value[76] != searchCubie[76] || value[87] != searchCubie[87] || value[89] != searchCubie[89] || value[100] != searchCubie[100] {
			isEqual = false
			break
		}
		if isEqual {
			return true
		}
	}
	return false
}

func generateDBRest(cube *Cube3x3) {
	s := make([][]Cubie, 0)
	v := make([]Cubie, cube.size)
	copy(v, cube.cube)

	s = append(s, v)
	for len(s) > 0 {
		v = s[len(s)-1]
		if !containsRest(databaseCorners, v) {
			databaseCorners = append(databaseCorners, v)
			databaseScoresCorners = append(databaseScoresCorners, byte(manhattanDistance3DRest(cube.goal, cube.cube, faces3x3)))
			for _, succ := range cube.successors(v) {
				s = append(s, succ)
			}
		}
	}

	// for _, succ := range cube.successors(cube.cube) {
	// 	if !containsRest(databaseRest, succ) {
	// 		databaseRest = append(databaseRest, succ)
	// 		databaseScoresRest = append(databaseScoresRest, byte(manhattanDistance3DRest(cube.goal, cube.cube, faces3x3)))
	// 		generateDBHalf(cube)
	// 	}
	// }
}
