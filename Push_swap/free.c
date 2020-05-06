#include "main.h"

void		ft_free_instructions(t_instructions *instructions)
{
	t_instruction *begin;
	t_instruction *tmp;

	begin = instructions->first;
	while (begin)
	{
		tmp = begin->next;
		free(begin);
		begin = tmp;
	}
	ft_free_listall(instructions->a);
	ft_free_listall(instructions->b);
	free(instructions);
}

t_maille	*ft_free_list(t_maille *begin)
{
	t_maille *tmp;

	while (begin)
	{
		tmp = begin->next;
		free(begin);
		begin = tmp;
	}
	return (NULL);
}

void		*ft_free_listall(t_list *list)
{
	ft_free_list(list->begin);
	free(list);
	return (NULL);
}

int			ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (FALSE);
}

int			ft_strfree(char *str)
{
	free(str);
	return (FALSE);
}
