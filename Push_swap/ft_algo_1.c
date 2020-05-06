#include "main.h"

char *ft_algo_b(t_list *a, t_list *b, t_option *option);
char *ft_algo_a(t_list *a, t_list *b, t_option *option);

char	*ft_algo_1_1(t_list *a, t_list *b, t_option *option)
{
	char *result;

	if ((result = ft_algo_a(a, b, option)))
		return (result);
	if ((result = ft_algo_b(a, b, option)))
		return (result);
	return (ft_rrr(a, b, option));
}

char	*ft_algo_a(t_list *a, t_list *b, t_option *option)
{
	char *result;

	if (ft_check_list(a) && ft_check_rev_list(b))
		return (ft_pa(a, b, option));
	else if (a->begin && a->begin->next && a->begin->val <
	a->begin->next->val && (!b->begin || b->begin->val < a->begin->val))
		return (ft_pb(a, b, option));
	else if (ft_check_rev_list(b) && a->begin && a->begin->next
	&& a->begin->val < b->begin->val && a->begin->next->val > b->begin->val)
		return (ft_pa(a, b, option));
	else if (ft_check_rev_list(b) && a->begin && a->begin->next &&
	a->begin->val < b->begin->val && a->begin->next->val < b->begin->val)
		return (ft_ra(a, option));
	else if (a->begin && !ft_check_list(a) && a->begin->next &&
	a->begin->val > a->begin->next->val)
		return (ft_ra(a, option));
	else if ((result = ft_algo_b(a, b, option)))
		return (result);
	return (NULL);
}

char	*ft_algo_b(t_list *a, t_list *b, t_option *option)
{
	if (!b->begin || ft_check_rev_list(b))
		return (NULL);
	if (a->begin && b->begin->val < a->begin->val)
		return (ft_pa(a, b, option));
	return (NULL);
}
