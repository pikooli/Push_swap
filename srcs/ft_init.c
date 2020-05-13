/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:11:19 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 02:11:34 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*ft_init_stack(void)
{
	t_stack *stack;

	if (!(stack = (t_stack *)ft_zemalloc(sizeof(t_stack))))
		return (ft_error());
	stack->head = NULL;
	stack->size = 0;
	stack->pairs = 0;
	stack->markup_head = NULL;
	return (stack);
}

t_command_list	*ft_init_command_list(void)
{
	t_command_list *list;

	if (!(list = (t_command_list *)ft_zemalloc(sizeof(t_command_list))))
		return (NULL);
	list->size = 0;
	list->head = NULL;
	return (list);
}
