#ifndef FT_ALGO_ONE_HUNDRED_H
# define FT_ALGO_ONE_HUNDRED_H

# include "main.h"

# define PUSH_A 1
# define TRANCH1 1
# define TRANCH2 2
# define TRANCH3 3
# define TRANCH4 4



char    *ft_trie_20(t_list *a, t_list *b, t_option *option);
char    *ft_push_b_20(t_list *a, t_list *b, t_option *option);
char    *ft_push_a_20(t_list *a, t_list *b, t_option *option);
char    *ft_rotate(t_list *a, t_list *b, t_option *option);
char    *ft_annex_b(t_list *a, t_list *b, t_option *option);
int         ft_finish_tranch(t_list *a);

#endif
