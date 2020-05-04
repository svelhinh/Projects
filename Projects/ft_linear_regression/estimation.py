#!/usr/bin/python3

def estimatePrice(mileage, theta0, theta1):
	return theta0 + (theta1 * mileage)

if __name__ == "__main__":
	
	import sys
	if len(sys.argv) == 2:
		try:
			mileage = float(sys.argv[1])
		except:
			print("This is not a mileage")
			exit()
		if mileage < 0:
			print("Your car can't have negative mileage")
			exit()

		theta0File = None
		theta1File = None

		try:
			theta0File = open("theta0.txt", "r")
			theta1File = open("theta1.txt", "r")
		except:
			print("Can't open file theta0.txt or theta1.txt")
			exit()
		finally:
			try:
				for line in theta0File:
					theta0 = float(line)
					break
				for line in theta1File:
					theta1 = float(line)
					break
			except:
				print("One of theta0 or theta1 is not a number")
				exit()

			print("Your car worth " + str(estimatePrice(mileage, theta0, theta1)))

			if theta0File is not None:
				theta0File.close()
			else:
				print("Can't close file data.csv")
	else:
		print("Please enter one mileage")