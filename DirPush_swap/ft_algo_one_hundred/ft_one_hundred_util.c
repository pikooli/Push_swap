#include "main.h"

int 		ft_r_or_rr(t_list *list, int val)
{
	int ret;

	if ((ret = ft_search_position_from_top(list->begin, val + 1)) == 1000)
		return (0);
    if (ret == 0)
        return (0);
    if (((list->numb / 2) - ret) == 0)
        return (1);
	return ((list->numb / 2) - ret);
}