/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:17:58 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 12:42:20 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	ft_instruction_next(t_list *a,
					t_list *b,
					t_option *option,
					char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		if (!(ft_check_instruction(tab[i], a, b, option)))
			return (FALSE);
		else
		{
			option->nb_instruction = i + 1;
			ft_print_step(a, b, option, tab[i]);
		}
	return (TRUE);
}

int			ft_instruction(t_list *a,
					t_list *b,
					t_option *option)
{
	char	buf[10];
	int		ret;
	char	**tab;
	char	*cmd;

	if (!(cmd = malloc(sizeof(char) * 1)))
		return (FALSE);
	cmd[0] = '\0';
	while ((ret = read(0, buf, 5)))
	{
		buf[ret] = '\0';
		if (!(cmd = ft_append(cmd, buf)))
			return (FALSE);
	}
	if (!(tab = ft_split(cmd, '\n')))
		return (ft_strfree(cmd));
	free(cmd);
	if (!(ft_instruction_next(a, b, option, tab)))
		return (ft_free_tab(tab));
	ft_free_tab(tab);
	return (ft_check_final(a, b));
}

int			ft_ss(t_list *a, t_list *b, t_option *option)
{
	ft_sa(a, option);
	return (ft_sb(b, option));
}

int			ft_rr(t_list *a, t_list *b, t_option *option)
{
	ft_ra(a, option);
	return (ft_rb(b, option));
}

int			ft_rrr(t_list *a, t_list *b, t_option *option)
{
	ft_rra(a, option);
	return (ft_rrb(b, option));
}
