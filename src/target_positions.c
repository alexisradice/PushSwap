/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:23:17 by aradice           #+#    #+#             */
/*   Updated: 2022/08/25 21:23:19 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		target_pos;
	int		lowest;

	temp_a = (*stack_a);
	temp_b = (*stack_b);
	target_pos = INT_MAX;
	lowest = INT_MAX;
	while (temp_b)
	{
		temp_a = (*stack_a);
		target_pos = INT_MAX;
		lowest = INT_MAX;
		ft_target_position(temp_a, temp_b, &target_pos);
		temp_a = (*stack_a);
		ft_lowest_index(temp_a, &target_pos, &lowest);
		temp_b->target_position = target_pos;
		temp_b = temp_b->next;
	}
}

void	ft_target_position(t_stack *temp_a, t_stack *temp_b, int *target_pos)
{
	while (temp_a)
	{	
		if (temp_a->index < temp_b->index && temp_a->next != NULL
			&& temp_a->next->index > temp_b->index)
			*target_pos = temp_a->next->position;
		else if (temp_a->position == 0 && temp_a->index > temp_b->index
			&& ft_stack_last(temp_a)->index < temp_b->index)
			*target_pos = 0;
		temp_a = temp_a->next;
	}
}

void	ft_lowest_index(t_stack *temp_a, int *target_pos, int *lowest)
{
	if (*target_pos == INT_MAX)
	{
		while (temp_a)
		{
			if (temp_a->index < *lowest)
			{
				*target_pos = temp_a->position;
				*lowest = temp_a->index;
			}
				temp_a = temp_a->next;
		}
	}
}
