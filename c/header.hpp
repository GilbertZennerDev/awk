#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_ijkl
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	l;
} t_ijkl;

bool ft_isnumeric(char c);
void ft_malloc_sarray(char ***sl, unsigned int 	words);
void 	ft_split_line(char ***sl, char buffer[], char splitter, unsigned int 	words);
int *getIdx(char **av, unsigned int *countIdx);
void getOutput(int *idx_nbrs, unsigned int countIdx, char **inTxt);
void	ft_countWords(char buffer[], unsigned int *words, char splitter);
char **ft_splittedline(char buffer[], char splitter);
void ft_countCleanIdx(unsigned int *countCleanIdx, unsigned int words, char **idx1);
char **ft_cleanidx(char **idx1, unsigned int countCleanIdx, unsigned int words);
int *ft_getnbrs(char **cleaned, unsigned int words);
char **getInTxt(char **av);
void ft_copy_cleanidx(char ***cleaned, char **idx1, unsigned int words, unsigned int countCleanIdx);

