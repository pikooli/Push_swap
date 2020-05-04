#include "main.h"

void	ft_principal(int num, char **av);


int main(int ac, char *av[])
{
	if (ac > 1)
	{
		if (!ft_check_entry(ac, av))
		{
				ft_print_error();
				return 0;
		}
		ft_principal(ac, av);
		system("leaks a.out");
	}
}

void	ft_principal(int num, char **av)
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
		return;
	a->numb = num - 1;
	if (!ft_instruction(a, b))
		ft_print_error();
	// ft_putstr("list a\n");
	// ft_print_list(a->begin);
	// ft_putstr("list b\n");
	// ft_print_list(b->begin);

	ft_free_list(a->begin);
	ft_free_list(b->begin);
	free(a);
	free(b);
}