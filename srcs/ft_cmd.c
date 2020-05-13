/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:05:38 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 02:06:31 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_command	*ft_create_command(const char *str)
{
	t_command *cmd;

	if (!(cmd = (t_command *)ft_zemalloc(sizeof(t_command))))
		return (NULL);
	if (!(cmd->name = ft_strdup(str)))
	{
		free(cmd);
		return (NULL);
	}
	return (cmd);
}

void		ft_add_command(t_command_list *list,
					t_command *cmd)
{
	t_command *last;

	if (list && cmd)
	{
		if (!list->head)
			list->head = cmd;
		else
		{
			last = list->head;
			while (last->next)
				last = last->next;
			last->next = cmd;
		}
		list->size++;
	}
}

void		ft_print_commands(t_command_list *list)
{
	t_command *current;

	current = list->head;
	while (current)
	{
		ft_putstrendl(current->name);
		current = current->next;
	}
}
