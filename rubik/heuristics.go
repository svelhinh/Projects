/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristics.go                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:59:37 by svelhinh          #+#    #+#             */
/*   Updated: 2018/04/18 20:27:07 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

package main

import "math"

// func calcul(goalI int, faces []CubieInfo, cubieGoal Cubie, cube []Cubie, c chan int) {
// 	goalPt := get3dPositionOfCubie(goalI, faces)
// 	cubiePt := get3dPositionOfCubie(indexOf(cubieGoal, cube), faces)

// 	c <- int(math.Abs(float64(goalPt.x-cubiePt.x)) + math.Abs(float64(goalPt.y-cubiePt.y)) + math.Abs(float64(goalPt.z-cubiePt.z)))
// }

func manhattanDistance3D(goal []Cubie, cube []Cubie, faces [][]int /*, goalNumber int8*/) int {

	// c := make(chan int, len(goal))
	// var corners int

	// goalI := 3
	// cubieI := indexOf(goal[goalI], cube)
	// corners += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// goalI = 5
	// cubieI = indexOf(goal[goalI], cube)
	// corners += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// goalI = 27
	// cubieI = indexOf(goal[goalI], cube)
	// corners += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// goalI = 29
	// cubieI = indexOf(goal[goalI], cube)
	// corners += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// goalI = 75
	// cubieI = indexOf(goal[goalI], cube)
	// corners += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// goalI = 77
	// cubieI = indexOf(goal[goalI], cube)
	// corners += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// goalI = 99
	// cubieI = indexOf(goal[goalI], cube)
	// corners += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// goalI = 101
	// cubieI = indexOf(goal[goalI], cube)
	// corners += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// max := corners

	// var half int

	// goalI = 4
	// cubieI = indexOf(goal[goalI], cube)
	// half += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// goalI = 15
	// cubieI = indexOf(goal[goalI], cube)
	// half += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// goalI = 17
	// cubieI = indexOf(goal[goalI], cube)
	// half += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// goalI = 28
	// cubieI = indexOf(goal[goalI], cube)
	// half += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// goalI = 48
	// cubieI = indexOf(goal[goalI], cube)
	// half += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// goalI = 50
	// cubieI = indexOf(goal[goalI], cube)
	// half += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// if half > max {
	// 	max = half
	// }

	// var rest int

	// goalI = 53
	// cubieI = indexOf(goal[goalI], cube)
	// rest += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// goalI = 56
	// cubieI = indexOf(goal[goalI], cube)
	// rest += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// goalI = 76
	// cubieI = indexOf(goal[goalI], cube)
	// rest += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// goalI = 87
	// cubieI = indexOf(goal[goalI], cube)
	// rest += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// goalI = 89
	// cubieI = indexOf(goal[goalI], cube)
	// rest += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// goalI = 100
	// cubieI = indexOf(goal[goalI], cube)
	// rest += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	// if rest > max {
	// 	max = rest
	// }

	// return max

	// var finalResult int

	/*switch goalNumber {
	case 0:*/
	/*goalPtX, goalPtY, goalPtZ := get3dPositionOfCubie(1, faces)
	cubiePtX, cubiePtY, cubiePtZ := get3dPositionOfCubie(indexOf(goal[1], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(3, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[3], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(7, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[7], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(9, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[9], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(10, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[10], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(12, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[12], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(16, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[16], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(18, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[18], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(19, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[19], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(21, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[21], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(25, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[25], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(27, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[27], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(28, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[28], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(30, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[30], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(34, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[34], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(36, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[36], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(37, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[37], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(39, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[39], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(43, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[43], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(45, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[45], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(46, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[46], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(48, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[48], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(52, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[52], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(54, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[54], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	/*goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(48, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[48], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(52, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[52], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))

	goalPtX, goalPtY, goalPtZ = get3dPositionOfCubie(54, faces)
	cubiePtX, cubiePtY, cubiePtZ = get3dPositionOfCubie(indexOf(goal[54], cube), faces)
	finalResult += int(math.Abs(float64(goalPtX-cubiePtX)) + math.Abs(float64(goalPtY-cubiePtY)) + math.Abs(float64(goalPtZ-cubiePtZ)))*/
	//break
	/*case 1:
	break*/
	//}

	// if generateDb {

	// var finalResult int

	// // j := 0
	// for goalI, cubieGoal := range goal {
	// 	if /*goalI == 3 || goalI == 5 || goalI == 27 || goalI == 29 || goalI == 75 || goalI == 77 || goalI == 99 || goalI == 101 */ cubieGoal == 0 || cubieGoal == 5 || cubieGoal == 14 || cubieGoal == 23 || cubieGoal == 32 || cubieGoal == 41 || cubieGoal == 50 {
	// 		continue
	// 	}
	// 	// var goalPt Vector3
	// 	// var cubiePt Vector3
	// 	// var goalFound bool
	// 	// var cubieFound bool

	// 	// cubieI := indexOf(cubieGoal, cube)

	// 	// for _, cubieInfo := range faces {
	// 	// 	if !goalFound && goalI == cubieInfo.index {
	// 	// 		goalPt = cubieInfo.pos
	// 	// 		if cubieFound {
	// 	// 			break
	// 	// 		}
	// 	// 		goalFound = true
	// 	// 	}
	// 	// 	if !cubieFound && cubieI == cubieInfo.index {
	// 	// 		cubiePt = cubieInfo.pos
	// 	// 		if goalFound {
	// 	// 			break
	// 	// 		}
	// 	// 		cubieFound = true
	// 	// 	}
	// 	// }
	// 	// cubieI := indexOf(cubieGoal, cube)
	// 	for cubieI := range cube {
	// 		if cube[cubieI] == cubieGoal {
	// 			finalResult += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))
	// 			break
	// 		}
	// 	}
	// 	// }

	// 	// go calcul(goalI, faces, cubieGoal, cube, c)
	// 	// j++
	// }

	// // 	if !contains(database, cube) {
	// // 		database = append(database, cube)
	// // 		databaseScores = append(databaseScores, byte(finalResult/8))
	// // 		// fmt.Println("toto")
	// // 	}
	// return finalResult / 8
	// }

	var max int

	for dataI, data := range databaseCorners {
		isEqual := true
		if data[3] != cube[3] || data[5] != cube[5] || data[27] != cube[27] || data[29] != cube[29] || data[75] != cube[75] || data[77] != cube[77] || data[99] != cube[99] || data[101] != cube[101] {
			isEqual = false
		}
		if isEqual {
			max = int(databaseScoresCorners[dataI])
			break
		}
	}

	for dataI, data := range databaseHalf {
		isEqual := true
		if data[4] != cube[4] || data[15] != cube[15] || data[17] != cube[17] || data[28] != cube[28] || data[48] != cube[48] || data[50] != cube[50] {
			isEqual = false
		}
		if isEqual {
			if int(databaseScoresHalf[dataI]) > max {
				max = int(databaseScoresHalf[dataI])
			}
			break
		}
	}

	for dataI, data := range databaseRest {
		isEqual := true
		if data[53] != cube[53] || data[56] != cube[56] || data[76] != cube[76] || data[87] != cube[87] || data[89] != cube[89] || data[100] != cube[100] {
			isEqual = false
		}
		if isEqual {
			if int(databaseScoresRest[dataI]) > max {
				max = int(databaseScoresRest[dataI])
			}
			break
		}
	}

	return max

	// return 0

	// finalResult /= 4

	// var finalResult2 int

	// for goalI, cubieGoal := range goal {
	// 	if goalI == 4 || goalI == 15 || goalI == 17 || goalI == 28 || goalI == 48 || goalI == 50 || goalI == 53 || goalI == 56 || goalI == 76 || goalI == 87 || goalI == 89 || goalI == 100 {
	// 		for cubieI := range cube {
	// 			if cube[cubieI] == cubieGoal {
	// 				finalResult += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))
	// 				break
	// 			}
	// 		}
	// 	}
	// }

	// finalResult2 /= 4

	// return finalResult + finalResult2

	// return finalResult / 8
}

func manhattanDistance3DCorners(goal []Cubie, cube []Cubie, faces [][]int) int {

	var corners int

	goalI := 3
	cubieI := indexOf(goal[goalI], cube)
	corners += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	goalI = 5
	cubieI = indexOf(goal[goalI], cube)
	corners += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	goalI = 27
	cubieI = indexOf(goal[goalI], cube)
	corners += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	goalI = 29
	cubieI = indexOf(goal[goalI], cube)
	corners += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	goalI = 75
	cubieI = indexOf(goal[goalI], cube)
	corners += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	goalI = 77
	cubieI = indexOf(goal[goalI], cube)
	corners += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	goalI = 99
	cubieI = indexOf(goal[goalI], cube)
	corners += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	goalI = 101
	cubieI = indexOf(goal[goalI], cube)
	corners += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))
	return corners
}

func manhattanDistance3DHalf(goal []Cubie, cube []Cubie, faces [][]int) int {

	var half int

	goalI := 4
	cubieI := indexOf(goal[goalI], cube)
	half += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	goalI = 15
	cubieI = indexOf(goal[goalI], cube)
	half += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	goalI = 17
	cubieI = indexOf(goal[goalI], cube)
	half += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	goalI = 28
	cubieI = indexOf(goal[goalI], cube)
	half += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	goalI = 48
	cubieI = indexOf(goal[goalI], cube)
	half += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	goalI = 50
	cubieI = indexOf(goal[goalI], cube)
	half += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))
	return half
}

func manhattanDistance3DRest(goal []Cubie, cube []Cubie, faces [][]int) int {

	var rest int

	goalI := 53
	cubieI := indexOf(goal[goalI], cube)
	rest += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	goalI = 56
	cubieI = indexOf(goal[goalI], cube)
	rest += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	goalI = 76
	cubieI = indexOf(goal[goalI], cube)
	rest += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	goalI = 87
	cubieI = indexOf(goal[goalI], cube)
	rest += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	goalI = 89
	cubieI = indexOf(goal[goalI], cube)
	rest += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))

	goalI = 100
	cubieI = indexOf(goal[goalI], cube)
	rest += int(math.Abs(float64(faces[goalI][0]-faces[cubieI][0])) + math.Abs(float64(faces[goalI][1]-faces[cubieI][1])) + math.Abs(float64(faces[goalI][2]-faces[cubieI][2])))
	return rest
}
