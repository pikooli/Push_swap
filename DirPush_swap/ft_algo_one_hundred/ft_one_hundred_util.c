#include "main.h"
#include "ft_algo_one_hundred.h"


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

void        ft_help_tranch(t_list *a, t_list *b, t_option *option)
{
    ft_print_tranch(a);
    ft_print_finish_tranch(a);
    ft_printf("search next = ",ft_next_bigger_tranch(a, b));
    ft_printf("tranch on", a->tranch.mode);
    ft_printf("option mode : ", option->modetri);
}



int         ft_finish_tranch(t_list *a)
{
    if (a->begin->val < a->tranch.tranch1)
        return (a->tranch.tranch1finish);
    if (a->begin->val < a->tranch.tranch2)
        return (a->tranch.tranch2finish);
    if (a->begin->val < a->tranch.tranch3)
        return (a->tranch.tranch3finish);
    if (a->begin->val < a->tranch.tranch4)
        return (a->tranch.tranch4finish);
    if (a->begin->val < a->tranch.tranch5)
        return (a->tranch.tranch5finish);
    return (0);
}

void        ft_is_tranch(t_list *a, int val)
{
    a->tranch.mode = (val > a->tranch.tranch5) ? TRANCH5 : a->tranch.mode; 
    a->tranch.mode = (val < a->tranch.tranch5) ? TRANCH4 : a->tranch.mode; 
    a->tranch.mode = (val < a->tranch.tranch4)  ? TRANCH3 : a->tranch.mode; 
    a->tranch.mode = (val < a->tranch.tranch3) ? TRANCH2 : a->tranch.mode; 
    a->tranch.mode = (val < a->tranch.tranch2) ? TRANCH1 : a->tranch.mode; 
}

// make the tranch finish
void        ft_tranch_finish(t_list *a)
{
    a->tranch.tranch1finish = (a->tranch.mode == TRANCH1) ? TRUE :  a->tranch.tranch1finish; 
    a->tranch.tranch2finish = (a->tranch.mode == TRANCH2) ? TRUE :  a->tranch.tranch2finish;
    a->tranch.tranch3finish = (a->tranch.mode == TRANCH3) ? TRUE :  a->tranch.tranch3finish;
    a->tranch.tranch4finish = (a->tranch.mode == TRANCH4) ? TRUE :  a->tranch.tranch4finish;
    a->tranch.tranch5finish = (a->tranch.mode == TRANCH5) ? TRUE :  a->tranch.tranch5finish;
    a->tranch.mode = NOTHING;
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

int     ft_next_bigger_tranch(t_list *a, t_list *b)
{
    int tranch; 
    int i;

    i = 0;
    tranch = ft_return_tranch_val(a);
    if (!b->numb)
        return (tranch);
    while (i < 20)
    {
        tranch++;
        if ((ft_search_position_from_top(b->begin ,tranch) == 1000))
            return (tranch);
        i++;
    }
    return (1000);
}

void	ft_first_tranch(t_list *a)
{
	int ret;
    int tmp;

    if (a->tranch.mode != NOTHING)
        return ;

    ret = 1000;

    if (!a->tranch.tranch1finish)
    {
        ret = ft_search_position_from_top(a->begin, a->tranch.tranch1);
        a->tranch.mode = TRANCH1;
    }
    if (!a->tranch.tranch2finish)
    {
        tmp = ft_search_position_from_top(a->begin, a->tranch.tranch2);
        a->tranch.mode = tmp < ret ? TRANCH2 : a->tranch.mode;
        ret = tmp < ret ? tmp : ret;
    }
    if (!a->tranch.tranch3finish)
    {
        tmp = ft_search_position_from_top(a->begin, a->tranch.tranch3);
        a->tranch.mode = tmp < ret ? TRANCH3 : a->tranch.mode;
        ret = tmp < ret ? tmp : ret;
    }
    if (!a->tranch.tranch4finish)
    {
        tmp = ft_search_position_from_top(a->begin, a->tranch.tranch4);
        a->tranch.mode = tmp < ret ? TRANCH4 : a->tranch.mode;
        ret = tmp < ret ? tmp : ret;
    }
    if (!a->tranch.tranch5finish)
    {
        tmp = ft_search_position_from_top(a->begin, a->tranch.tranch5);
        a->tranch.mode = tmp < ret ? TRANCH5 : a->tranch.mode;
        ret = tmp < ret ? tmp : ret;
    }
    ft_printf("tranchmode ",a->tranch.mode);

}

void    ft_print_finish_tranch(t_list *a)
{
    ft_printf("tranch 1 ",a->tranch.tranch1finish);
    ft_printf("tranch 2 ",a->tranch.tranch2finish);
    ft_printf("tranch 3 ",a->tranch.tranch3finish);
    ft_printf("tranch 4 ",a->tranch.tranch4finish);
    ft_printf("tranch 5 ",a->tranch.tranch5finish);
}