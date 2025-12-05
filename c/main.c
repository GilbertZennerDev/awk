/*
#Input is : python awk.py intxt "$1 $2 $3"
#Input is : python awk.py -stdin "$1 $2 $3"
*/

#include "header.h"

int	main(int ac, char **av)
{
	int				*idx;
	char			**in_txt;
	unsigned int	count_idx;

	if (ac != 3)
		return (1);
	in_txt = getInTxt(av);
	idx = getIdx(av, &count_idx);
	getOutput(idx, count_idx, in_txt);
	return (0);
}
