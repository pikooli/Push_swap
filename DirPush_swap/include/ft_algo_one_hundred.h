#ifndef FT_ALGO_ONE_HUNDRED_H
# define FT_ALGO_ONE_HUNDRED_H

# include "main.h"

# define PUSH_A 1
# define TRANCH1 1
# define TRANCH2 2
# define TRANCH3 3
# define TRANCH4 4
# define TRANCH5 5



char    *ft_trie_20(t_list *a, t_list *b, t_option *option);
char    *ft_push_b_20(t_list *a, t_list *b, t_option *option);
char    *ft_push_a_20(t_list *a, t_list *b, t_option *option);
char    *ft_annex_b(t_list *a, t_list *b, t_option *option);
int         ft_finish_tranch(t_list *a);
void        ft_is_tranch(t_list *a, int val);
void        ft_tranch_finish(t_list *a);
void			ft_print_tranch(t_list *a);
void        ft_print_tranch_step(t_list *a);
char    *ft_rotate(t_list *list, t_option *option, int val);
char    *ft_search_next(t_list *a, t_list *b, t_option *option);
int     ft_return_tranch_val(t_list *a);
void	ft_first_tranch(t_list *a);
int     ft_next_bigger_tranch(t_list *a, t_list *b);
void    ft_print_finish_tranch(t_list *a);
char    *ft_final(t_list *a, t_list *b, t_option *option);


#endif
