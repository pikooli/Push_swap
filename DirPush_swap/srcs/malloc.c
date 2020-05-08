#include "main.h"

t_list			*ft_list(void)
{
	t_list *ret;

	if (!(ret = malloc(sizeof(t_list))))
		return (NULL);
	ret->numb = 0;
	ret->begin = NULL;
	ret->last = NULL;
	return (ret);
}

t_maille		*ft_new_elem(int val)
{
	t_maille *new;

	if (!(new = malloc(sizeof(t_maille))))
		return (NULL);
	new->val = val;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

char			*ft_substr(char *str)
{
	int		i;
	char	*ret;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	if (!(ret = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (str[++i])
		ret[i] = str[i];
	ret[i] = str[i];
	return (ret);
}

int				ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_append(char *str1, char *str2)
{
	int i;
	int j;
	char*dest;

	i = ft_strlen(str1);
	j = ft_strlen(str2);
	if (!(dest = malloc(sizeof(char) * (i + j + 1))))
	{
		free(str1);
		return (NULL);
	}
	i = -1;
	while (str1[++i])
		dest[i] = str1[i];
	j = 0;
	while (str2[j])
		dest[i++] = str2[j++];
	dest[i] = '\0';
	free(str1);
	return (dest);
}

t_maille		*ft_copy_list(t_maille *first)
{
	t_maille *begin;
	t_maille *tmp;

	if (!(begin = ft_new_elem(first->val)))
		return (NULL);
	tmp = begin;
	first = first->next;
	while (first)
	{
		if (!(tmp->next = ft_new_elem(first->val)))
			return (ft_free_list(begin));
		tmp->next->prev = tmp;
		first = first->next;
		tmp = tmp->next;
	}
	return (begin);
}

t_instructions	*ft_create_instructions(void)
{
	t_instructions *ret;

	if (!(ret = malloc(sizeof(t_instructions))))
		return (NULL);
	ret->first = NULL;
	ret->last = NULL;
	ret->numb = 0;
	return (ret);
}

t_instruction	*ft_create_instruction(char *str)
{
	t_instruction *ret;

	if (!(ret = malloc(sizeof(t_instruction))))
		return (NULL);
	ret->val = str;
	ret->next = NULL;
	return (ret);
}
