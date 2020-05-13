/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:21:27 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 02:27:26 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			ft_principal(t_stack *stack, t_stack *stack_gt)
{
	t_command_list	*commands_index;
	t_command_list	*commands_gt;

	ft_index_stack(stack);
	ft_index_stack(stack_gt);
	opt_markup_stack(stack, &ft_markup_stack_index);
	opt_markup_stack(stack_gt, &ft_markup_stack_gt);
	commands_index = ft_solve(stack, &ft_markup_stack_index);
	commands_gt = ft_solve(stack_gt, &ft_markup_stack_gt);
	ft_print_commands(commands_index->size < commands_gt->size ?
	commands_index : commands_gt);
	ft_free_command(commands_index);
	ft_free_command(commands_gt);
}

int					main(int ac, char *av[])
{
	t_stack	*stack;
	t_stack	*stack_gt;

	if (ac >= 2)
	{
		if (!(stack = ft_parse(ac, av)))
			ft_error();
		else
		{
			if (!ft_check_dups(stack) || !(stack_gt = ft_parse(ac, av)))
				ft_error();
			else
			{
				ft_principal(stack, stack_gt);
				ft_free_stack(stack_gt);
				free(stack_gt);
			}
			ft_free_stack(stack);
			free(stack);
		}
	}
	else
		ft_error();
}

/*
**    system("leaks push_swap");
*/
