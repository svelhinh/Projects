import os
nb = 123456
nb_max = 654321
while nb <= nb_max:
	nbStr = ' '.join(str(nb))
	if nbStr.count('1') == 1 and nbStr.count('2') == 1 and nbStr.count('3') == 1 and nbStr.count('4') == 1 and nbStr.count('5') == 1 and nbStr.count('6') == 1:
		os.system("echo 'Public speaking is very easy.\n1 2 6 24 120 720\n0 q 777\n9\n/ %+-!\n" + nbStr + "' > toto && echo '" + str(nb) + "' && ./bomb toto")
	nb += 1