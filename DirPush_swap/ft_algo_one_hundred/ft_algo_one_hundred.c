#include "ft_algo_one_hundred.h"

char    *ft_algo_one_hundred(t_list *a, t_list *b, t_option *option)
{
    char *ret;

    ft_first_tranch(a);
    ft_help_tranch(a, b, option);

    if ((ret = ft_final(a, b, option)))
        return (ret);

    if ((ret = ft_push_a_20(a, b, option)))
        return ((ret));
    
    if ((ret = ft_push_b_20(a, b, option)))
        return (ret);

    if ((ret = ft_search_next(a, b, option)))
        return (ret);

    if ((ret = ft_annex_b(a, b, option)))
        return (ret);

    return (ft_rra(a, option));
}

char    *ft_final(t_list *a, t_list *b, t_option *option)
{
    (void)b;
    if (a->tranch.tranch1finish && a->tranch.tranch2finish &&
     a->tranch.tranch3finish && a->tranch.tranch4finish
     && a->tranch.tranch5finish)
        return(ft_ra(a , option));
    return (NULL);
}

char    *ft_search_next(t_list *a, t_list *b, t_option *option)
{   
    char *ret;

    if (b->numb < 20 && option->modetri == NOTHING)
            if ((ret = ft_rotate(a, option, ft_next_bigger_tranch(a, b))))
                return (ret);
    if (option->modetri == PUSH_A && b->begin->val != a->big)
        if ((ret = ft_rotate(a, option, b->begin->val - 1)))
                return (ret);
    return (NULL);
}

char    *ft_push_b_20(t_list *a, t_list *b, t_option *option)
{
    if (!ft_finish_tranch(a) && option->modetri == NOTHING && b->numb < 20)
    {
        if (a->begin->val == ft_next_bigger_tranch(a, b))
            return (ft_pb(a, b, option));
    }
    return (NULL);
}

char    *ft_push_a_20(t_list *a, t_list *b, t_option *option)
{
    if (option->modetri == PUSH_A)
    {
        if (ft_closer_big(a, b->begin->val) || b->begin->val == a->small)
        {
            if (b->numb == 1)
            {
                option->modetri = NOTHING;
                ft_tranch_finish(a);
            }
            return (ft_pa(a, b, option));
        }
    }
    return (NULL);
}
char    *ft_annex_b(t_list *a, t_list *b, t_option *option)
{
    if (b->numb >= 20 && option->modetri == NOTHING)
    {
            ft_printf("push_a ", a->tranch.mode);
            option->modetri = PUSH_A;
    }
    return (NULL);
}


/*
** (void)a;
** (void)b;
** (void)option;
*/