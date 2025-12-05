#include "header.h"

char **getInTxt(char **av)
{
	int fd;
	int bytes_read;
	char buffer[1024];

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

int *ft_getnbrs(char **cleaned, unsigned int words)
{
	unsigned int	i;
	int		*idx_nbrs;

	i = 0;
	idx_nbrs = malloc(sizeof(int) * 10);
	while (i < words)
	{
		idx_nbrs[i] = atoi(cleaned[i]);
		++i;
	}
	return (idx_nbrs);
}

int *getIdx(char **av, unsigned int *countIdx)
{
	unsigned int 	words;
	char		**idx1;
	char		**cleanidx1;
	unsigned int	countCleanIdx;

	ft_countWords(av[2], &words, ' ');
	idx1 = ft_splittedline(av[2], ' ');
	ft_countCleanIdx(countIdx, words, idx1);
	cleanidx1 = ft_cleanidx(idx1, *countIdx, words);

	return (ft_getnbrs(cleanidx1, words));
}

void getOutput(int *idx_nbrs, unsigned int countIdx, char **inTxt)
{
	unsigned int	i;

	i = 0;
	while (i < countIdx)
		printf("%s ", inTxt[idx_nbrs[i++] - 1]);
	printf("\n");
}

