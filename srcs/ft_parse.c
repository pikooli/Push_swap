/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:13:53 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 10:26:43 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_set_option(int ar, char *av[])
{
	int print;
	int color;

	print = ft_strcmp(av[1], "-v");
	color = ft_strcmp(av[1], "-c");
	if (ar > 1)
	{
		print = print ? print : ft_strcmp(av[2], "-v");
		color = color ? color : ft_strcmp(av[2], "-c");
	}
	return (print + color + 1);
}

static int		ft_set_option_str(int ar, char *av[])
{
	int print;
	int color;

	print = ft_strcmp(av[0], "-v");
	color = ft_strcmp(av[0], "-c");
	if (ar > 1)
	{
		print = print ? print : ft_strcmp(av[1], "-v");
		color = color ? color : ft_strcmp(av[1], "-c");
	}
	return (print + color);
}

static void		ft_parse_arg(t_stack *stack,
					int ar,
					char **av)
{
	int			i;
	t_stack_elem*new;

	i = (ft_set_option(ar, av));
	while (i < ar)
	{
		if (!ft_is_int(av[i]))
		{
			ft_free_stack(stack);
			return ;
		}
		if (!(new = ft_create_elem(ft_atoi(av[i++]))))
		{
			ft_free_stack(stack);
			return ;
		}
		ft_add_to_stack(stack, new);
	}
}

static void		ft_parse_str(t_stack *stack,
					char *str)
{
	char		**numbers;
	size_t		i;
	t_stack_elem*new;

	if (!(numbers = ft_split(str, ' ')))
		return ;
	i = ft_set_option_str(ft_size_tab(numbers), numbers);
	while (numbers[i])
	{
		if (!ft_is_int(numbers[i]))
		{
			ft_free_stack(stack);
			ft_free_split(numbers);
			return ;
		}
		if (!(new = ft_create_elem(ft_atoi(numbers[i++]))))
		{
			ft_free_stack(stack);
			ft_free_split(numbers);
			return ;
		}
		ft_add_to_stack(stack, new);
	}
	ft_free_split(numbers);
}

t_stack			*ft_parse(int ar,
				char *av[])
{
	t_stack *stack;

	if (!(stack = ft_init_stack()))
		return (ft_error());
	if (ar == 2 && !ft_isnum(av[1], 10))
		ft_parse_str(stack, av[1]);
	else
		ft_parse_arg(stack, ar, av);
	if (!stack->size)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}
