
#include "main.h"

void	ft_principal(int num, char **av, t_option option)
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
    if (option.print)
        ft_print_result(a, b);
	ft_free_list(a->begin);
	ft_free_list(b->begin);
	free(a);
	free(b);
}

int 	ft_one_argu(char *str, t_option *option)
{
	char **tab;
	int size;
    int i;

	if (!(tab = ft_split(str, ' ')))
		return ft_print_error();
	if (!(size = ft_tab_length(tab)))
    {
        ft_free_tab(tab);
		return 0;
    }
    if (!ft_check_entry(size, tab, option))
	{   
        ft_free_tab(tab);
    	return ft_print_error();
    }
    i = option->print + option->color;
    ft_principal(size - i, &tab[i], *option);
	ft_free_tab(tab);
	return 0;
}