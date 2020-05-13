/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:18:57 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 02:19:02 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_shift_info	*ft_init_shift_info(void)
{
	t_shift_info	*shift_info;

	if (!(shift_info = (t_shift_info *)ft_zemalloc(sizeof(t_shift_info))))
		return (NULL);
	shift_info->a_elem = NULL;
	shift_info->b_elem = NULL;
	shift_info->a_direction = R;
	shift_info->b_direction = R;
	shift_info->size = 0;
	shift_info->is_set = false;
	return (shift_info);
}

static void			ft_move_b(t_stack *a_stack,
						t_stack *b_stack,
						t_shift_info *shift_info,
						t_command_list *command_list)
{
	while (shift_info->a_elem != a_stack->head
		|| shift_info->b_elem != b_stack->head)
	{
		if (shift_info->a_direction == shift_info->b_direction
			&& shift_info->a_elem != a_stack->head
			&& shift_info->b_elem != b_stack->head)
			(shift_info->a_direction == R) ?
					ft_rr(a_stack, b_stack, "rr", command_list) :
					ft_rrr(a_stack, b_stack, "rrr", command_list);
		else if (shift_info->a_elem != a_stack->head)
			(shift_info->a_direction == R) ?
					ft_rx(a_stack, "ra", command_list) :
					ft_rrx(a_stack, "rra", command_list);
		else if (shift_info->b_elem != b_stack->head)
			(shift_info->b_direction == R) ?
					ft_rx(b_stack, "rb", command_list) :
					ft_rrx(b_stack, "rrb", command_list);
	}
}

void				ft_solve_b(t_stack *a_stack,
						t_stack *b_stack,
						t_command_list *command_list)
{
	t_shift_info	*shift_info;

	shift_info = ft_init_shift_info();
	while (b_stack->size)
	{
		shift_info->is_set = false;
		ft_opt_direction(a_stack, b_stack, shift_info);
		ft_move_b(a_stack, b_stack, shift_info, command_list);
		ft_px(a_stack, b_stack, "pa", command_list);
	}
	free(shift_info);
}
