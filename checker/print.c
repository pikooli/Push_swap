#include "main.h"

void ft_print_list(t_maille *a, t_maille *b)
{
    int i;

    ft_putstr("a             b\n");
    while (a || b)
    {
        i = 14;
        if (a)
        {    
            ft_putnbr(a->val);
            i -= ft_length_numb(a->val);

        }
        while(i-- > 0)
            ft_putstr(" ");
        b ? ft_putnbr(b->val) : 0;
        ft_putstr("\n");
        a = a ? a->next : NULL;
        b = b ? b->next : NULL; 
    }
}

void ft_putstr(char *str)
{
    if (str)
        while(*str)
            write(1, str++, 1);
}

int    ft_print_error()
{
    ft_putstr("error\n");
    return 0;
}

void ft_putnbr(int numb)
{
    char c;

    if (numb < 0 && numb != -2147483648)
    {
        numb = - numb;
        c = '-';
        write(1, &c, 1);
    }
    if (numb > 9)
        ft_putnbr(numb /10);
    c = numb % 10 + 48;
    if (numb == -2147483648)
        write(1,"-2147483648", 11);
    else
        write(1, &c, 1);
}

int    ft_print_ok()
{
    ft_putstr("OK\n");
    return TRUE;
}

int    ft_print_ko()
{
    ft_putstr("KO\n");
    return TRUE;
}

void    ft_print_result(t_list *a, t_list *b)
{
	ft_print_list(a->begin, b->begin);
}

void    ft_print_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        ft_putstr(tab[i++]);
        ft_putstr("\n");
    }
}

// printf("option print = %d\noption color = %d\n", option.print, option.color);