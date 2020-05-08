#include "main.h"

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

	option->modetri = BEGIN;
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