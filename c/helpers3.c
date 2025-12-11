#include "header.h"

char	**ft_cleanidx(char **idx1, unsigned int countCleanIdx,\
		unsigned int words)
{
	char	**cleaned;

	ft_malloc_sarray(&cleaned, countCleanIdx);
	ft_copy_cleanidx(&cleaned, idx1, words, countCleanIdx);
	return (cleaned);
}

void	ft_count_clean_idx(unsigned int *count_clean_idx,\
		unsigned int words, char **idx1)
{
	unsigned int	i;

	i = 0;
	(*count_clean_idx) = 0;
	while (i < words)
	{
		if (idx1[i][0] == '.')
			++(*count_clean_idx);
		++i;
	}
}
