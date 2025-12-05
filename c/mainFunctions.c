#include "header.h"

char	**get_in_txt(char **av)
{
	int		fd;
	int		bytes_read;
	char	buffer[1024];

	if (av[1][0] == '-')
	{
		fd = 0;
		if (strcmp(av[1], "-stdin") != 0)
			fd = open("file", O_RDONLY);
		bytes_read = read(fd, buffer, 1023);
		if (bytes_read < 0)
			exit(1);
		if (fd)
			close(fd);
		buffer[1023] = 0;
		return (ft_splittedline(buffer, ' '));
	}
	return (ft_splittedline(av[1], ' '));
}

int	*ft_getnbrs(char **cleaned, unsigned int words)
{
	unsigned int	i;
	int				*idx_nbrs;

	i = 0;
	idx_nbrs = malloc(sizeof(int) * 10);
	while (i < words)
	{
		idx_nbrs[i] = atoi(cleaned[i]);
		++i;
	}
	return (idx_nbrs);
}

int	*get_idx(char **av, unsigned int *countIdx)
{
	unsigned int	words;
	char			**idx1;
	char			**cleanidx1;

	ft_count_words(av[2], &words, ' ');
	idx1 = ft_splittedline(av[2], ' ');
	ft_count_clean_idx(countIdx, words, idx1);
	cleanidx1 = ft_cleanidx(idx1, *countIdx, words);
	return (ft_getnbrs(cleanidx1, words));
}

void	get_output(int *idx_nbrs, unsigned int count_idx, \
char **in_txt, unsigned int count_words)
{
	unsigned int	i;

	i = 0;
	while (i < count_idx)
	{
		if (i < count_words)
			printf("%s ", in_txt[idx_nbrs[i] - 1]);
		++i;
	}
	printf("\n");
}
