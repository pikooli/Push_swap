#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef struct	s_maille
{
	int				val;
	struct s_maille *prev;
	struct s_maille *next;
}				t_maille;

typedef struct	s_list
{
	t_maille	*begin;
	t_maille	*last;
	int			numb;
}				t_list;

typedef struct	s_option
{
	int val1;
	int color;
	int print;
	int modetri;
}				t_option;

typedef struct	s_instruction
{
	char					*val;
	struct s_instruction	*next;
}				t_instruction;

typedef struct	s_instructions
{
	t_instruction	*first;
	t_instruction	*last;
	t_list			*a;
	t_list			*b;
	int				numb;
}				t_instructions;

/*
** algo
*/

int				ft_algo(t_list *a, t_option *option);
t_maille		*ft_copy_list(t_maille *first);
t_instructions	*ft_prepare_algo(t_list *a, t_option *option,
char *(*algo)(t_list *, t_list *, t_option *));
void			*ft_test_algo(t_instructions *instruct, t_option *option,
char *(*algo)(t_list *, t_list *, t_option *));
t_instructions *ft_best_algo(t_list *a, t_instructions *instruct, t_option
 *option, char *(*algo)(t_list *, t_list *, t_option *));

char			*ft_algo_1_1(t_list *a, t_list *b, t_option *option);
char 			*ft_algo_1_2(t_list *a, t_list *b, t_option *option);

/*
** principal function
*/
void			ft_principal_push_swap(int num, char **av, t_option *option);
int				ft_one_argu(char *str, t_option *option);

/*
** check function
*/

int				ft_only_number(char *str);
int				ft_check_entry(int num, char **tab, t_option *option);
char			*ft_check_instruction(char buf[4], t_list *a,
t_list *b, t_option *option);
int				ft_check_double(int num, char **tab);
int				ft_check_final(t_list *a, t_list *b);
int				ft_set_option(int num, char **tab, t_option *option);
int				ft_check_list(t_list *list);
int				ft_check_rev_list(t_list *list);
int				ft_top_is_the_bigger(t_list *list);

/*
** copy_entry
*/
t_maille		*ft_copy_av(int num, char *av[]);
t_maille		*ft_create_maille(int i, char **av);

/*
** malloc function
*/
char			*ft_substr(char *str);
t_maille		*ft_new_elem(int val);
t_list			*ft_list();
t_instructions	*ft_create_instructions();
t_instruction	*ft_create_instruction(char *str);

/*
** free function
*/
t_maille		*ft_free_list(t_maille *begin);
int				ft_free_tab(char **tab);
int				ft_strfree(char *str);
char			**ft_free_tab_num(int size, char **tab);
void			*ft_free_listall(t_list *list);
int				ft_free_instructions(t_instructions *instructions);

/*
** print function
*/
void			ft_putstr(char *str);
void			ft_print_list(t_maille *a, t_maille *b, t_option option);
int				ft_print_error();
void			ft_putnbr(int numb);
int				ft_print_ok();
int				ft_print_ko();
void			ft_print_result(t_instructions *instruct, t_option option);
void			ft_print_tab(char **tab);
void			ft_print_instruction(t_instructions *instructions,
t_option option);
void			ft_print_resultb(t_list *a, t_list *b, t_option option);
void			ft_print_step(t_instructions *instructions);

/*
** instruction
*/
int				ft_instruction(t_list *a, t_list *b, t_option *option);
char			*ft_sa(t_list *a, t_option *option);
char			*ft_sb(t_list *b, t_option *option);
char			*ft_ss(t_list *a, t_list *b, t_option *option);
char			*ft_pa(t_list *a, t_list *b, t_option *option);
char			*ft_pb(t_list *a, t_list *b, t_option *option);
char			*ft_ra(t_list *a, t_option *option);
char			*ft_rb(t_list *b, t_option *option);
char			*ft_rr(t_list *a, t_list *b, t_option *option);
char			*ft_rra(t_list *a, t_option *option);
char			*ft_rrb(t_list *b, t_option *option);
char			*ft_rrr(t_list *a, t_list *b, t_option *option);

/*
** utility
*/
long			ft_atoi(char *str);
int				ft_strcmp(char *str1, char *str2);
int				ft_tab_length(char **tab);
char			*ft_append(char *str1, char *str2);
int				ft_strlen(char *str);
int				ft_length_numb(int nb);
int				ft_bigger_in_list(t_list *list);


/*
**	list function
*/
t_maille		*ft_last_list(t_list *list);
int				ft_smaller_in_list(t_list *list);
int 			ft_list_ordoned(t_list *list);
int				ft_less_diff(t_list *list, int val);
int				ft_less_diff_b(t_list *a, t_list *b);

/*
**split
*/
char			**ft_split(char *str, char cara);

#endif
