#include "header.h"

void	ft_count_words(char buffer[],\
		unsigned int *words, char splitter)
{
	unsigned int	i;

	i = 0;
	*words = 1;
	while (buffer[i])
	{
		if (buffer[i] == splitter && buffer[i + 1] && buffer[i + 1] != splitter)
			++(*words);
		++i;
	}
}

char	**ft_splittedline(char buffer[], char splitter)
{
	char			**sl;
	unsigned int	words;

	ft_count_words(buffer, &words, ' ');
	ft_malloc_sarray(&sl, words);
	ft_split_line(&sl, buffer, splitter, words);
	return (sl);
}

void	ft_copy_cleanidx(char ***cleaned, char **idx1,\
		unsigned int words, unsigned int countCleanIdx)
{
	t_ijkl	s;

	s.i = 0;
	s.j = 0;
	while (s.i < words && s.j < countCleanIdx)
	{
		s.k = 0;
		s.l = 0;
		if (idx1[s.i][0] != '.')
		{
			++s.i;
			continue ;
		}
		while (idx1[s.i][s.l])
		{
			if (ft_isnumeric(idx1[s.i][s.l]))
				(*cleaned)[s.j][s.k++] = idx1[s.i][s.l];
			++s.l;
		}
		(*cleaned)[s.j++][s.k] = 0;
		++s.i;
	}
}
