#Input is : python awk.py intxt "$1 $2 $3"
#Input is : python awk.py -stdin "$1 $2 $3"

import sys

def getAvAc():
	return sys.argv, len(sys.argv) 

def getInTxt(av):
	if av[1] == '-stdin':
		inTxt = [line.split(' ') for line in sys.stdin][0]
	else:
		inTxt = av[1].split()
	return [part.replace('\n', '') for part in inTxt]

def getIdx(av):
	idx = av[2].split(' ')
	idx = [i for i in idx if len(i)]
	return [int(i[1:]) for i in idx if i[0] == '.']

def getOutput(idx, av, inTxt):
	output = av[2]
	for i in idx: output = output.replace(f".{i}", inTxt[i - 1])
	return output

def main():
	av, ac = getAvAc()
	if ac != 3: exit()
	inTxt = getInTxt(av)
	idx = getIdx(av)
	output = getOutput(idx, av, inTxt)
	print("Final Output:", output)

if __name__ == '__main__': main()
