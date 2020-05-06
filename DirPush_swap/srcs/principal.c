#include "main.h"

void	ft_principal_push_swap(int num, char **av, t_option *option)
{
	t_list *a;

	if (!(a = ft_list()))
		return ;
	if (!(a->begin = ft_copy_av(num, av)))
	{
		free(a);
		ft_print_error();
		return ;
	}
	a->last = ft_last_list(a);
	a->numb = num;
	if (!ft_algo(a, option))
		ft_print_error();
	ft_free_list(a->begin);
	free(a);
}
