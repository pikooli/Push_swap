/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:16:46 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 02:17:03 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rx(t_stack *stack,
			const char *name,
			t_command_list *list)
{
	if (stack && stack->head)
		stack->head = stack->head->next;
	if (name && !list)
		ft_putstrendl(name);
	if (name && list)
		ft_add_command(list, ft_create_command(name));
}

void	ft_rr(t_stack *a,
			t_stack *b,
			const char *name,
			t_command_list *list)
{
	ft_rx(a, NULL, NULL);
	ft_rx(b, NULL, NULL);
	if (name && !list)
		ft_putstrendl(name);
	if (name && list)
		ft_add_command(list, ft_create_command(name));
}

void	ft_rrx(t_stack *stack,
			const char *name,
			t_command_list *list)
{
	if (stack && stack->head)
		stack->head = stack->head->previous;
	if (name && !list)
		ft_putstrendl(name);
	if (name && list)
		ft_add_command(list, ft_create_command(name));
}

void	ft_rrr(t_stack *a,
			t_stack *b,
			const char *name,
			t_command_list *list)
{
	ft_rrx(a, NULL, NULL);
	ft_rrx(b, NULL, NULL);
	if (name && !list)
		ft_putstrendl(name);
	if (name && list)
		ft_add_command(list, ft_create_command(name));
}
