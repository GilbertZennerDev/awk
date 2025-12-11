#include "header.h"

bool	ft_isnumeric(char c)
{
	return (c >= '0' && c <= '9');
}

unsigned int	ft_get_arr_lenght(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
		++i;
	return (i);
}

void	ft_malloc_sarray(char ***sl, unsigned int words)
{
	unsigned int	i;

	i = 0;
	(*sl) = (char **)malloc(sizeof(char *) * (words + 1));
	while (i < words)
		(*sl)[i++] = (char *)malloc(1024);
	(*sl)[i] = NULL;
}

void	ft_split_line(char ***sl, char buffer[],\
		char splitter, unsigned int words)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (buffer[i])
	{
		if (buffer[i] == splitter)
		{
			++j;
			(*sl)[j][k] = 0;
			k = 0;
		}
		else
		{
			(*sl)[j][k] = buffer[i];
			++k;
		}
		++i;
	}
}

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

