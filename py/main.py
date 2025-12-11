#Input is : python awk.py intxt "$1 $2 $3"
#Input is : python awk.py -stdin "$1 $2 $3"
#Input is : python awk.py -stdin "$1:$3" = $1 $2 $3

import sys

def getAvAc():
	return sys.argv, len(sys.argv) 

def getInTxt(av):
	if av[1][0] == '-':
		if av[1] == '-stdin':
			inTxt = [line.split(' ') for line in sys.stdin][0]
		else:
			try: inTxt = open(av[1][1:], "r").read().split(' ')
			except Exception as e: print(e); exit()
	else:
		inTxt = av[1].split()
	return [part.replace('\n', '') for part in inTxt]

def getIdx(av):
	if ':' in av[2]:
		idx = av[2].split(':')
		idx_0 = int(idx[0][idx[0].index('.') + 1:])
		idx_1 = int(idx[1][idx[0].index('.') + 1:])
		start = min(idx_0, idx_1)
		end = max(idx_0, idx_1)
		print(idx_0, idx_1)
		idx = [i for i in range(start, end + 1)]
		print(idx)
		return (idx)
	else:
		idx = av[2].split(' ')
		idx = [i for i in idx if len(i)]
		return [int(i[1:]) for i in idx if i[0] == '.']

def getOutput(idx, av, inTxt):
	if ':' in av[2]:
		output = ""
		for i in idx:
			output += inTxt[i - 1]
	else:
		output = av[2]
		try:
			for i in idx: output = output.replace(f".{i}", inTxt[i - 1])
		except Exception as e: print(e); exit()
	return output

def main():
	av, ac = getAvAc()
	if ac != 3: exit()
	inTxt = getInTxt(av)
	idx = getIdx(av)
	output = getOutput(idx, av, inTxt)
	print("Final Output:", output)

if __name__ == '__main__': main()
