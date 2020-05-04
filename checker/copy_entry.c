#include "main.h"

t_maille *ft_create_element(int i, char **av);


t_maille *ft_copy_av(int num, char *av[])
{
	int i;
	t_maille *begin;
	t_maille *tmp;

	i = 0;
	if (num == 0)
		return NULL;
    if (!(begin = ft_create_element(i++, av)))
        return NULL;
	tmp = begin;
	while(i < num)
	{
		if (!(tmp->next = ft_create_element(i++, av)))
			return ft_free_list(begin);
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
	return begin;
}


t_maille *ft_create_element(int i, char **av)
{
    int val;
	int moins;

    if (ft_strcmp(av[i], "-2147483648"))
        val = -2147483648;
    else
    {
        moins = av[i][0] == '-' ? 1: 0; 
        val = ft_atoi(&av[i][moins]);	
        if (val < 0)
            return NULL;
        val = moins ? -val : val;
    }
	return ft_new_elem(val);
}