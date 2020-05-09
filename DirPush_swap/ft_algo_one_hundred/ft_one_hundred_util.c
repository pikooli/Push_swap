#include "main.h"
#include "ft_algo_one_hundred.h"


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

void        ft_is_tranch(t_list *a, int val)
{
    a->tranch.mode = (val >= a->tranch.tranch1 && val < a->tranch.tranch2) ? TRANCH1 : a->tranch.mode; 
    a->tranch.mode = (val >= a->tranch.tranch2 && val < a->tranch.tranch3) ? TRANCH2 : a->tranch.mode; 
    a->tranch.mode = (val >= a->tranch.tranch3 && val < a->tranch.tranch4) ? TRANCH3 : a->tranch.mode; 
    a->tranch.mode = (val >= a->tranch.tranch4 && val < a->tranch.tranch5) ? TRANCH4 : a->tranch.mode; 
    a->tranch.mode = (val > a->tranch.tranch5) ? TRANCH5 : a->tranch.mode; 
}

// make the tranch finish
void        ft_tranch_finish(t_list *a, int mode)
{
    a->tranch.tranch1finish = (mode == TRANCH1) ? TRUE :  a->tranch.tranch1finish; 
    a->tranch.tranch2finish = (mode == TRANCH2) ? TRUE :  a->tranch.tranch2finish;
    a->tranch.tranch3finish = (mode == TRANCH3) ? TRUE :  a->tranch.tranch3finish;
    a->tranch.tranch4finish = (mode == TRANCH4) ? TRUE :  a->tranch.tranch4finish;
    a->tranch.tranch5finish = (mode == TRANCH5) ? TRUE :  a->tranch.tranch5finish;
    a->tranch.mode = NOTHING;
}

int         ft_is_in_tranch(t_list *a)
{
    if (a->tranch.mode == NOTHING)
        return (TRUE);
    if (a->tranch.mode == TRANCH1 && a->begin->val > a->tranch.tranch1 &&
    a->begin->val < a->tranch.tranch2)
        return (TRUE);
    if (a->tranch.mode == TRANCH2 && a->begin->val > a->tranch.tranch2 &&
    a->begin->val < a->tranch.tranch3)
        return (TRUE);
    if (a->tranch.mode == TRANCH3 && a->begin->val > a->tranch.tranch3 &&
    a->begin->val < a->tranch.tranch4)
        return (TRUE);
    if (a->tranch.mode == TRANCH4 && a->begin->val > a->tranch.tranch4 &&
    a->begin->val < a->tranch.tranch5)
        return (TRUE);
    if (a->tranch.mode == TRANCH5 && a->begin->val > a->tranch.tranch5)
        return (TRUE);
    return (FALSE);
}

void        ft_print_tranch_step(t_list *a)
{
    a->tranch.mode == TRANCH1 ? ft_putstr("-------- tranch 1 ------\n") : 0;
    a->tranch.mode == TRANCH2 ? ft_putstr("-------- tranch 2 ------\n") : 0;
    a->tranch.mode == TRANCH3 ? ft_putstr("-------- tranch 3 ------\n") : 0;
    a->tranch.mode == TRANCH4 ? ft_putstr("-------- tranch 4 ------\n") : 0;
    a->tranch.mode == TRANCH5 ? ft_putstr("-------- tranch 5 ------\n") : 0;
}

void	ft_print_tranch(t_list *a)
{
	ft_putstr("----------- tranche --------\n");
	ft_putnbr(a->tranch.tranch1);
	ft_putstr("\n");
	ft_putnbr(a->tranch.tranch2);
	ft_putstr("\n");
	ft_putnbr(a->tranch.tranch3);
	ft_putstr("\n");
	ft_putnbr(a->tranch.tranch4);
	ft_putstr("\n");
	ft_putnbr(a->tranch.tranch5);
	ft_putstr("\n");
}

int     ft_smaller_tranch_inside(t_list *a, t_list *b)
{
    int smaller;
    int ret;

    if (a->tranch.mode == NOTHING)
        return (FALSE);
    
    smaller = a->tranch.tranch1 - 1;
    smaller = a->tranch.mode == TRANCH1 ? a->tranch.tranch1 : smaller;
    smaller = a->tranch.mode == TRANCH2 ? a->tranch.tranch2 : smaller;
    smaller = a->tranch.mode == TRANCH3 ? a->tranch.tranch3 : smaller;
    smaller = a->tranch.mode == TRANCH4 ? a->tranch.tranch4 : smaller;
    smaller = a->tranch.mode == TRANCH5 ? a->tranch.tranch5 : smaller;
    
    ret = ft_search_position_from_top(b->begin, smaller);
    if (ret == 1000)
        return (FALSE);
    return (TRUE);
}

char    *ft_rotate(t_list *list, t_option *option, int val)
{   
    int ret;
    if (list->begin->val == val)
        return (NULL);
    ret = ft_r_or_rr(list, val);
    if (ret < 0)
        return (ft_rra(list, option));
    else if (ret > 0)
        return (ft_ra(list, option));
    return (NULL);
}

int     ft_return_tranch_val(t_list *a)
{
    if (a->tranch.mode == TRANCH1)
        return (a->tranch.tranch1);
    if (a->tranch.mode == TRANCH2)
        return (a->tranch.tranch2);
    if (a->tranch.mode == TRANCH3)
        return (a->tranch.tranch3);
    if (a->tranch.mode == TRANCH4)
        return (a->tranch.tranch4);
    return (a->tranch.tranch5);
}

int     ft_next_smaller_tranch(t_list *a, t_list *b)
{
    int tranch; 
    int i;

    i = 0;
    tranch = ft_return_tranch_val(a);
    if ((ft_search_position_from_top(b->begin ,tranch) == 1000))
        return (tranch);
    while (i < 20)
    {
        tranch++;
        if ((ft_search_position_from_top(b->begin ,tranch) == 1000))
            return (tranch);
    }
    return (1000);
}

