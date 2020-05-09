#include "ft_algo_one_hundred.h"

char    *ft_algo_one_hundred(t_list *a, t_list *b, t_option *option)
{
    char *ret;

    if (ft_tranch_complete(a, b))
        ft_tranch_finish(a);

    ft_first_tranch(a);
    if ((ret = ft_final(a, b, option)))
        return (ret);
    if ((ret = ft_push_b_20(a, b, option)))
        return (ret);
    if ((ret = ft_search_next(a, b, option)))
        return (ret);
    return (ft_rra(a, option));
}

char    *ft_final(t_list *a, t_list *b, t_option *option)
{
    if (a->tranch.tranch1finish && a->tranch.tranch2finish &&
     a->tranch.tranch3finish && a->tranch.tranch4finish
     && a->tranch.tranch5finish)
        return(ft_pa(a , b,  option));
    return (NULL);
}

char    *ft_search_next(t_list *a, t_list *b, t_option *option)
{   
    char *ret;
    
    if ((ret = ft_rotate(a, option, ft_next_bigger_tranch(a, b))))
                return (ret);
    return (NULL);
}

char    *ft_push_b_20(t_list *a, t_list *b, t_option *option)
{
    if (a->begin->val == ft_next_bigger_tranch(a, b))
            return (ft_pb(a, b, option));
    return (NULL);
}

/*
** (void)a;
** (void)b;
** (void)option;
*/