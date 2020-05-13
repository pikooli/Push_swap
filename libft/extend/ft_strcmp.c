/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 10:03:12 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 10:03:24 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char *str1, char *str2)
{
	int i;

	if (str1 == NULL || str2 == NULL)
		return (0);
	i = 0;
	while ((str1[i] == str2[i]) && str1[i] && str2[i])
		i++;
	return ((str1[i] == '\0') && (str2[i] == '\0'));
}
