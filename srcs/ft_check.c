/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:04:33 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 02:05:16 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_check_dups(t_stack *stack)
{
	size_t			i;
	t_stack_elem	*current;
	t_stack_elem	*tmp;

	i = 0;
	current = stack->head;
	while (i < stack->size)
	{
		tmp = current->next;
		while (tmp != current)
		{
			if (tmp->number == current->number)
				return (false);
			tmp = tmp->next;
		}
		i++;
		current = current->next;
	}
	return (true);
}
