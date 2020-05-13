/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:10:31 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 02:11:04 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_elem	*ft_get_next_min(t_stack *stack)
{
	size_t		i;
	t_bool		has_min;
	t_stack_elem*min;
	t_stack_elem*current;

	min = NULL;
	if (stack)
	{
		i = 0;
		has_min = false;
		current = stack->head;
		while (i < stack->size)
		{
			if ((current->index == -1)
			&& (!has_min || current->number < min->number))
			{
				has_min = true;
				min = current;
			}
			i++;
			current = current->next;
		}
	}
	return (min);
}

void				ft_index_stack(t_stack *stack)
{
	size_t			index;
	t_stack_elem	*current;

	index = 0;
	while ((current = ft_get_next_min(stack)))
		current->index = index++;
}
