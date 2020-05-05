#include "main.h"



int main(int ac, char *av[])
{
	if (ac > 1)
	{
		if (ac == 2)
			ft_one_argu(av[1]);
		else if (ft_strcmp(av[1], "-v"))
		{
			if (!ft_check_entry(ac -2, &av[2]))
				return ft_print_error();
			ft_principal(ac - 2, &av[2], TRUE);
		}
		else 
		{
			if (!ft_check_entry(ac -1, &av[1]))
				return ft_print_error();
			ft_principal(ac - 1, &av[1], FALSE);
		}
		// system("leaks a.out");
	}
}
