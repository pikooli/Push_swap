#include "main.h"

int		ft_algo(t_list *a, t_option *option)
{
	t_instructions *instruct;
	t_instructions *tmp;

	(void)tmp;
	if (!(instruct = ft_prepare_algo(a, option, &ft_algo_1_1)))
		return (FALSE);
	if (!(instruct = ft_best_algo(a, instruct, option, &ft_algo_1_2)))
		return (FALSE);
	ft_print_step(instruct);
	// ft_print_instruction(instruct, *option);
	// if (option->print)
	// 	ft_print_result(instruct, *option);
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
	if (instruct->numb > tmp->numb)
	{
	         ft_free_instructions(instruct);
	         instruct = tmp;
	}
	else 
		ft_free_instructions(tmp);
	return instruct;
}