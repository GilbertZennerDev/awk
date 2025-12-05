/*
#Input is : python awk.py intxt "$1 $2 $3"
#Input is : python awk.py -stdin "$1 $2 $3"
*/

#include "header.hpp"

int main(int ac, char **av)
{
	int *idx;
	char **inTxt;
	unsigned int countIdx;
	
	if (ac != 3)
		return (1);

	inTxt = getInTxt(av);
	idx = getIdx(av, &countIdx);
	getOutput(idx, countIdx, inTxt);
	return (0);
}
