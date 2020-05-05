#include "main.h"



int    ft_algo(t_list *a, t_list *b, t_option *option)
{
    t_instructions *instruct;

    if (!(instruct = ft_test_algo(a, b, option)))
        return FALSE;
    
    return TRUE;
}
