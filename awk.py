#Input is : python awk.py intxt "$1 $2 $3"
#Input is : python awk.py -stdin "$1 $2 $3"

import sys

def parseInput():
	av = sys.argv
	ac = len(av)
	if ac != 3: exit()
	if av[1] == '-stdin':
		inTxt = [line.split(' ') for line in sys.stdin][0]
	else:
		inTxt = av[1].split()
	print(inTxt)
	inTxt = [part.replace('\n', '') for part in inTxt]
	idx = av[2].split(' ')
	#print(inTxt)
	#idx = av[1].split(' ')
	print(idx)
	idx = [i for i in idx if len(i)]
	print(idx)
	idx = [int(i[1:]) for i in idx if i[0] == '.']
	print(idx)
	output = av[2]
	for i in idx: output = output.replace(f".{i}", inTxt[i - 1])
	print("Final Output:", output)


def printOutput(): pass
def saveOutput(): pass
def main():
	parseInput()
	printOutput()
	saveOutput()
if __name__ == '__main__': main()
