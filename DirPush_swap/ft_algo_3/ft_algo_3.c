#include "ft_algo_3.h"

char *ft_algo_1_3(t_list *a, t_list *b, t_option *option)
{
    // ft_print_resultb(a, b, *option);
    char *rest;

    if ((rest = ft_b(a, b, option)))
        return (rest); 
    if ((rest = ft_a(a, b, option)))
        return (rest); 

    return (ft_ra(a, option));
}

char    *ft_b(t_list *a, t_list *b, t_option *option)
{
    if (b->begin)
    {   
        if (ft_check_rev_list(b))
            return (NULL);
        if (ft_bigger_in_list(b))
            return (NULL);
        if (b->begin->next && b->begin->val < b->begin->next->val)
            return (ft_sb(b, option));
        if (b->begin->val < b->last->val)
            return (ft_rrb(b, option));
    }
    return (NULL);
}

char    *ft_a(t_list *a, t_list *b, t_option *option)
{
    if (a->begin)
    {
       
    }
    return (NULL);
}

/*
** printf("\nbegin = %d last = %d\n",a->begin->val, a->last->val);
*/