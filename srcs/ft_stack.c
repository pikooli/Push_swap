/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:19:37 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 02:20:21 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_elem	*ft_create_elem(int numb)
{
	t_stack_elem *new;

	if (!(new = (t_stack_elem *)ft_zemalloc(sizeof(t_stack_elem))))
		return (ft_error());
	new->number = numb;
	new->index = -1;
	new->keep_in_stack = false;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

void			ft_add_to_stack(t_stack *stack, t_stack_elem *elem)
{
	t_stack_elem *tail;

	if (stack && elem)
	{
		if (!stack->head)
		{
			stack->head = elem;
			stack->head->previous = stack->head;
			stack->head->next = stack->head;
			stack->tail = stack->head;
		}
		else
		{
			tail = stack->head->previous;
			elem->previous = tail;
			tail->next = elem;
			elem->next = stack->head;
			stack->head->previous = elem;
			stack->tail = elem;
		}
		stack->size++;
	}
}

void			ft_push(t_stack *stack,
					t_stack_elem *elem)
{
	t_stack_elem	*tail;

	if (stack && elem)
	{
		if (!stack->head)
		{
			stack->head = elem;
			stack->head->previous = stack->head;
			stack->head->next = stack->head;
		}
		else
		{
			tail = stack->head->previous;
			elem->previous = tail;
			tail->next = elem;
			elem->next = stack->head;
			stack->head->previous = elem;
			stack->head = elem;
		}
		stack->size++;
	}
}

t_stack_elem	*ft_pop(t_stack *stack)
{
	t_stack_elem	*elem;

	elem = NULL;
	if (stack && stack->size)
	{
		if (stack->size == 1)
		{
			elem = stack->head;
			stack->head = NULL;
			elem->previous = NULL;
			elem->next = NULL;
		}
		else
		{
			elem = stack->head;
			stack->head = stack->head->next;
			elem->previous->next = elem->next;
			elem->next->previous = elem->previous;
			elem->previous = NULL;
			elem->next = NULL;
		}
		stack->size--;
	}
	return (elem);
}
