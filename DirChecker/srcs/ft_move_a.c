/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:21:14 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 12:32:03 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			ft_rra(t_list *a, t_option *option)
{
	t_maille *tmp;
	t_maille *last;

	if (a->numb < 2)
		return (TRUE);
	tmp = a->begin;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = a->begin;
	a->begin = last;
	option->val1 = last->val;
	return (TRUE);
}

int			ft_ra(t_list *a, t_option *option)
{
	t_maille *tmp;
	t_maille *last;

	if (a->numb < 2)
		return (TRUE);
	tmp = a->begin;
	a->begin = a->begin->next;
	tmp->next = NULL;
	last = a->begin;
	while (last->next)
		last = last->next;
	last->next = tmp;
	option->val1 = tmp->val;
	return (TRUE);
}

int			ft_pa(t_list *a, t_list *b, t_option *option)
{
	t_maille *tmp;

	if (b->numb == 0)
		return (TRUE);
	option->val1 = b->begin->val;
	tmp = b->begin;
	b->begin = b->begin->next;
	b->numb -= 1;
	tmp->next = a->begin;
	a->begin = tmp;
	a->numb += 1;
	return (TRUE);
}

int			ft_sa(t_list *a, t_option *option)
{
	t_maille *tmp;

	if (a->numb > 1)
	{
		tmp = a->begin;
		option->val1 = tmp->val;
		a->begin = a->begin->next;
		tmp->next = a->begin->next;
		a->begin->next = tmp;
	}
	return (TRUE);
}
