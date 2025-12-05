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
	unsigned int	count_words;

	if (ac != 3)
		return (1);
	in_txt = get_in_txt(av);
	count_words = ft_get_arr_lenght(in_txt);
	idx = get_idx(av, &count_idx);
	get_output(idx, count_idx, in_txt, count_words);
	return (0);
}
