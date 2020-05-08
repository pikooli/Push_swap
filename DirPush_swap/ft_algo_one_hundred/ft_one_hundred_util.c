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

int         ft_finish_tranch(t_list *a)
{
    if (a->begin->val >= a->tranch.tranch1 && a->begin->val < a->tranch.tranch2)
        return (a->tranch.tranch1finish);
    if (a->begin->val >= a->tranch.tranch2 && a->begin->val < a->tranch.tranch3)
        return (a->tranch.tranch2finish);
    if (a->begin->val >= a->tranch.tranch3 && a->begin->val < a->tranch.tranch4)
        return (a->tranch.tranch3finish);
    if (a->begin->val >= a->tranch.tranch4 && a->begin->val < a->tranch.tranch5)
        return (a->tranch.tranch4finish);
    if (a->begin->val >= a->tranch.tranch5)
        return (a->tranch.tranch5finish);
    return (0);
}