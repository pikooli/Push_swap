/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:22:11 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 12:32:40 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			ft_pb(t_list *a, t_list *b, t_option *option)
{
	return (ft_pa(b, a, option));
}

int			ft_rb(t_list *b, t_option *option)
{
	return (ft_ra(b, option));
}

int			ft_rrb(t_list *b, t_option *option)
{
	return (ft_rra(b, option));
}

int			ft_sb(t_list *b, t_option *option)
{
	return (ft_sa(b, option));
}
