#include "main.h"

int	main(int ac, char *av[])
{
	t_option	option;
	int			i;

	if (ac > 1)
	{
		if (ac == 2)
			ft_one_argu(av[1], &option);
		else if (!ft_check_entry(ac - 1, &av[1], &option))
			ft_print_error();
		else
		{
			i = option.print + option.color + 1;
			ft_principal_push_swap(ac - i, &av[i], &option);
		}
		// system("leaks a.out");
	}
}
