#include "main.h"
#include "ft_algo_one_hundred.h"



int		ft_algo(t_list *a, t_option *option)
{
	t_instructions *instruct;

	instruct = NULL;
	// if (!(instruct = ft_best_algo(a, instruct, option, &ft_algo_1_2)))
	// 	return (FALSE);
	// if (!(instruct = ft_best_algo(a, instruct, option, &ft_algo_1_3)))
	// 	return (FALSE);
	// if (!(instruct = ft_best_algo(a, instruct, option, &ft_algo_1_4)))
	// 	return (FALSE);
	if (option->modeinput == HUNDRED)
		if (!(instruct = ft_algo_suivie(a, instruct, option, &ft_algo_one_hundred)))
	 		return (FALSE);
	ft_print_step(instruct);
	// ft_print_instruction(instruct, *option);
	ft_free_instructions(instruct);
	return (TRUE);
}

t_instructions *ft_best_algo(t_list *a, t_instructions *instruct, t_option *option, char *(*algo)(t_list *, t_list *, t_option *))
{
	t_instructions *tmp;

	if (!(tmp = ft_prepare_algo(a, option, (*algo))))
	{
		ft_free_instructions(instruct);
		return (NULL);
	}
	if (instruct)
	{
		if (instruct->numb > tmp->numb)
		{
	         ft_free_instructions(instruct);
	         instruct = tmp;
		}
		else 
			ft_free_instructions(tmp);
	}
	else 
		instruct = tmp;
	return instruct;
}

t_instructions *ft_algo_suivie(t_list *a, t_instructions *instruct, t_option *option, char *(*algo)(t_list *, t_list *, t_option *))
{
	t_instructions *tmp;

	if (option->modeinput == HUNDRED)
		ft_prepare_tranch_hundred(a);
	option->modetri = NOTHING;
	if (!(tmp = ft_prepare_algo(a, option, (*algo))))
	{
		ft_free_instructions(instruct);
		return (NULL);
	}
	if (instruct)
	{
		if (instruct->numb > tmp->numb)
		{
	         ft_free_instructions(instruct);
	         instruct = tmp;
		}
		else 
			ft_free_instructions(tmp);
	}
	else 
		instruct = tmp;
	return instruct;
}

void	ft_prepare_tranch_hundred(t_list *a)
{
	int diff;

	diff = (a->numb / 5);
	a->tranch.tranch1 = a->small + diff;
	a->tranch.tranch1finish = FALSE;
	a->tranch.tranch2 = a->small + diff * 2;
	a->tranch.tranch2finish = FALSE;
	a->tranch.tranch3 = a->small + diff * 3;
	a->tranch.tranch3finish = FALSE;
	a->tranch.tranch4 = a->small + diff * 4;
	a->tranch.tranch4finish = FALSE;
	a->tranch.tranch5 = a->small + diff * 5;
	a->tranch.tranch5finish = FALSE;
	a->tranch.mode = NOTHING;
}

void	ft_prepare_tranch_five_hundred(t_list *a)
{
	a->tranch.tranch1 = a->small + (a->numb / 11);
	a->tranch.tranch1finish = FALSE;
	a->tranch.tranch2 = a->small + (a->numb / 11) * 2;
	a->tranch.tranch2finish = FALSE;
	a->tranch.tranch3 = a->small + (a->numb / 11) * 3;
	a->tranch.tranch3finish = FALSE;
	a->tranch.tranch4 = a->small + (a->numb / 11) * 4;
	a->tranch.tranch4finish = FALSE;
	a->tranch.tranch5 = a->small + (a->numb / 11) * 5;
	a->tranch.tranch5finish = FALSE;
	a->tranch.tranch6 = a->small + (a->numb / 11) * 6;
	a->tranch.tranch6finish = FALSE;
	a->tranch.tranch7 = a->small + (a->numb / 11) * 7;
	a->tranch.tranch7finish = FALSE;
	a->tranch.tranch8 = a->small + (a->numb / 11) * 8;
	a->tranch.tranch8finish = FALSE;
	a->tranch.tranch9 = a->small + (a->numb / 11) * 9;
	a->tranch.tranch9finish = FALSE;
	a->tranch.tranch10 = a->small + (a->numb / 11) * 10;
	a->tranch.tranch10finish = FALSE;
	a->tranch.tranch11 = a->small + (a->numb / 11) * 11;
	a->tranch.tranch11finish = FALSE;
	a->tranch.mode = NOTHING;
}
