/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:22:48 by aradice           #+#    #+#             */
/*   Updated: 2022/08/25 21:39:17 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_movements(t_stack **lowest_stack_b,
			t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	ft_move_rrr(lowest_stack_b, stack_a, stack_b, i);
	ft_move_rr(lowest_stack_b, stack_a, stack_b, i);
	ft_move_rrb(lowest_stack_b, stack_b, i);
	ft_move_rb(lowest_stack_b, stack_b, i);
	ft_move_rra(lowest_stack_b, stack_a, i);
	ft_move_ra(lowest_stack_b, stack_a, i);
	ft_pa(stack_a, stack_b);
}

void	ft_move_rrr(t_stack **lowest_stack_b,
			t_stack **stack_a, t_stack **stack_b, int i)
{
	if ((*lowest_stack_b)->cost_b < 0 && (*lowest_stack_b)->cost_a < 0)
	{
		while (i < ft_min(ft_abs((*lowest_stack_b)->cost_a),
				ft_abs((*lowest_stack_b)->cost_b)))
		{
			ft_rrr(stack_a, stack_b);
			i++;
		}
		(*lowest_stack_b)->cost_a += i;
		(*lowest_stack_b)->cost_b += i;
		i = 0;
	}
}

void	ft_move_rra(t_stack **lowest_stack_b, t_stack **stack_a, int i)
{
	if ((*lowest_stack_b)->cost_a < 0)
	{
		while (i < ft_abs((*lowest_stack_b)->cost_a))
		{
			ft_rra(stack_a);
			i++;
		}
		(*lowest_stack_b)->cost_a += i;
		i = 0;
	}
}

void	ft_move_rrb(t_stack **lowest_stack_b, t_stack **stack_b, int i)
{
	if ((*lowest_stack_b)->cost_b < 0)
	{
		while (i < ft_abs((*lowest_stack_b)->cost_b))
		{
			ft_rrb(stack_b);
			i++;
		}
		(*lowest_stack_b)->cost_b += i;
		i = 0;
	}
}
