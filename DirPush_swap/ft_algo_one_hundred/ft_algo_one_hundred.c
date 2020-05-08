#include "ft_algo_one_hundred.h"

char    *ft_algo_one_hundred(t_list *a, t_list *b, t_option *option)
{
    char *ret;


    if ((ret = ft_push_b_20(a, b, option)))
        return (ret);

    if ((ret = ft_trie_20(a, b, option)))
        return (ret);

    return (NULL);
}

char    *ft_push_b_20(t_list *a, t_list *b, t_option *option)
{
    if (!ft_check_first_20(a->begin))
        if (!b->begin || b->numb < 20)
            return (ft_pb(a, b, option));

    return (NULL);
}


char    *ft_trie_20(t_list *a, t_list *b, t_option *option)
{
    (void)a;
    (void)b;
    
    (void)option;
    return (NULL);
}

/*
** (void)a;
** (void)b;
** (void)option;
*/