#include "ft_algo_one_hundred.h"

char    *ft_algo_one_hundred(t_list *a, t_list *b, t_option *option)
{
    char *ret;

    if ((ret = ft_rotate(a, b, option)))
        return (ret);
    if ((ret = ft_push_b_20(a, b, option)))
        return (ret);
    if ((ret = ft_annex_b(a, b, option)))
        return (ret);
    if ((ret = ft_trie_20(a, b, option)))
        return (ret);
    if ((ret = ft_push_a_20(a, b, option)))
        return ((ret));
    return (ft_rra(a, option));
}

char    *ft_rotate(t_list *a, t_list *b, t_option *option)
{   
    int ret;

    if (b->numb < 20 && b->numb && option->modetri == NOTHING)
    {
        if (a->begin->val == b->begin->val + 1)
            return (NULL);
        ret = ft_r_or_rr(a, b->begin->val);
        if (ret < 0)
            return (ft_rra(a, option));
        else if (ret > 0)
            return (ft_ra(a, option));
    }
    return (NULL);
}


char    *ft_push_b_20(t_list *a, t_list *b, t_option *option)
{
    if (!ft_check_first_20(a->begin) && option->modetri == NOTHING)
    {
        if (!b->begin || (b->numb < 20 && ft_closer_big(a, b->begin->val) && !ft_finish_tranch(a)))
            return (ft_pb(a, b, option));
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
    if (a && b && option)
    if (b->numb == 20 && !ft_check_rev_list(b))
        if (b->begin->val < b->last->val)
            return (ft_rb(b, option));

    if (ft_check_rev_list(b) && b->numb == 20)
        option->modetri = PUSH_A;
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