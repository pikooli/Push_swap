
#include "main.h"

void	ft_principal_push_swap(int num, char **av, t_option *option)
{
	t_list *a;
	t_list *b;

	if (!(a = ft_list()))
		return;
	if (!(b = ft_list()))
	{
		free(a);
		return;
	}
	if (!(a->begin = ft_copy_av(num, av)))
	{
		free(a);
		free(b);
		ft_print_error();
		return;
	}
	a->numb = num;
	if (!ft_algo(a, b, option))
		ft_print_error();
	ft_free_list(a->begin);
	ft_free_list(b->begin);
	free(a);
	free(b);
}

