#include "main.h"

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
    ft_principal_push_swap(size - i, &tab[i], option);
	ft_free_tab(tab);
	return 0;
}
