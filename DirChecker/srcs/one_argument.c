/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:17:49 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 12:17:50 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_one_argu(char *str, t_option *option)
{
	char	**tab;
	int		size;
	int		i;

	if (!(tab = ft_split(str, ' ')))
		return (ft_print_error());
	if (!(size = ft_tab_length(tab)))
	{
		ft_free_tab(tab);
		return (0);
	}
	if (!ft_check_entry(size, tab, option))
	{
		ft_free_tab(tab);
		return (ft_print_error());
	}
	i = option->print + option->color;
	ft_principal_checker(size - i, &tab[i], option);
	ft_free_tab(tab);
	return (0);
}
