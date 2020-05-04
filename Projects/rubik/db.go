package main

import (
	"fmt"
	"os"
)

func loadDBCorners() {
	f, err := os.Open("databaseCorners")
	if err != nil {
		generateDb = true
	}

	if !generateDb {
		var error error
		var i int
		for error == nil {
			var databaseTmp [108]byte
			n, err2 := f.Read(databaseTmp[:])
			error = err2
			databaseTmp2 := make([]Cubie, 0)
			for _, data := range databaseTmp {
				databaseTmp2 = append(databaseTmp2, Cubie(data))
			}
			databaseCorners = append(databaseCorners, databaseTmp2[:])
			_ = n
			var databaseTmp3 [1]byte
			n, error = f.Read(databaseTmp3[:])
			if i == 2 {
				fmt.Println(databaseTmp3)
			}
			i++
			databaseScoresCorners = append(databaseScoresCorners, databaseTmp3[0])
		}
		fmt.Println(databaseCorners)
	}
}

func saveDBCorners(cube *Cube3x3) {
	generateDBCorners(cube)
	f, err := os.Create("databaseCorners")
	if err != nil {
		panic(err)
	}
	defer f.Close()

	for dataI, data := range databaseCorners {
		databaseTmp := make([]byte, 0)
		for _, cubie := range data {
			databaseTmp = append(databaseTmp, byte(cubie))
		}
		n, err := f.Write(databaseTmp)
		if err != nil {
			panic(err)
		}
		n2, err2 := f.Write(databaseScoresCorners[dataI : dataI+1])
		_, _ = n, n2
		if err2 != nil {
			panic(err2)
		}
	}
}

func loadDBHalf() {
	f, err := os.Open("databaseHalf")
	if err != nil {
		generateDb = true
	}

	if !generateDb {
		var error error
		var i int
		for error == nil {
			var databaseTmp [108]byte
			n, err2 := f.Read(databaseTmp[:])
			error = err2
			databaseTmp2 := make([]Cubie, 0)
			for _, data := range databaseTmp {
				databaseTmp2 = append(databaseTmp2, Cubie(data))
			}
			databaseHalf = append(databaseHalf, databaseTmp2[:])
			_ = n
			var databaseTmp3 [1]byte
			n, error = f.Read(databaseTmp3[:])
			if i == 2 {
				fmt.Println(databaseTmp3)
			}
			i++
			databaseScoresHalf = append(databaseScoresHalf, databaseTmp3[0])
		}
	}
}

func saveDBHalf(cube *Cube3x3) {
	generateDBHalf(cube)
	f, err := os.Create("databaseHalf")
	if err != nil {
		panic(err)
	}
	defer f.Close()

	for dataI, data := range databaseHalf {
		databaseTmp := make([]byte, 0)
		for _, cubie := range data {
			databaseTmp = append(databaseTmp, byte(cubie))
		}
		n, err := f.Write(databaseTmp)
		if err != nil {
			panic(err)
		}
		n2, err2 := f.Write(databaseScoresHalf[dataI : dataI+1])
		_, _ = n, n2
		if err2 != nil {
			panic(err2)
		}
	}
}

func loadDBRest() {
	f, err := os.Open("databaseRest")
	if err != nil {
		generateDb = true
	}

	if !generateDb {
		var error error
		var i int
		for error == nil {
			var databaseTmp [108]byte
			n, err2 := f.Read(databaseTmp[:])
			error = err2
			databaseTmp2 := make([]Cubie, 0)
			for _, data := range databaseTmp {
				databaseTmp2 = append(databaseTmp2, Cubie(data))
			}
			databaseRest = append(databaseRest, databaseTmp2[:])
			_ = n
			var databaseTmp3 [1]byte
			n, error = f.Read(databaseTmp3[:])
			if i == 2 {
				fmt.Println(databaseTmp3)
			}
			i++
			databaseScoresRest = append(databaseScoresRest, databaseTmp3[0])
		}
	}
}

func saveDBRest(cube *Cube3x3) {
	generateDBRest(cube)
	f, err := os.Create("databaseRest")
	if err != nil {
		panic(err)
	}
	defer f.Close()

	for dataI, data := range databaseRest {
		databaseTmp := make([]byte, 0)
		for _, cubie := range data {
			databaseTmp = append(databaseTmp, byte(cubie))
		}
		n, err := f.Write(databaseTmp)
		if err != nil {
			panic(err)
		}
		n2, err2 := f.Write(databaseScoresRest[dataI : dataI+1])
		_, _ = n, n2
		if err2 != nil {
			panic(err2)
		}
	}
}
