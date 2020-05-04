#include "main.h"


t_maille *ft_free_list(t_maille *begin)
{
	t_maille *tmp;
	
	while (begin)
	{
		tmp = begin->next;
		free(begin);
		begin = tmp;
	}
	return NULL;
}
