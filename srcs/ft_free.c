/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:09:25 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 13:31:18 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_free_stack(t_stack *stack)
{
	t_stack_elem	*tmp;
	size_t			i;

	i = 0;
	while (i++ < stack->size)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		free(tmp);
	}
	stack->size = 0;
	return (NULL);
}

void	*ft_free_split(char **split)
{
	int i;

	i = 0;
	if (split && *split)
	{
		while (split[i])
			free(split[i++]);
		free(split);
	}
	return (NULL);
}

void	ft_free_command(t_command_list *list)
{
	t_command *tmp;
	t_command *current;

	current = list->head;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp->name);
		free(tmp);
	}
	free(list);
}
