/*
#Input is : python awk.py intxt "$1 $2 $3"
#Input is : python awk.py -stdin "$1 $2 $3"

import sys

def getAvAc():
	return sys.argv, len(sys.argv) 

def getInTxt(av):
	if av[1][0] == '-':
		if av[1] == '-stdin':
			inTxt = [line.split(' ') for line in sys.stdin][0]
		else:
			try: inTxt = open(av[1][1:], "r").read().split(' ')
			except Exception as e: print(e); exit()
	else:
		inTxt = av[1].split()
	return [part.replace('\n', '') for part in inTxt]
*/

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_countWords(char buffer[], unsigned int *words, char splitter)
{
	unsigned int i;
	
	i = 0;
	*words = 1;
	while (buffer[i])
	{
		if (buffer[i] == splitter)
		{
			++(*words);
		}
		++i;
	}
}

char **ft_splittedline(char buffer[], char splitter, unsigned int words)
{
	char **sl;
	unsigned int i;
	unsigned int j;
	unsigned int k;
	
	sl = malloc(sizeof(char *) * words);
	i = 0;
	while (i < words)
		sl[i++] = malloc(1024);
	i = 0;
	j = 0;
	k = 0;
	while (buffer[i])
	{
		if (buffer[i] == splitter)
		{
			++j;
			sl[j][k] = 0;
			k = 0;
		}
		else
		{
			sl[j][k] = buffer[i];
			++k;
		}
		++i;
	}
	return (sl);
}

char **getInTxt(char **av, unsigned int *words)
{
	int fd;
	int bytes_read;
	char buffer[1024];

	if (av[1][0] == '-')
	{
		if (strcmp(av[1], "-stdin") == 0)
		{
			bytes_read = read(0, buffer, 1023);
			buffer[1023] = 0;
		}
		else
		{
			fd = open("file", O_RDONLY); //will be fixed to be av[1][1:]
			bytes_read = read(fd, buffer, 1023);
			buffer[1023] = 0;
			close(fd);
		}
		ft_countWords(buffer, words, ' ');
		return (ft_splittedline(buffer, ' ', *words));
	}
	ft_countWords(av[1], words, ' ');
	printf("%d\n", *words);
	return (ft_splittedline(av[1], ' ', *words));
}

bool ft_isnumeric(char c)
{
	return (c >= '0' && c <= '9');
}

char **ft_cleanidx(char **idx1, unsigned int countCleanIdx, unsigned int words)
{
	char **cleaned;
	unsigned int i;
	unsigned int j;
	unsigned int k;
	unsigned int l;

	cleaned = malloc(sizeof(char *) * countCleanIdx);
	i = 0;
	while (i < countCleanIdx)
		cleaned[i++] = malloc(1024);
	i = 0;
	j = 0;
	while (i < words && j < countCleanIdx)
	{
		k = 0;
		l = 0;
		if (idx1[i][0] != '.')
		{
			++i;
			continue;
		}
		while (idx1[i][l])
		{
			if (ft_isnumeric(idx1[i][l]))
			{
				cleaned[j][k++] = idx1[i][l];
			}
			++l;
		}
		cleaned[j++][k] = 0;
		++i;
	}
	return (cleaned);
}

int *ft_getnbrs(char **cleaned)
{
	int	*idx_nbrs;
	unsigned int i;

	idx_nbrs = malloc(sizeof(int) * 10);
	i = 0;
	while (cleaned[i])
	{
		idx_nbrs[i] = atoi(cleaned[i]);
		++i;
	}
	return (idx_nbrs);
}

void ft_countCleanIdx(unsigned int *countCleanIdx, unsigned int words, char **idx1)
{
	unsigned int i;

	i = 0;
	(*countCleanIdx) = 0;
	while (i < words)
	{
		if (idx1[i][0] == '.')
		{
			++(*countCleanIdx);
		}
		++i;
	}
}

int *getIdx(char **av, unsigned int words)
{
	char **idx1;
	char **cleanidx1;
	int	*idx_nbrs;
	unsigned int countCleanIdx;

	idx1 = ft_splittedline(av[2], ' ', words);
	ft_countCleanIdx(&countCleanIdx, words, idx1);
	printf("Clean Idx:%d\n", countCleanIdx);
	cleanidx1 = ft_cleanidx(idx1, countCleanIdx, words);
	//idx_nbrs = ft_getnbrs(cleanidx1);
	
	printf("Clean Idx: .%s.\n", cleanidx1[0]);
}

char *getOutput(int *idx_nbrs, char **av, char **inTxt)
{
	char *output;
	char *replaced_output;
	unsigned int i;
	unsigned int j;

	replaced_output = malloc(strlen(output));
	output = av[2];
	i = 0;
	j = 0;
	while (output[i])
	{
		replaced_output[j] = output[i];
		++i;
		++j;
	}
	return (replaced_output);
}
/*
def getIdx(av):
	idx = av[2].split(' ')
	idx = [i for i in idx if len(i)]
	return [int(i[1:]) for i in idx if i[0] == '.']

def getOutput(idx, av, inTxt):
	output = av[2]
	try:
		for i in idx: output = output.replace(f".{i}", inTxt[i - 1])
	except Exception as e: print(e); exit()
	return output

def main():
	av, ac = getAvAc()
	if ac != 3: exit()
	inTxt = getInTxt(av)
	idx = getIdx(av)
	output = getOutput(idx, av, inTxt)
	print("Final Output:", output)

if __name__ == '__main__': main()
*/

int main(int ac, char **av)
{
	int *idx;
	char *output;
	char **inTxt;
	unsigned int i;
	unsigned int words;
	
	if (ac != 3)
		return (1);

	inTxt = getInTxt(av, &words);
	printf("%s\n", inTxt[0]);
	printf("%s\n", inTxt[1]);
	printf("%s\n", inTxt[2]);
	//printf("Words: %d\n", words);
	idx = getIdx(av, words);
	//printf("%d\n", idx[0]);
	//printf("%d\n", idx[1]);
	//printf("%d\n", idx[2]);
	//output = getOutput(idx, av, inTxt);
	//printf("%s\n", output);
	return (0);
}
