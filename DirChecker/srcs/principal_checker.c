#include "main.h"

void	ft_principal_checker(int num, char **av, t_option *option)
{
	t_list *a;
	t_list *b;

	if (!(a = ft_list()))
		return ;
	if (!(b = ft_list()))
	{
		free(a);
		return ;
	}
	if (!(a->begin = ft_copy_av(num, av)))
	{
		free(a);
		free(b);
		ft_print_error();
		return ;
	}
	a->numb = num;
	!ft_instruction(a, b, option) ? ft_print_error() : 0;
	option->print ? ft_print_result(a, b, *option) : 0;
	ft_free_list(a->begin);
	ft_free_list(b->begin);
	free(a);
	free(b);
}
