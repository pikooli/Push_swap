/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:34:48 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 13:31:04 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define OK "OK"
# define KO "KO"

# define COLOR_OK "\e[32mOK\e[39m"
# define COLOR_KO "\e[32mKO\e[39m"

typedef enum
{
	R,
	RR
}	t_direction;

typedef struct			s_stack_elem
{
	int					number;
	ssize_t				index;
	t_bool				keep_in_stack;
	struct s_stack_elem	*previous;
	struct s_stack_elem *next;
}						t_stack_elem;

typedef struct			s_stack
{
	t_stack_elem		*head;
	t_stack_elem		*tail;
	size_t				size;
	size_t				pairs;
	t_stack_elem		*markup_head;
}						t_stack;

typedef struct			s_shift_info
{
	t_stack_elem		*a_elem;
	t_stack_elem		*b_elem;
	int					a_direction;
	int					b_direction;
	size_t				size;
	t_bool				is_set;
}						t_shift_info;

typedef struct			s_command
{
	char				*name;
	struct s_command	*next;
}						t_command;

typedef struct			s_command_list
{
	size_t				size;
	t_command			*head;
}						t_command_list;

/*
**		ft_print.c
*/
void					*ft_error(void);
void					ft_print_stack(t_stack *stack);
void					ft_printf_cmd(t_command_list *list);

/*
**		ft_parse.c
*/
t_stack					*ft_parse(int ar,
					char *av[]);

/*
**		ft_stack.c
*/

t_stack_elem			*ft_create_elem(int numb);
void					ft_add_to_stack(t_stack *stack, t_stack_elem *elem);
void					ft_push(t_stack *stack,
					t_stack_elem *elem);
t_stack_elem			*ft_pop(t_stack *stack);

/*
**		ft_free.c
*/

void					*ft_free_stack(t_stack *stack);
void					*ft_free_split(char **split);
void					ft_free_command(t_command_list *list);

/*
**		ft_check.c
*/

t_bool					ft_check_dups(t_stack *stack);

/*
**		ft_index.c
*/

void					ft_index_stack(t_stack *stack);

/*
**		ft_markup.c
*/
void					opt_markup_stack(t_stack *stack,
					size_t (*markup_stack)(t_stack *, t_stack_elem *));
size_t					ft_markup_stack_index(t_stack *stack,
					t_stack_elem *markup_head);
size_t					ft_markup_stack_gt(t_stack *stack,
					t_stack_elem *markup_head);

/*
**		ft_init.c
*/

t_stack					*ft_init_stack(void);
t_command_list			*ft_init_command_list(void);

/*
**		ft_swap.c
*/

void					ft_sx(t_stack *stack,
					const char *cmd,
					t_command_list *cmd_list);
void					ft_ss(t_stack *a,
					t_stack *b,
					const char *cmd,
					t_command_list *cmd_list);

/*
**		ft_cmd.c
*/

t_command				*ft_create_command(const char *str);
void					ft_add_command(t_command_list *list,
					t_command *cmd);
void					ft_print_commands(t_command_list *list);

/*
**		ft_push.c
*/

void					ft_px(t_stack *to,
					t_stack *from,
					const char *cmd,
					t_command_list *cmd_list);
/*
**		ft_rotate.c
*/

void					ft_rx(t_stack *stack,
					const char *cmd,
					t_command_list *cmd_list);
void					ft_rr(t_stack *a,
					t_stack *b,
					const char *cmd,
					t_command_list *cmd_list);
void					ft_rrr(t_stack *a,
					t_stack *b,
					const char *cmd,
					t_command_list *cmd_list);
void					ft_rrx(t_stack *stack,
					const char *cmd,
					t_command_list *cmd_list);
/*
**		ft_solve.c
*/

t_command_list			*ft_solve(t_stack *a,
					size_t (*markup_stack)(t_stack *, t_stack_elem *));

/*
**		ft_solve_a.c
*/

void					ft_solve_a(t_stack *a,
					t_stack *b,
					size_t (*markup_stack)(t_stack *, t_stack_elem *),
					t_command_list *cmd_list);
/*
**		ft_solve_b.c
*/

void					ft_solve_b(t_stack *a_stack,
					t_stack *b_stack,
					t_command_list *command_list);
/*
**		ft_direction.c
*/

void					ft_opt_direction(t_stack *a,
					t_stack *b,
					t_shift_info *shift_info);
/*
**		ft_utils.c
*/

size_t					ft_max(size_t a, size_t b);
int						ft_size_tab(char **tab);
#endif
