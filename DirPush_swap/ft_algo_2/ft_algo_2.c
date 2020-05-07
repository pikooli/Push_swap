#include "ft_algo_2.h"


char *ft_algo_1_2(t_list *a, t_list *b, t_option *option)
{
    // printf("\nbegin = %d last = %d\n",a->begin->val, a->lastm->val);

    // ft_putstr("true\n");

    ft_print_resultb(a, b, *option);


    if ((ft_check_list(a) || !a->begin) && ft_check_rev_list(b))
        return (ft_pa(a , b, option));
    if (b->begin && a->begin && (a->begin->val == ft_smaller_in_list(a)) && ft_check_rev_list(b))
        return (ft_pb(a, b, option));
    if ((ft_check_list(a) || !a->begin) && b->begin)
    {
        if (ft_top_is_the_bigger(b))
        {
            if (b->begin->val < a->begin->val)    
                return (ft_pa(a, b, option));
            else
                if (a->numb > 1)
                    return (ft_ra(a, option));
        }
        else
            return (ft_rb(b, option));
    }
    if (a->begin)
    {
        if (!b->begin && a->begin->val == ft_smaller_in_list(a))
            return (ft_pb(a, b ,option));
        else if (a->begin->val > a->last->val && a->last->val == ft_smaller_in_list(a) && a->begin->val == ft_bigger_in_list(a))
            return (ft_ra(a, option));
        else if (a->begin->val > a->last->val && a->last->val == ft_smaller_in_list(a) && !ft_less_diff_b(a, b))
            return (ft_rra(a, option));
        else if (a->begin->next && a->begin->val > a->begin->next->val)
            return (ft_sa(a, option));
        else if (ft_less_diff_b(a, b))
            return (ft_pa(a, b, option));
        else if (ft_less_diff(a, a->last->val))
            return (ft_rra(a, option));
        else if (a->begin->next && a->begin->val > a->begin->next->val)
            return (ft_pb(a, b, option));
    }
    if (b->begin)
    {
        if (b->begin->next && b->begin->val < b->begin->next->val)
            return (ft_sb(b, option));
        else if (b->begin->val != ft_bigger_in_list(b))
            return (ft_rb(b, option));
        else if (a->begin->next && a->begin->val < a->begin->next->val)
            return (ft_ra(a, option));
    }
    return (ft_ra(a, option));
}



// printf("\nbegin = %d last = %d\n",a->begin->val, a->last->val);