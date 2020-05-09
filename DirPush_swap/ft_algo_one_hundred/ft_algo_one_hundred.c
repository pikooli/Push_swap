#include "ft_algo_one_hundred.h"

char    *ft_algo_one_hundred(t_list *a, t_list *b, t_option *option)
{
    char *ret;

    if ((ret = ft_search_next(a, b, option)))
        return (ret);
    if ((ret = ft_annex_b(a, b, option)))
        return (ret);
    if ((ret = ft_push_b_20(a, b, option)))
        return (ret);
    if ((ret = ft_trie_20(a, b, option)))
        return (ret);
    if ((ret = ft_push_a_20(a, b, option)))
        return ((ret));
    return (ft_rra(a, option));
}

char    *ft_search_next(t_list *a, t_list *b, t_option *option)
{   
    char *ret;

    if (b->numb < 20 && b->numb && option->modetri == NOTHING)
    {
            if ((ret = ft_rotate(a, option, ft_next_smaller_tranch(a, b))))
                return (ret);
    }
    return (NULL);
}

char    *ft_push_b_20(t_list *a, t_list *b, t_option *option)
{
    if (!ft_check_first_20(a->begin) && option->modetri == NOTHING)
    {
        if (!b->begin ||
        (a->begin->val == ft_next_smaller_tranch(a, b)))
        {
            ft_is_tranch(a, a->begin->val);
            return (ft_pb(a, b, option));
        }
    }
    return (NULL);
}

char    *ft_push_a_20(t_list *a, t_list *b, t_option *option)
{
    if (option->modetri == PUSH_A && b->numb)
    {
        if (ft_closer_big(a, b->begin->val))
        {
            if (b->numb == 1)
                    option->modetri = NOTHING;
            return (ft_pa(a, b, option));
        }
    }
    
    return (NULL);
}
char    *ft_annex_b(t_list *a, t_list *b, t_option *option)
{
    if (a && b->begin && option && b->begin->next)
        if (b->begin->val < b->begin->next->val)
            return (ft_sb(b, option));

    if (ft_check_rev_list(b) && b->numb == 20)
    {
            option->modetri = PUSH_A;
            ft_tranch_finish(a, a->tranch.mode);
    }
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