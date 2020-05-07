#include "ft_algo_3.h"

char *ft_algo_1_3(t_list *a, t_list *b, t_option *option)
{
    ft_print_resultb(a, b, *option);

    char *rest;

    if ((rest = ft_only_a_3(a, b, option)))
        return (rest);
    if ((rest = ft_a_3(a, b, option)))
        return (rest);
    if ((rest = ft_a_b_3(a, b, option)))
        return (rest);

    if ((rest = ft_b_3(a, b, option)))
        return (rest); 

    return (ft_ra(a, option));
    printf("salut\n");
}

char    *ft_only_a_3(t_list *a, t_list *b, t_option *option)
{
    if (ft_check_list(a))
            return (NULL);
    if (a->begin && !b->begin)
    {
        if (a->begin->val > a->begin->next->val)
            return (ft_sa(a, option));

        if (a->begin->val == ft_smaller_in_list(a))
            return (ft_pb(a, b, option));

        if (a->begin->next && a->begin->val > a->begin->next->val)
            return (ft_sa(a, option));

        if (a->begin->val > a->last->val)
            return (ft_rra(a, option));         

        if (ft_bigger_in_list(a))
            return (ft_pb(a, b, option));
    }
    return (NULL);
}

char    *ft_a_3(t_list *a, t_list *b, t_option *option)
{
    (void)b;
    if (a->begin)
    {
        if (a->begin->next && a->begin->val > a->begin->next->val)
            return (ft_sa(a, option));
    }
    return (NULL);
}

char    *ft_a_b_3(t_list *a, t_list *b, t_option *option)
{
    (void)option;
    if (a->begin && b->begin)
    {
        
    }
    return (NULL);
}

char    *ft_b_3(t_list *a, t_list *b, t_option *option)
{
    if (b->begin)
    {   
        if (ft_check_rev_list(b) && !a->begin)
            return (ft_pa(a, b, option));

        if (ft_check_rev_list(b) && ft_check_list(a) &&
         b->begin->val < a->begin->val)
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


/*
** printf("\nbegin = %d last = %d\n",a->begin->val, a->last->val);
*/