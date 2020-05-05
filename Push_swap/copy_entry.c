#include "main.h"

t_maille *ft_copy_av(int num, char *av[])
{
	int i;
	t_maille *begin;
	t_maille *tmp;

	i = 0;
	if (num == 0)
		return NULL;
    if (!(begin = ft_create_maille(i++, av)))
        return NULL;
	tmp = begin;
	while(i < num)
	{
		if (!(tmp->next = ft_create_maille(i++, av)))
			return ft_free_list(begin);
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
	return begin;
}

t_maille *ft_create_maille(int i, char **av)
{
    int val;
	long ret;

    ret = ft_atoi(av[i]);	
    if (ret < -2147483648 || ret > 2147483647)
        return NULL;
	val = (int)ret;
	return ft_new_elem(val);
}