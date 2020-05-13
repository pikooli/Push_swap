/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:16:16 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 02:16:21 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_px(t_stack *to,
			t_stack *from,
			const char *name,
			t_command_list *list)
{
	ft_push(to, ft_pop(from));
	if (name && !list)
		ft_putstrendl(name);
	if (name && list)
		ft_add_command(list, ft_create_command(name));
}
