/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:18:01 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 12:18:02 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_maille	*ft_free_list(t_maille *begin)
{
	t_maille *tmp;

	while (begin)
	{
		tmp = begin->next;
		free(begin);
		begin = tmp;
	}
	return (NULL);
}

int			ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (FALSE);
}

int			ft_strfree(char *str)
{
	free(str);
	return (FALSE);
}
