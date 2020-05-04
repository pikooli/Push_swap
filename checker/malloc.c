#include "main.h"


t_list *ft_list()
{
	t_list *ret;

	if (!(ret = malloc(sizeof(t_list))))
		return NULL;
	ret->numb = 0;
	ret->begin = NULL;
	return ret;
}


t_maille *ft_copy_av(int num, char *av[])
{
	int i;
	int val;
	t_maille *begin;
	t_maille *tmp;

	i = 1;
	if (num == 1)
		return NULL;
	val = ft_atoi(av[i++]);
	if (!(begin = ft_new_elem(val)))
		return NULL;
	tmp = begin;
	while(i < num)
	{
		val = ft_atoi(av[i++]);
		if (!(tmp->next = ft_new_elem(val)))
			return ft_free_list(begin);
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
	return begin;
}

t_maille *ft_new_elem(int val)
{
	t_maille *new;

	if (!(new = malloc(sizeof(t_maille))))
		return NULL;
	new->val = val;
	new->next = NULL;
	new->prev = NULL;
	return new;
}

char *ft_substr(char *str)
{
	int i;
	char *ret;

	if (str == NULL)
		return NULL;
	i = 0;
	while(str[i])
		i++;
	if (!(ret = malloc(sizeof(char) * (i + 1))))
		return NULL;
	i = -1;
	while (str[++i])
		ret[i] = str[i];
	ret[i] = str[i];
	return ret;
}
