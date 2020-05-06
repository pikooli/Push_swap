#include "main.h"

int		ft_instruction(t_list *a, t_list *b, t_option *option)
{
	char	buf[10];
	int		ret;
	char	**tab;
	char	*cmd;

	if (!(cmd = malloc(sizeof(char) * 1)))
		return (FALSE);
	cmd[0] = '\0';
	while ((ret = read(0, buf, 5)))
	{
		buf[ret] = '\0';
		if (!(cmd = ft_append(cmd, buf)))
			return (FALSE);
	}
	if (!(tab = ft_split(cmd, '\n')))
		return (ft_strfree(cmd));
	free(cmd);
	ret = 0;
	while (tab[ret])
		if (!(ft_check_instruction(tab[ret++], a, b, option)))
			return (ft_free_tab(tab));
	ft_free_tab(tab);
	return (ft_check_final(a, b));
}

char	*ft_sa(t_list *a, t_option *option)
{
	t_maille *tmp;

	if (a->numb > 1)
	{
		tmp = a->begin;
		a->begin = a->begin->next;
		tmp->next = a->begin->next;
		a->begin->next = tmp;
		option->val1 = tmp->val;
	}
	return ("sa");
}

char	*ft_sb(t_list *b, t_option *option)
{
	ft_sa(b, option);
	return ("sb");
}

char	*ft_ss(t_list *a, t_list *b, t_option *option)
{
	ft_sa(a, option);
	ft_sb(b, option);
	return ("ss");
}

char	*ft_pa(t_list *a, t_list *b, t_option *option)
{
	t_maille *tmp;

	if (b->numb == 0)
		return ("pa");
	option->val1 = b->begin->val;
	tmp = b->begin;
	b->begin = b->begin->next;
	b->numb -= 1;
	tmp->next = a->begin;
	a->begin = tmp;
	a->numb += 1;
	return ("pa");
}

char	*ft_pb(t_list *a, t_list *b, t_option *option)
{
	ft_pa(b, a, option);
	return ("pb");
}

char	*ft_ra(t_list *a, t_option *option)
{
	t_maille *tmp;
	t_maille *last;

	if (a->numb < 2)
		return ("ra");
	tmp = a->begin;
	a->begin = a->begin->next;
	tmp->next = NULL;
	last = a->begin;
	while (last->next)
		last = last->next;
	last->next = tmp;
	option->val1 = tmp->val;
	return ("ra");
}

char	*ft_rb(t_list *b, t_option *option)
{
	ft_ra(b, option);
	return ("rb");
}

char	*ft_rr(t_list *a, t_list *b, t_option *option)
{
	ft_ra(a, option);
	ft_rb(b, option);
	return ("rr");
}

char	*ft_rra(t_list *a, t_option *option)
{
	t_maille *tmp;
	t_maille *last;

	if (a->numb < 2)
		return ("rra");
	tmp = a->begin;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = a->begin;
	a->begin = last;
	option->val1 = last->val;
	return ("rra");
}

char	*ft_rrb(t_list *b, t_option *option)
{
	ft_rra(b, option);
	return ("rrb");
}

char	*ft_rrr(t_list *a, t_list *b, t_option *option)
{
	ft_rra(a, option);
	ft_rrb(b, option);
	return ("rrr");
}
