
#include "main.h"

void	ft_principal(int num, char **av, int option)
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
    if (option)
        ft_print_result(a, b);
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
    {
        ft_free_tab(tab);
		return 0;
    }
    if (ft_strcmp(tab[0], "-v"))
	{
        if (!ft_check_entry(size - 1, &tab[1]))
			ft_print_error();
		else 
            ft_principal(size - 1, &tab[1], TRUE);
    }
    else
    {
        if (!ft_check_entry(size, tab))
			ft_print_error();
        else
            ft_principal(size, tab, FALSE);
    }
	ft_free_tab(tab);
	return 0;
}