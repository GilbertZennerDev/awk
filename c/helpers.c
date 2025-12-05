#include "header.h"

bool ft_isnumeric(char c)
{
	return (c >= '0' && c <= '9');
}

void ft_malloc_sarray(char ***sl, unsigned int 	words)
{
	unsigned int 	i;

	(*sl) = malloc(sizeof(char *) * words);
	i = 0;
	while (i < words)
		(*sl)[i++] = malloc(1024);
}

void 	ft_split_line(char ***sl, char buffer[], char splitter, unsigned int 	words)
{
	unsigned int 	i;
	unsigned int 	j;
	unsigned int 	k;

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

