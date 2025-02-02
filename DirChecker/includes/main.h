/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:15:38 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 12:40:05 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define GREEN "\e[32m"
# define RED "\e[1;31m"
# define RESET "\e[1;0m"
# define INVERT "\e[7m"
# define BACKGREEN "\e[42;m"
# define BACKBLUE "\e[44m"

typedef struct	s_maille
{
	int				val;
	struct s_maille	*prev;
	struct s_maille	*next;
}				t_maille;

typedef struct	s_list
{
	t_maille	*begin;
	int			numb;
}				t_list;

typedef struct	s_option
{
	int	val1;
	int	color;
	int	print;
	int nb_instruction;
}				t_option;

/*
** principal function
*/

void			ft_principal_checker(int num, char **av, t_option *option);
int				ft_one_argu(char *str, t_option *option);

/*
** check function
*/
int				ft_only_number(char *str);
int				ft_check_entry(int num, char **tab, t_option *option);
int				ft_check_instruction(char buf[4], t_list *a, t_list *b,
t_option *option);
int				ft_check_double(int num, char **tab);
int				ft_check_final(t_list *a, t_list *b);
int				ft_set_option(int num, char **tab, t_option *option);

/*
** malloc function
*/

t_maille		*ft_copy_av(int num, char *av[]);
char			*ft_substr(char *str);
t_maille		*ft_new_elem(int val);
t_list			*ft_list();

/*
** free function
*/

t_maille		*ft_free_list(t_maille *begin);
int				ft_free_tab(char **tab);
int				ft_strfree(char *str);
char			**ft_free_tab_num(int size, char **tab);
t_maille		*ft_create_maille(int i, char **av);

/*
** print function
*/

void			ft_putstr(const char *str);
void			ft_print_list(t_maille *a, t_maille *b, t_option option);
int				ft_print_error();
void			ft_putnbr(int numb);
int				ft_print_ok();
int				ft_print_ko();
void			ft_print_result(t_list *a, t_list *b, t_option option);
void			ft_putcolor(const char *color);
void			ft_putstrcolor(const char *str, const char *color);
void			ft_message(const char *str, int nb, const char *color);
void			ft_print_step(t_list *a, t_list *b, t_option *option,
						const char *cmd);

/*
** instruction
*/

int				ft_instruction(t_list *a, t_list *b, t_option *option);
int				ft_sa(t_list *a, t_option *option);
int				ft_sb(t_list *b, t_option *option);
int				ft_ss(t_list *a, t_list *b, t_option *option);
int				ft_pa(t_list *a, t_list *b, t_option *option);
int				ft_pb(t_list *a, t_list *b, t_option *option);
int				ft_ra(t_list *a, t_option *option);
int				ft_rb(t_list *b, t_option *option);
int				ft_rr(t_list *a, t_list *b, t_option *option);
int				ft_rra(t_list *a, t_option *option);
int				ft_rrb(t_list *b, t_option *option);
int				ft_rrr(t_list *a, t_list *b, t_option *option);

/*
** utility
*/

long			ft_atoi(char *str);
int				ft_strcmp(char *str1, char *str2);
int				ft_tab_length(char **tab);
char			*ft_append(char *str1, char *str2);
int				ft_strlen(char *str);
int				ft_length_numb(int nb);

/*
**split
*/
char			**ft_split(char *str, char cara);

#endif
