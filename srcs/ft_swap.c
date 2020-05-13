/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:20:37 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 02:20:40 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack_elem *first,
				t_stack_elem *second,
				t_stack *stack)
{
	t_stack_elem	*previous;
	t_stack_elem	*next;

	previous = first->previous;
	next = second->next;
	previous->next = second;
	second->previous = previous;
	first->next = next;
	next->previous = first;
	second->next = first;
	first->previous = second;
	stack->head = second;
}

void		ft_sx(t_stack *stack,
				const char *name,
				t_command_list *list)
{
	if (stack && stack->head && stack->size >= 2)
		ft_swap(stack->head, stack->head->next, stack);
	if (name && !list)
		ft_putstrendl(name);
	if (name && list)
		ft_add_command(list, ft_create_command(name));
}

void		ft_ss(t_stack *a,
				t_stack *b,
				const char *name,
				t_command_list *list)
{
	ft_sx(a, NULL, NULL);
	ft_sx(b, NULL, NULL);
	if (name && !list)
		ft_putstrendl(name);
	if (name && list)
		ft_add_command(list, ft_create_command(name));
}
