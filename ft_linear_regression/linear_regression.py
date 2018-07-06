#!/usr/bin/python3

def normalise(mileages, prices):
	minPrice = min(prices)
	maxPrice = max(prices)
	minMileage = min(mileages)
	maxMileage = max(mileages)
	for i in range(len(mileages)):
		mileages[i] = (mileages[i] - minMileage) / (maxMileage - minMileage)
		prices[i] = (prices[i] - minPrice) / (maxPrice - minPrice)
		# print(mileages, prices)
	return mileages, prices


def denormalize(mileages, prices, theta0, theta1):
	maxPrice = max(prices)
	minPrice = min(prices)
	maxMileage = max(mileages)
	minMileage = min(mileages)
	thetaf0 = minPrice + (maxPrice - minPrice) * (theta0 - theta1 * minMileage / (maxMileage-minMileage))
	thetaf1 = (maxPrice - minPrice) * theta1 / (maxMileage - minMileage)
	thetaFile = open("theta1.txt", 'w')
	thetaFile.write(str(thetaf1))
	thetaFile.close()
	thetaFile = open("theta0.txt", 'w')
	thetaFile.write(str(thetaf0))
	thetaFile.close()
	return thetaf0, thetaf1

def estimatePrice(mileage, theta0, theta1):
	return theta0 + (theta1 * float(mileage))

def gradientDescent(mileages_orig, prices_orig, mileages, prices, iters = 1000):

	m = len(mileages)
	learningRate = 0.1
	theta0 = 0.0
	theta1 = 0.0

	for iter in range(iters):
		tmpTheta0 = theta0 - learningRate * sum(estimatePrice(mileages[i], theta0, theta1) - prices[i] for i in range(m)) / m
		tmpTheta1 = theta1 - learningRate * sum((estimatePrice(mileages[i], theta0, theta1) - prices[i]) * mileages[i] for i in range(m)) / m

		theta0 = tmpTheta0
		theta1 = tmpTheta1

	denormalize(mileages_orig, prices_orig, theta0, theta1)

if __name__ == "__main__":
	
	dataFile = None

	try:
		dataFile = open("data.csv", "r")
	except:
		print("Can't open file data.csv")
		exit()
	finally:
		nbLine = 0
		mileages = []
		prices = []
		for line in dataFile:
			if nbLine != 0:
				line = line[:-1]
				splittedLine = line.split(',')
				try:
					mileages.append(float(splittedLine[0]))
					prices.append(float(splittedLine[1]))
				except:
					print("One entry of data is not a number")
					exit()
			nbLine += 1

		mileages_orig = mileages.copy()
		prices_orig = prices.copy()
		mileages, prices = normalise(mileages, prices)

		gradientDescent(mileages_orig, prices_orig, mileages, prices)

		if dataFile is not None:
			dataFile.close()
		else:
			print("Can't close file data.csv")