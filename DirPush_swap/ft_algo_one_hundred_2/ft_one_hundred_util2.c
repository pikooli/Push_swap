#include "main.h"
#include "ft_algo_one_hundred_2.h"

int     ft_next_numb(t_list *a, t_list *b)
{
    int stepdesc;
    int ascstep;
    int nmbdesc;
    int nmbasc;
    (void)b;

    nmbdesc = ft_next_numb_desc(a, &stepdesc);
    nmbasc = ft_next_numb_asc(a, &ascstep);

    ft_putstr("--------next bumber to b-------\n");
    ft_printf("nmbdesc ", nmbdesc);
    ft_printf("stepdesc ", stepdesc);
    ft_printf("nmbasc ", nmbasc);
    ft_printf("ascstep ", ascstep);
    if (ascstep > stepdesc)
        ft_printf("number choise = ", nmbdesc);
    else
        ft_printf("number choise = ", nmbasc);
    

    if (ascstep == 1000 && stepdesc == 1000)
        return (1000);
    if (ascstep > stepdesc)
        return (nmbdesc);
    else
        return (nmbasc);
}

int     ft_next_numb_desc(t_list *a, int *stepdesc)
{
    int nmbdesc;

    nmbdesc = 1000;
    nmbdesc = a->tranch.mode == TRANCH1 ? 
    ft_first_numb_btw_desc(a, a->tranch.tranch1, a->tranch.tranch1 + 19, stepdesc) : nmbdesc;
    nmbdesc = a->tranch.mode == TRANCH2 ? 
    ft_first_numb_btw_desc(a, a->tranch.tranch2, a->tranch.tranch2 + 19, stepdesc) : nmbdesc;
    nmbdesc = a->tranch.mode == TRANCH3 ? 
    ft_first_numb_btw_desc(a, a->tranch.tranch3, a->tranch.tranch3 + 19, stepdesc) : nmbdesc;
    nmbdesc = a->tranch.mode == TRANCH4 ? 
    ft_first_numb_btw_desc(a, a->tranch.tranch4, a->tranch.tranch4 + 19, stepdesc) : nmbdesc;
    nmbdesc = a->tranch.mode == TRANCH5 ? 
    ft_first_numb_btw_desc(a, a->tranch.tranch5, a->tranch.tranch5 + 19, stepdesc) : nmbdesc;

    return (nmbdesc);
}

int     ft_next_numb_asc(t_list *a, int *ascstep)
{
    int nmbasc;

    nmbasc = 1000;
    nmbasc = a->tranch.mode == TRANCH1 ? 
    ft_first_numb_btw_asc(a, a->tranch.tranch1, a->tranch.tranch1 + 19, ascstep) : nmbasc;
    nmbasc = a->tranch.mode == TRANCH2 ? 
    ft_first_numb_btw_asc(a, a->tranch.tranch2, a->tranch.tranch2 + 19, ascstep) : nmbasc;
    nmbasc = a->tranch.mode == TRANCH3 ? 
    ft_first_numb_btw_asc(a, a->tranch.tranch3, a->tranch.tranch3 + 19, ascstep) : nmbasc;
    nmbasc = a->tranch.mode == TRANCH4 ? 
    ft_first_numb_btw_asc(a, a->tranch.tranch4, a->tranch.tranch4 + 19, ascstep) : nmbasc;
    nmbasc = a->tranch.mode == TRANCH5 ? 
    ft_first_numb_btw_asc(a, a->tranch.tranch5, a->tranch.tranch5 + 19, ascstep) : nmbasc;  

    return (nmbasc);
}


int     ft_first_numb_btw_desc(t_list *a, int min, int max, int *step)
{
    t_maille *tmp;
    int i;

    tmp = a->begin;
    i = 0;
    while (tmp)
    {
        *step = i;
        if (tmp->val >= min && tmp->val <= max)
            return (tmp->val);
        tmp = tmp->next;
        i++;
    }
    return (1000);
}

int     ft_first_numb_btw_asc(t_list *a, int min, int max, int *step)
{
    t_maille *tmp;
    int i;

    tmp = a->last;
    i = 0;
    while (tmp)
    {
        *step = i;
        if (tmp->val >= min && tmp->val <= max)
            return (tmp->val);
        tmp = tmp->prev;
        i++;
    }
    return (1000);
}