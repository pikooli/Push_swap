#include "main.h"

char *ft_algo_b(t_list *a, t_list *b, t_option *option);


char *ft_algo_1_1(t_list *a, t_list *b, t_option *option)
{
    ft_print_result(a ,b, *option);
    
    if (a->begin && a->begin->next && a->begin->val < a->begin->next->val)
        return ft_pb(a, b, option);
    if (a->begin && a->begin->next &&  a->begin->val > a->begin->next->val)
        return ft_ra(a, option);
    if(b->begin && a->begin->val > b->begin->val)
        return ft_pa(a ,b , option);
    return ft_rrr(a, b, option);
}

char *ft_algo_b(t_list *a, t_list *b, t_option *option)
{
    if (!b->begin)
        return NULL;
    if (a->begin && b->begin->val < a->begin->val)
        return ft_pa(a ,b , option);
    return NULL;
}