#ifndef FT_ALGO_ONE_HUNDRED_H
# define FT_ALGO_ONE_HUNDRED_H

# include "main.h"

# define PUSH_A 1

char    *ft_push_b_20(t_list *a, t_list *b, t_option *option);
char    *ft_push_a_20(t_list *a, t_list *b, t_option *option);
char    *ft_annex_b(t_list *a, t_list *b, t_option *option);
char    *ft_rotate(t_list *list, t_option *option, int val);
char    *ft_search_next(t_list *a, t_list *b, t_option *option);
char    *ft_final(t_list *a, t_list *b, t_option *option);
int     ft_next_bigger(t_list *a, t_list *b);


#endif
