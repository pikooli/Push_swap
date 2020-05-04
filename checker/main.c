#include "main.h"

void	ft_principal(int num, char **av);
int 	ft_one_argu(char *str);

int main(int ac, char *av[])
{
	if (ac > 1)
	{
		if (ac == 2)
			ft_one_argu(av[1]);
		else if (!ft_check_entry(ac -1, &av[1]))
				return ft_print_error();
		else 
			ft_principal(ac - 1, &av[1]);
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
	{
		free(a);
		free(b);
		ft_print_error();
		return;
	}
	a->numb = num;
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

int 	ft_one_argu(char *str)
{
	char **tab;
	int size;

	if (!(tab = ft_split(str, ' ')))
		return ft_print_error();
	if (!(size = ft_tab_length(tab)))
		return 0;
	if (!ft_check_entry(size, tab))
			ft_print_error();
	else
		ft_principal(size, tab);
	ft_free_tab(tab);
	return 0;
}