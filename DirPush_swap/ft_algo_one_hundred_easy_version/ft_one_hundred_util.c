#include "main.h"
#include "ft_algo_one_hundred_easy_version.h"


char    *ft_rotate(t_list *list, t_option *option, int val)
{   
    int ret;

    if (val == 1000)
        return (NULL);
    if (list->begin->val == val)
        return (NULL);
    ret = ft_r_or_rr(list, val);
    if (ret < 0)
        return (ft_rra(list, option));
    else if (ret > 0)
        return (ft_ra(list, option));
    return (NULL);
}

int 		ft_r_or_rr(t_list *list, int val)
{
	int ret;

	if ((ret = ft_search_position_from_top(list->begin, val)) == 1000)
		return (0);
    if (ret == 0)
        return (0);
    if (((list->numb / 2) - ret) == 0)
        return (1);
	return ((list->numb / 2) - ret);
}

int     ft_next_bigger(t_list *a, t_list *b)
{
    int tranch; 
    int i;

    i = 0;
    tranch = b->begin ? b->begin->val + 1 : a->small;
    return (tranch);
}