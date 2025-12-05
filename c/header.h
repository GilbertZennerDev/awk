#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_ijkl
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	l;
}	t_ijkl;

bool			ft_isnumeric(char c);
char			**get_in_txt(char **av);
unsigned int	ft_get_arr_lenght(char **arr);
int				*get_idx(char **av, unsigned int *countIdx);
int				*ft_getnbrs(char **cleaned, unsigned int words);
char			**ft_splittedline(char buffer[], char splitter);
void			ft_malloc_sarray(char ***sl, unsigned int 	words);
void			ft_countWords(char buffer[], unsigned int *words, char splitter);
char			**ft_cleanidx(char **idx1, unsigned int countCleanIdx, unsigned int words);
void			ft_countCleanIdx(unsigned int *countCleanIdx, unsigned int words, char **idx1);
void			ft_split_line(char ***sl, char buffer[], char splitter, unsigned int 	words);
void			get_output(int *idx_nbrs, unsigned int count_idx, char **in_txt, unsigned int	count_words);
void			ft_copy_cleanidx(char ***cleaned, char **idx1, unsigned int words, unsigned int countCleanIdx);

