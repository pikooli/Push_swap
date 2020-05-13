/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:27:01 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 12:33:22 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_putstr(const char *str)
{
	if (str)
		while (*str)
			write(1, str++, 1);
}

void	ft_putnbr(int numb)
{
	char c;

	if (numb < 0 && numb != -2147483648)
	{
		numb = -numb;
		c = '-';
		write(1, &c, 1);
	}
	if (numb > 9)
		ft_putnbr(numb / 10);
	c = numb % 10 + 48;
	if (numb == -2147483648)
		write(1, "-2147483648", 11);
	else
		write(1, &c, 1);
}

void	ft_putcolor(const char *color)
{
	ft_putstr(color);
}

void	ft_putstrcolor(const char *str, const char *color)
{
	ft_putcolor(color);
	ft_putstr(str);
	ft_putcolor(RESET);
	ft_putstr("\n");
}
