/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:16:50 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 12:18:14 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_check_entry(int num, char **tab, t_option *option)
{
	int i;

	i = ft_set_option(num, tab, option);
	while (i < num)
		if (!ft_only_number(tab[i++]))
			return (FALSE);
	if (ft_check_double(num, tab))
		return (FALSE);
	return (TRUE);
}

int		ft_only_number(char *str)
{
	int i;

	i = str[0] == '-' ? 0 : -1;
	while (str[++i])
		if (str[i] < 48 || str[i] > 57)
			return (FALSE);
	return ((TRUE));
}

int		ft_check_instruction(char buf[4], t_list *a, t_list *b,
t_option *option)
{
	if (ft_strcmp(buf, "sa"))
		return (ft_sa(a, option));
	else if (ft_strcmp(buf, "sb"))
		return (ft_sb(b, option));
	else if (ft_strcmp(buf, "ss"))
		return (ft_ss(a, b, option));
	else if (ft_strcmp(buf, "pa"))
		return (ft_pa(a, b, option));
	else if (ft_strcmp(buf, "pb"))
		return (ft_pb(a, b, option));
	else if (ft_strcmp(buf, "ra"))
		return (ft_ra(a, option));
	else if (ft_strcmp(buf, "rb"))
		return (ft_rb(b, option));
	else if (ft_strcmp(buf, "rr"))
		return (ft_rr(a, b, option));
	else if (ft_strcmp(buf, "rra"))
		return (ft_rra(a, option));
	else if (ft_strcmp(buf, "rrb"))
		return (ft_rrb(b, option));
	else if (ft_strcmp(buf, "rrr"))
		return (ft_rrr(a, b, option));
	return (FALSE);
}

int		ft_check_double(int num, char **tab)
{
	int i;
	int j;

	i = 0;
	while (i < num)
	{
		j = 0;
		while (j < i)
			if (ft_strcmp(tab[j++], tab[i]))
				return (TRUE);
		i++;
	}
	return (FALSE);
}

int		ft_check_final(t_list *a, t_list *b)
{
	t_maille *tmp;

	if (b->numb > 0)
		return (ft_print_ko());
	tmp = a->begin;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (ft_print_ko());
		tmp = tmp->next;
	}
	return (ft_print_ok());
}
