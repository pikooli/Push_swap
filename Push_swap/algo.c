#include "main.h"

int		ft_algo(t_list *a, t_option *option)
{
	t_instructions *instruct;
	t_instructions *tmp;

	if (!(instruct = ft_prepare_algo(a, option, &ft_algo_1_1)))
		return (FALSE);
	// if (instruct->numb > tmp->numb)
	// {
	//         ft_free_instructions(instruct);
	//         instruct = tmp;
	// }
	ft_print_instruction(instruct, *option);
	if (option->print)
		ft_print_result(instruct, *option);
	ft_free_instructions(instruct);
	return (TRUE);
}
