#include "ft_algo_4.h"

char *ft_algo_1_4(t_list *a, t_list *b, t_option *option)
{
    char *rest;

    if ((rest = ft_only_a_4(a, b, option)))
        return (rest);
    if ((rest = ft_only_b_4(a, b, option)))
        return (rest); 
    if ((rest = ft_a_4(a, b, option)))
        return (rest);
    if ((rest = ft_b_4(a, b, option)))
        return (rest); 
    if ((rest = ft_a_b_4(a, b, option)))
        return (rest);
    // ft_putstr("----------end----------\n");
    return (ft_rra(a, option));
}

char    *ft_only_a_4(t_list *a, t_list *b, t_option *option)
{
    if (a->begin && !b->begin)
    {
        if (a->begin->val == ft_smaller_in_list(a))
            return (ft_pb(a, b, option));

        if (a->begin->next && a->begin->next->next && a->begin->val > a->begin->next->val &&
         a->begin->next->val > a->begin->next->next->val)
            return (ft_sa(a, option));

        if (a->begin->next && !a->begin->next->next && a->begin->val > a->begin->next->val)
            return (ft_sa(a, option));

        if (a->begin->val > a->last->val) 
            return (ft_rra(a, option));         

        if (a->begin->val == ft_bigger_in_list(a))
            return (ft_ra(a, option));
        
    }
    return (NULL);
}

char    *ft_a_4(t_list *a, t_list *b, t_option *option)
{
    (void)option;
    if (a->begin && b->begin)
    {   
        if (a->begin->next && a->begin->next->next && a->begin->val > a->begin->next->val &&
         a->begin->next->val > a->begin->next->next->val)
            return (ft_sa(a, option));

        if (a->begin->next && !a->begin->next->next && a->begin->val > a->begin->next->val)
            return (ft_sa(a, option));
    }
    return (NULL);
}

char    *ft_only_b_4(t_list *a, t_list *b, t_option *option)
{
    if (b->begin && !a->begin)
    {   
        if (ft_check_rev_list(b) && !a->begin)
            return (ft_pa(a, b, option));

        if (ft_bigger_in_list(b))
            return (ft_pa(a, b, option));

        if (b->begin->val < b->last->val)
            return (ft_rrb(b, option));

        if (b->begin->next)
        {
            if (b->begin->next && b->begin->val < b->begin->next->val)
                return (ft_sb(b, option));
        }
    }
    return (NULL);
}

char    *ft_b_4(t_list *a, t_list *b, t_option *option)
{
    if (a->begin && b->begin)
    {
        if (b->begin->next && b->begin->val < b->begin->next->val)
            return (ft_sb(b, option));
        
        if (b->begin->val == ft_smaller_in_list(b) && b->numb > 1)
            return (ft_rb(b, option));
        
        if (b->last->val == ft_bigger_in_list(b) && b->numb > 1)
            return (ft_rrb(b, option));

    }
    return (NULL);
}
char    *ft_a_b_4(t_list *a, t_list *b, t_option *option)
{
    if (a->begin && b->begin)
    {        
        
        if (ft_closer_small(a, b->begin->val) && ft_check_list(a))
            return (ft_pa(a, b, option));

        if (a->begin->next)
        {
            if (a->begin->next && a->begin->val > a->begin->next->val && ft_check_rev_list(b))
                return (ft_sa(a, option));
        
            if (a->begin->val > b->begin->val && ft_bigger_in_list(b) && !ft_check_list(a) &&
                 a->begin->next->val < a->begin->val && a->begin->val != a->big)
                return (ft_pb(a, b, option));
        }
        if (a->begin->val == ft_smaller_in_list(a) && ft_closer_big(a, b->begin->val))
            return (ft_pb(a, b, option));

        if (a->begin->val > a->last->val && b->begin->val < b->last->val) 
            return (ft_rrr(a, b, option));

        if (!(a->begin->val > a->last->val) && b->begin->val < b->last->val) 
            return (ft_rrb(b, option));

        if (a->begin->val > a->last->val && !(b->begin->val < b->last->val)) 
            return (ft_rra(a, option));

        if (ft_is_bigger(a, a->begin->val) && ft_is_bigger(b, a->begin->val))
            return (ft_rra(a, option));

    }
    return (NULL);
}



/*
** printf("\nbegin = %d last = %d\n",a->begin->val, a->last->val);
*/