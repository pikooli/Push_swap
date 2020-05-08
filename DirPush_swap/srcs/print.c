#include "main.h"

void		ft_print_list(t_maille *a, t_maille *b, t_option option)
{
	int i;

	ft_putstr("a             b\n");
	while (a || b)
	{
		i = 14;
		if (a)
		{
			option.val1 == a->val && option.color ? ft_putstr("\e[1;92m") : 0;
			ft_putnbr(a->val);
			i = a->val > 0 ? i : i -1;
			i -= ft_length_numb(a->val);
			option.val1 == a->val && option.color ? ft_putstr("\e[1;0m") : 0;
		}
		while (i-- > 0)
			ft_putstr(" ");
		if (b)
		{
			option.val1 == b->val && option.color ? ft_putstr("\e[1;92m") : 0;
			ft_putnbr(b->val);
			option.val1 == b->val && option.color ? ft_putstr("\e[1;0m") : 0;
		}
		ft_putstr("\n");
		a = a ? a->next : NULL;
		b = b ? b->next : NULL;
	}
}

void		ft_putstr(char *str)
{
	if (str)
		while (*str)
			write(1, str++, 1);
}

int			ft_print_error(void)
{
	ft_putstr("error\n");
	return (0);
}

void		ft_putnbr(int numb)
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

int			ft_print_ok(void)
{
	ft_putstr("OK\n");
	return (TRUE);
}

int			ft_print_ko(void)
{
	ft_putstr("KO\n");
	return (TRUE);
}

void		ft_print_resultb(t_list *a, t_list *b, t_option option)
{
	ft_putstr("---------------\n");
	ft_print_list(a->begin, b->begin, option);
}

void		ft_print_result(t_instructions *instruct, t_option option)
{
	ft_putstr("---------------\n");
	ft_print_list(instruct->a->begin, instruct->b->begin, option);
	ft_print_step(instruct);
}

void		ft_print_step(t_instructions *instructions)
{
	ft_putstr("number of step : ");
	ft_putnbr(instructions->numb);
	ft_putstr("\n");
	ft_print_last_step(instructions);
}

void    ft_rev_print(t_list *a)
{
    t_maille *tmp;

	tmp = a->begin;
	ft_putstr("------rev print ----------- \n");
    while (tmp->next)
    {
		    ft_putnbr(tmp->val);
        	ft_putstr("\n");
            tmp = tmp->next;
    }
	ft_putnbr(tmp->val);
    ft_putstr("\n");
	ft_putstr("------ start rev print ----------- \n");

    while (tmp)
    {
        ft_putnbr(tmp->val);
        ft_putstr("\n");
        tmp = tmp->prev;
    }
}


void		ft_print_2(t_maille *a, t_maille *b)
{
	ft_putstr("------ ");
	ft_putnbr(a->val);
	ft_putstr("------ ");
	ft_putnbr(b->val);
	ft_putstr("------\n");
}

void		ft_print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i++]);
		ft_putstr("\n");
	}
}

void		ft_print_instruction(t_instructions *instructions, t_option option)
{
	t_instruction *tmp;

	tmp = instructions->first;
	while (tmp)
	{
		!tmp->next && option.color ? ft_putstr("\e[1;92m") : 0;
		ft_putstr(tmp->val);
		!tmp->next && option.color ? ft_putstr("\e[1;0m") : 0;
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

void		ft_print_last_step(t_instructions *instruct)
{
	if (instruct->last)
	{
		ft_putstr("\e[1;32m");
		ft_putstr("instruction = ");
		ft_putstr(instruct->last->val);
		ft_putstr("\e[1;0m"); 
		ft_putstr("\n");
	}
}

void	ft_print_tranch(t_list *a)
{
	ft_putstr("----------- tranche --------\n");
	ft_putnbr(a->tranch.tranch1);
	ft_putstr("\n");
	ft_putnbr(a->tranch.tranch2);
	ft_putstr("\n");
	ft_putnbr(a->tranch.tranch3);
	ft_putstr("\n");
	ft_putnbr(a->tranch.tranch4);
	ft_putstr("\n");
	ft_putnbr(a->tranch.tranch5);
	ft_putstr("\n");
}