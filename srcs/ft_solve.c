/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:17:22 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 02:18:18 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_align_a(t_stack *a_stack,
					t_command_list *command_list)
{
	t_stack_elem	*current;
	size_t			ra_size;
	size_t			rra_size;

	if (a_stack && a_stack->head)
	{
		ra_size = 0;
		current = a_stack->head;
		while (current->index != 0)
		{
			ra_size++;
			current = current->next;
		}
		rra_size = 0;
		current = a_stack->head;
		while (current->index != 0)
		{
			rra_size++;
			current = current->previous;
		}
		while (a_stack->head->index != 0 && (ra_size < rra_size))
			ft_rx(a_stack, "ra", command_list);
		while (a_stack->head->index != 0 && !(ra_size < rra_size))
			ft_rrx(a_stack, "rra", command_list);
	}
}

t_command_list	*ft_solve(t_stack *a_stack,
					size_t (*markup_stack)(t_stack *, t_stack_elem *))
{
	t_command_list	*command_list;
	t_stack			*b_stack;

	command_list = ft_init_command_list();
	b_stack = ft_init_stack();
	ft_solve_a(a_stack, b_stack, markup_stack, command_list);
	ft_solve_b(a_stack, b_stack, command_list);
	ft_align_a(a_stack, command_list);
	ft_free_stack(b_stack);
	free(b_stack);
	return (command_list);
}
