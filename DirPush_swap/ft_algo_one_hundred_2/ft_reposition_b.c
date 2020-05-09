#include "main.h"
#include "ft_algo_one_hundred_2.h"


char    *ft_reposition_b(t_list *a, t_list *b, t_option *option)
{
    if (b->begin->next)
        if (a->begin->val == b->begin->next->val - 1)
                return (ft_sb(b, option));
    if (a->begin->val == b->last->val + 1)
        return (ft_rb(b, option));
    ft_step(b, a->begin->val);
    return (NULL);
}

// char    *ft_best_position(t_list *b, int val)
// {

// }

int     ft_step(t_list *b, int val)
{
    int descstep;
    int ascstep;
    int valdesc;
    int valasc;

    descstep = ft_desc_step(b, val, &valdesc);
    ascstep = ft_asc_step(b, val, &valasc);
    ft_print_reposition_b(descstep, ascstep, valdesc, valasc);
    return (0);
}

int     ft_desc_step(t_list *b, int val, int *valdesc)
{
    int i;
    t_maille *tmp;
    int save_i;
    long save;

    *valdesc = b->begin->val;
    if (!b->begin->next)
        return (0);
    tmp = b->begin;
    i = 0;
    save_i = 0;
    save = -2147483648;
    while (tmp)
    {
        if (val > tmp->val && (long)tmp->val > save)
        {
            *valdesc = tmp->val;
            save = (long)tmp->val;
            save_i = i + 1;
        }    
        i++;
        tmp = tmp->next;
    }
    return (save_i);
}

int     ft_asc_step(t_list *b, int val, int *valasc)
{
    int i;
    t_maille *tmp;
    int save_i;
    long save;

    *valasc = b->last->val;
    if (!b->last->prev)
        return (0);
    tmp = b->last;
    i = 0;
    save_i = 0;
    save = -2147483648;
    while (tmp)
    {
        if (val > tmp->val && (long)tmp->val > save)
        {
            save_i = i + 1;
            save = (long)tmp->val;
            *valasc = tmp->val;
        }
        i++;
        tmp = tmp->prev;
    }
    return (save_i);
}

void    ft_print_reposition_b(int stepdesc, int stepasc, int valdesc, int valasc)
{
    ft_putstr("\n------- reposition -------\n");
    ft_printf("stepdesc repos", stepdesc);
    ft_printf("stepasc repos", stepasc);
    ft_printf("valdesc repos", valdesc);
    ft_printf("valasc repos", valasc);
}