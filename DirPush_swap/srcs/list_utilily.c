#include "main.h"

int         ft_bigger_in_list(t_list *list)
{
	int val;
	t_maille *tmp;

	val = list->begin->val;
	tmp = list->begin->next;
	while (tmp)
	{
		if (val < tmp->val)
			val = tmp->val;
		tmp = tmp->next;
	}
	return val;
}

int			ft_smaller_in_list(t_list *list)
{
	int val;
	t_maille *tmp;

	val = list->begin->val;
	tmp = list->begin->next;
	while (tmp)
	{
		if (val > tmp->val)
			val = tmp->val;
		tmp = tmp->next;
	}
	return (val);
}


int			ft_less_diff_b(t_list *a, t_list *b)
{
	if (!b->begin)
		return (FALSE);
	return (ft_less_diff(a, b->begin->val));
}

/*
**	if the value of begin of list is the smaller number after val 
*/

int			ft_less_diff(t_list *list, int val)
{
	int diff;
	t_maille *tmp;
	
	tmp = list->begin;
	if ((diff = tmp->val - val) < 0)
		return (FALSE);
	tmp = tmp->next;
	while (tmp)
	{
		if ((diff - (tmp->val - val)) > 0 && tmp->val > val)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

int			ft_closer_big(t_list *list, int val)
{
	long diff;
	long tmpdiff;
	t_maille *tmp;
	
	tmp = list->begin;
	diff = (long)tmp->val - (long)val;
	diff = diff > 0 ? diff : -diff;
	tmp = tmp->next;
	while (tmp)
	{
		tmpdiff = ((long)tmp->val - (long)val) > 0 ? ((long)tmp->val - (long)val) : -((long)tmp->val - (long)val);
		if ((tmpdiff - diff) < 0 && tmp->val > val)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

int			ft_closer_small(t_list *list, int val)
{
	long diff;
	long tmpdiff;
	t_maille *tmp;
	
	tmp = list->begin;
	diff = (long)tmp->val - (long)val;
	diff = diff > 0 ? diff : -diff;
	tmp = tmp->next;
	while (tmp)
	{
		tmpdiff = ((long)tmp->val - (long)val) > 0 ? ((long)tmp->val - (long)val) : -((long)tmp->val - (long)val);
		if ((tmpdiff - diff) < 0 && tmp->val < val)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

int			ft_closer_big_maille(t_maille *begin, int val)
{
	long diff;
	long tmpdiff;
	t_maille *tmp;
	
	tmp = begin;
	diff = (long)tmp->val - (long)val;
	diff = diff > 0 ? diff : -diff;
	tmp = tmp->next;
	while (tmp)
	{
		tmpdiff = ((long)tmp->val - (long)val) > 0 ? ((long)tmp->val - (long)val) : -((long)tmp->val - (long)val);
		if ((tmpdiff - diff) < 0 && tmp->val > val)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}


int			ft_closer_small_maille(t_maille *begin, int val)
{
	long diff;
	long tmpdiff;
	t_maille *tmp;
	
	tmp = begin;
	diff = (long)tmp->val - (long)val;
	diff = diff > 0 ? diff : -diff;
	tmp = tmp->next;
	while (tmp)
	{
		tmpdiff = ((long)tmp->val - (long)val) > 0 ? ((long)tmp->val - (long)val) : -((long)tmp->val - (long)val);
		if ((tmpdiff - diff) < 0 && tmp->val < val)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

int 		ft_list_ordoned(t_list *list)
{
	t_maille *next;
	t_maille *current;
	int smaller;

	current = list->begin;
	if (!current)
		return (FALSE);
	next = list->begin->next;
	smaller = ft_smaller_in_list(list);
	while (next)
	{
		if (current->val > next->val && next->val != smaller)
			return (FALSE);
		current = next;
		next = next->next;
	}
	return (TRUE);
}


int         ft_check_list(t_list *list)
{
	t_maille *tmp;

	tmp = list->begin;
	if (!tmp)
		return (FALSE);
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

int         ft_check_rev_list(t_list *list)
{
	t_maille *tmp;

	tmp = list->begin;
	if (!tmp)
		return (FALSE);
	while (tmp->next)
	{
		if (tmp->val < tmp->next->val)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

int         ft_top_is_the_bigger(t_list *list)
{
	int val;
	t_maille *tmp;

	if (!list->begin)
		return (FALSE);
	val = list->begin->val;
	tmp = list->begin->next;
	while (tmp)
	{
		if (val < tmp->val)
			return (FALSE);
		tmp = tmp->next;
	}
	return TRUE;
}

t_maille    *ft_last_list(t_list *list)
{
    t_maille *tmp;

    tmp = list->begin;
    if (!tmp)
        return (NULL);
    while (tmp->next)
    {   
        tmp = tmp->next;
    }
    return (tmp);
}

int			ft_is_bigger(t_list *list, int val)
{
	t_maille *current;

	current = list->begin;
	while (current)
	{
		if (current->val > val)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}
