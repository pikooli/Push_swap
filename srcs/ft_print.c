/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:14:53 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 13:30:12 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		*ft_error(void)
{
	ft_putstrendl("error");
	return (NULL);
}

void		ft_printf(char *str, int nb)
{
	ft_putstr(str);
	ft_putstr(" : ");
	ft_putnbr(nb);
	ft_putstr("\n");
}

void		ft_print_stack(t_stack *stack)
{
	t_stack_elem	*elem;
	size_t			i;

	i = 0;
	if (stack->markup_head)
	{
		ft_printf("markup head number", stack->markup_head->number);
		ft_printf("markup head index", stack->markup_head->index);
	}
	ft_printf("number of pair ", stack->pairs);
	ft_printf("size stack ", stack->size);
	elem = stack->head;
	while (i++ < stack->size)
	{
		ft_putnbr_fd(elem->number, 1);
		ft_putstr(" ");
		ft_putnbr(elem->index);
		ft_printf(" keep ", elem->keep_in_stack);
		ft_putstrendl("");
		elem = elem->next;
	}
}

void		ft_printf_cmd(t_command_list *list)
{
	t_command	*tmp;
	size_t		i;

	tmp = list->head;
	i = 0;
	ft_printf("list size ", list->size);
	while (i++ < list->size)
	{
		ft_putstrendl(tmp->name);
		tmp = tmp->next;
	}
}
