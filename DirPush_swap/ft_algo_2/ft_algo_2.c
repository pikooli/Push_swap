#include "ft_algo_2.h"

char *ft_algo_1_2(t_list *a, t_list *b, t_option *option)
{
    ft_print_resultb(a ,b, *option);
    // char *result;

    ft_check_rev_list(a) && !b->begin ?option->modetri = REVA : 0;
    // if (option->modetri == REVA)
        // return ft_rra(a, option);
    return NULL;
}
