/*
#Input is : python awk.py intxt "$1 $2 $3"
#Input is : python awk.py -stdin "$1 $2 $3"
*/

#include "header.h"

int	main(int ac, char **av)
{
	unsigned int	i;
	int		*idx;
	char		**in_txt;
	unsigned int	count_idx;
	unsigned int	count_words;
	std::vector<int>		idx_v;
	std::vector<std::string>	in_txt_v;


	if (ac != 3)
		return (1);
	in_txt = get_in_txt(av);
	count_words = ft_get_arr_lenght(in_txt);
	idx = get_idx(av, &count_idx);
	get_output(idx, count_idx, in_txt, count_words);
	i = 0;
	while (i < count_idx)
		free(in_txt[i++]);
	free(idx);
	free(in_txt);
	return (0);
}
