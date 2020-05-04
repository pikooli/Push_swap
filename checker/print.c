#include "main.h"

void ft_print_list(t_maille *begin)
{
    while (begin)
    {
        ft_putnbr(begin->val);
        ft_putstr("\n");
        begin = begin->next;
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