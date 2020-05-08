#include "main.h"

void    ft_check_mode(t_list *a, t_option *option)
{
    int min;
    int i;

    i = 0;
    min = ft_smaller_in_list(a);
    while (ft_find_plusone(a, min) || min == -1)
    {
        min++;
        i++;
    }
    if (i == 100)
        option->modeinput = HUNDRED;
    else if (i == 500)
        option->modeinput = FIVEHUNDRED;
    else 
        option->modeinput = NOTHING;
}

int     ft_find_plusone(t_list *a, int val)
{
    t_maille *tmp;

    tmp = a->begin;
    while (tmp)
    {
        if (tmp->val == val + 1)
            return (val + 1);
        tmp = tmp->next;
    }
    return 0;
}