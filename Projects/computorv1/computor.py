def squareroot(x):
	a = 1
	b = x
	while True:
		a = (a + b) / 2
		b = x / a
		if a - b <= .0000001:
			break
	return a

def resolve1st(coeffs):
	a = coeffs[1]
	b = coeffs[0]
	return x

def resolve2nd(coeffs):
	a = coeffs[2]
	b = coeffs[1]
	c = coeffs[0]
	delta = b * b - 4 * a * c

	x = []
	if delta > 0:
		x.append((-b + squareroot(delta)) / (2 * a))
		x.append((-b - squareroot(delta)) / (2 * a))
	elif delta == 0:
		x.append(-b / (2 * a))
	return x

def roundFloat(nb):
	return "{:.6f}".format(nb).rstrip('0').rstrip('.')


import sys

if len(sys.argv) != 2:
	print("python3 computor [polynomial equation]")
	exit(1)

polynomial = -1
coeffs = []
equation = [x for x in sys.argv[1].split() if x != '*']

lastI = 0

# LEFT PART OF EQUATION
for i in range(1, len(equation)):
	if equation[i][0] == 'X':
		power = equation[i].split('^')
		if int(power[1]) > polynomial:
			coeffs += [0] * (int(power[1]) - polynomial)
			polynomial = int(power[1])
		coeffs[int(power[1])] += float(equation[i - 1]) if equation[i - 1].count('.') > 0 else int(equation[i - 1])
		if i - 2 >= 0 and equation[i - 2] == "-":
			coeffs[int(power[1])] = -coeffs[int(power[1])]
	if equation[i] == "=":
		lastI = i + 1
		break

# RIGHT PART OF EQUATION
for i in range(lastI, len(equation)):
	if equation[i][0] == 'X':
		power = equation[i].split('^')
		if int(power[1]) > polynomial:
			coeffs += [0] * (int(power[1]) - polynomial)
			polynomial = int(power[1])
		coeffs[int(power[1])] -= float(equation[i - 1]) if equation[i - 1].count('.') > 0 else int(equation[i - 1])
		if i - 2 >= 0 and equation[i - 2] == "-":
			coeffs[int(power[1])] = -coeffs[int(power[1])]

for i in range(len(coeffs)-1, -1, -1):
	if coeffs[i] == 0:
		coeffs.pop(i)
		polynomial -= 1
	else:
		break

if len(coeffs) == 0:
	print("Reduced form: 0 * X^0 = 0\nPolynomial degree: 0\nAll real numbers are solution")
	exit(0)

# RESOLUTION
allNb = False
x = []
if polynomial == 0:
	if coeffs[0] == 0:
		allNb = True
	else:
		x = None
elif polynomial == 1:
	x.append(-coeffs[0] / coeffs[1])
elif polynomial == 2:
	x = resolve2nd(coeffs)

# REDUCED FORM
reducedForm = "Reduced form: "
if coeffs[0] < 0:
	reducedForm += "- "
	coeffs[0] = -coeffs[0]
reducedForm += str(coeffs[0]) + " * X^0 "

for i in range(1, polynomial + 1):
	if coeffs[i] != 0:
		if coeffs[i] < 0:
			reducedForm += "- "
			coeffs[i] = -coeffs[i]
		else:
			reducedForm += "+ "
		reducedForm += str(coeffs[i]) + " * X^" + str(i) + " "

reducedForm += "= 0"


# PRINT
print(reducedForm)
print("Polynomial degree: " + str(polynomial))

if polynomial == 0:
	if allNb:
		print("All real numbers are solution")
	if x == None:
		print("This equation has no solution")
elif polynomial == 1:
	print("The solution is:\n" + roundFloat(x[0]))
elif polynomial == 2:
	lenX = len(x)
	if lenX == 0:
		print("Discriminant is negative, this equation has no solution")
	elif lenX == 1:
		print("Discriminant is equal to 0, the solution is:\n" + roundFloat(x[0]))
	else:
		print("Discriminant is strictly positive, the two solutions are:\n" + roundFloat(x[0]) + "\n" + roundFloat(x[1]))
else:
	print("The polynomial degree is stricly greater than 2, I can't solve.")