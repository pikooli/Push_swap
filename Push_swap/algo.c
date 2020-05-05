#include "main.h"


void    ft_algo(t_list *a, t_list *b, t_option *option)
{
    if (ft_check_final(a, b))
        return ;
    ft_sa(a, option);
    ft_algo(a, b, option);
}