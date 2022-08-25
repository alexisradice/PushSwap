/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:22:42 by aradice           #+#    #+#             */
/*   Updated: 2022/08/25 21:24:29 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;
	int		median_a;
	int		median_b;

	temp_b = (*stack_b);
	median_a = ft_count_stack(*stack_a) / 2 + 1;
	median_b = ft_count_stack(*stack_b) / 2 + 1;
	while (temp_b)
	{
		if (temp_b->position < median_b)
			temp_b->cost_b = temp_b->position;
		else
			temp_b->cost_b = temp_b->position - ft_count_stack(*stack_b);
		if (temp_b->target_position < median_a)
			temp_b->cost_a = temp_b->target_position;
		else
			temp_b->cost_a = temp_b->target_position - ft_count_stack(*stack_a);
		temp_b = temp_b->next;
	}
}

t_stack	**ft_small_cost(t_stack **stack, t_stack **lowest_cost)
{
	t_stack	*temp;
	int		lowest;

	temp = (*stack);
	lowest = INT_MAX;
	while (temp)
	{
		if ((ft_abs(temp->cost_a) + ft_abs(temp->cost_b)) < lowest)
		{
			lowest = ft_abs(temp->cost_a) + ft_abs(temp->cost_b);
			(*lowest_cost) = temp;
		}
		temp = temp->next;
	}
	return (lowest_cost);
}
