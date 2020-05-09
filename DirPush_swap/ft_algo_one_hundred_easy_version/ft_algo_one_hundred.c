#include "ft_algo_one_hundred_easy_version.h"

char    *ft_algo_one_hundred(t_list *a, t_list *b, t_option *option)
{
    char *ret;

    if (a->numb == 1)
        option->modetri = PUSH_A;

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
    if (option->modetri == PUSH_A)
        return(ft_pa(a , b,  option));
    return (NULL);
}

char    *ft_search_next(t_list *a, t_list *b, t_option *option)
{   
    char *ret;
    
    if ((ret = ft_rotate(a, option, ft_next_bigger(a, b))))
                return (ret);
    return (NULL);
}

char    *ft_push_b_20(t_list *a, t_list *b, t_option *option)
{
    if (a->begin->val == ft_next_bigger(a, b))
            return (ft_pb(a, b, option));
    return (NULL);
}

/*
** (void)a;
** (void)b;
** (void)option;
*/