/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:18:33 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 02:18:40 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	ft_needs_pb(t_stack *a_stack)
{
	size_t			i;
	t_stack_elem	*current;

	if (a_stack)
	{
		i = 0;
		current = a_stack->head;
		while (i < a_stack->size)
		{
			if (!current->keep_in_stack)
				return (true);
			i++;
			current = current->next;
		}
	}
	return (false);
}

static t_bool	ft_needs_sa(t_stack *a_stack,
					size_t (*markup_stack)(t_stack *, t_stack_elem *))
{
	size_t	current_pairs;

	if (a_stack && a_stack->size >= 2)
	{
		ft_sx(a_stack, NULL, NULL);
		current_pairs = markup_stack(a_stack, a_stack->markup_head);
		ft_sx(a_stack, NULL, NULL);
		markup_stack(a_stack, a_stack->markup_head);
		if (current_pairs > a_stack->pairs)
			return (true);
	}
	return (false);
}

void			ft_solve_a(t_stack *a_stack,
					t_stack *b_stack,
					size_t (*markup_stack)(t_stack *, t_stack_elem *),
					t_command_list *command_list)
{
	while (ft_needs_pb(a_stack))
	{
		if (ft_needs_sa(a_stack, markup_stack))
		{
			ft_sx(a_stack, "sa", command_list);
			a_stack->pairs = markup_stack(a_stack, a_stack->markup_head);
		}
		else if (a_stack->head->keep_in_stack == false)
			ft_px(b_stack, a_stack, "pb", command_list);
		else
			ft_rx(a_stack, "ra", command_list);
	}
}
