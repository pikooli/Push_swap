/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:28:26 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 12:32:54 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_print_error(void)
{
	ft_putstr("error\n");
	return (0);
}

int		ft_print_ok(void)
{
	ft_putstr("OK\n");
	return (TRUE);
}

int		ft_print_ko(void)
{
	ft_putstr("KO\n");
	return (TRUE);
}
