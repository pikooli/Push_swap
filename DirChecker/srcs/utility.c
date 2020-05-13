/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:17:36 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 12:31:33 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			ft_strcmp(char *str1, char *str2)
{
	int i;

	if (str1 == NULL || str2 == NULL)
		return (0);
	i = 0;
	while ((str1[i] == str2[i]) && str1[i] && str2[i])
		i++;
	return ((str1[i] == '\0') && (str2[i] == '\0'));
}

long		ft_atoi(char *str)
{
	long	nb;
	int		i;
	int		moins;

	if (ft_strcmp(str, "-2147483648"))
		return (-2147483648);
	i = str[0] != '-' ? 0 : 1;
	moins = str[0] != '-' ? 1 : -1;
	nb = 0;
	while (str[i])
	{
		if (i > 10)
			return (nb);
		nb *= 10;
		nb += str[i++] - 48;
	}
	return (moins * nb);
}

int			ft_tab_length(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int			ft_length_numb(int nb)
{
	int i;

	i = 0;
	while (nb != 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int			ft_set_option(int num, char **tab, t_option *option)
{
	option->print = ft_strcmp(tab[0], "-v");
	option->color = ft_strcmp(tab[0], "-c");
	if (num > 1)
	{
		option->print = option->print ? option->print : ft_strcmp(tab[1], "-v");
		option->color = option->color ? option->color : ft_strcmp(tab[1], "-c");
	}
	return (option->print + option->color);
}
