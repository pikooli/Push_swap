/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:17:43 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 12:41:19 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_print_list(t_maille *a, t_maille *b, t_option option)
{
	int i;

	ft_putstrcolor("a             b", INVERT);
	while (a || b)
	{
		i = 14;
		if (a)
		{
			option.val1 == a->val && option.color ? ft_putcolor(BACKBLUE) : 0;
			ft_putnbr(a->val);
			i -= ft_length_numb(a->val);
			option.val1 == a->val && option.color ? ft_putcolor(RESET) : 0;
		}
		while (i-- > 0)
			ft_putstr(" ");
		if (b)
		{
			option.val1 == b->val && option.color ? ft_putcolor(BACKBLUE) : 0;
			ft_putnbr(b->val);
			option.val1 == b->val && option.color ? ft_putcolor(RESET) : 0;
		}
		ft_putstr("\n");
		a = a ? a->next : NULL;
		b = b ? b->next : NULL;
	}
}

void	ft_print_step(t_list *a, t_list *b, t_option *option, const char *cmd)
{
	if (!option->print)
		return ;
	ft_print_list(a->begin, b->begin, *option);
	if (!option->color)
		return ;
	ft_putcolor(GREEN);
	ft_putstr("last command : '");
	ft_putstr(cmd);
	ft_putstr("'\n");
	ft_message("number of instruction : ", option->nb_instruction, GREEN);
}

void	ft_message(const char *str, int nb, const char *color)
{
	ft_putcolor(color);
	ft_putstr(str);
	ft_putstr(" : ");
	ft_putnbr(nb);
	ft_putstr("\n");
	ft_putcolor(RESET);
}

void	ft_print_result(t_list *a, t_list *b, t_option option)
{
	if (option.print)
	{
		ft_putstrcolor("----------- FINAL RESULT -----------", GREEN);
		ft_print_list(a->begin, b->begin, option);
	}
	if (option.color)
		ft_message("number of instruction : ", option.nb_instruction, GREEN);
}
