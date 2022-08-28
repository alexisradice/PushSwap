/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_rotate_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:22:51 by aradice           #+#    #+#             */
/*   Updated: 2022/08/27 16:57:21 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_move_rr(t_stack **lowest_stack_b,
			t_stack **stack_a, t_stack **stack_b, int i)
{
	if ((*lowest_stack_b)->cost_b > 0 && (*lowest_stack_b)->cost_a > 0)
	{
		while (i < ft_min(ft_abs((*lowest_stack_b)->cost_a),
				ft_abs((*lowest_stack_b)->cost_b)))
		{
			ft_rr(stack_a, stack_b);
			i++;
		}
		(*lowest_stack_b)->cost_a -= i;
		(*lowest_stack_b)->cost_b -= i;
		i = 0;
	}
}

void	ft_move_ra(t_stack **lowest_stack_b, t_stack **stack_a, int i)
{
	if ((*lowest_stack_b)->cost_a > 0)
	{
		while (i < ft_abs((*lowest_stack_b)->cost_a))
		{
			ft_ra(stack_a);
			i++;
		}
		(*lowest_stack_b)->cost_a -= i;
		i = 0;
	}
}

void	ft_move_rb(t_stack **lowest_stack_b, t_stack **stack_b, int i)
{
	if ((*lowest_stack_b)->cost_b > 0)
	{
		while (i < ft_abs((*lowest_stack_b)->cost_b))
		{
			ft_rb(stack_b);
			i++;
		}
		(*lowest_stack_b)->cost_b -= i;
		i = 0;
	}
}
