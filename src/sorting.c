/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:23:12 by aradice           #+#    #+#             */
/*   Updated: 2022/08/25 21:38:34 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_small_sort(t_stack **stack)
{
	while ((*stack)->index > (*stack)->next->index
		|| (*stack)->next->index > (*stack)->next->next->index)
	{
		if ((*stack)->index > (*stack)->next->index
			&& (*stack)->index > (*stack)->next->next->index)
			ft_ra(stack);
		else if ((*stack)->next->index > (*stack)->index
			&& (*stack)->next->index > (*stack)->next->next->index)
			ft_rra(stack);
		else if ((*stack)->index > (*stack)->next->index)
			ft_sa(stack);
	}
}

void	ft_big_sort(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int		median;
	int		i;
	int		count_b;
	t_stack	*lowest_cost;

	lowest_cost = NULL;
	median = (argc - 1) / 2;
	count_b = 0;
	i = 0;
	ft_median_sort(stack_a, stack_b, argc, median);
	ft_small_sort(stack_a);
	count_b = ft_count_stack(*stack_b);
	while (i < count_b)
	{
		ft_set_position(stack_a);
		ft_set_position(stack_b);
		ft_set_target_position(stack_a, stack_b);
		ft_set_cost(stack_a, stack_b);
		ft_movements(ft_small_cost(stack_b, &lowest_cost), stack_a, stack_b);
		i++;
	}
	ft_set_position(stack_a);
	ft_final_sort(stack_a, median);
}

void	ft_median_sort(t_stack **stack_a,
			t_stack **stack_b, int argc, int median)
{
	int		count;

	count = 1;
	while ((*stack_a)->next->next->next != NULL)
	{
		if (argc >= 5 && argc <= 30)
			ft_pb(stack_a, stack_b);
		else
		{
			if (count != median)
			{
				if ((*stack_a)->index < median)
				{
					ft_pb(stack_a, stack_b);
					count++;
				}
				else
					ft_ra(stack_a);
			}
			else
				ft_pb(stack_a, stack_b);
		}
	}
}

void	ft_final_sort(t_stack **stack_a, int median)
{
	t_stack	*temp;
	int		pos;

	temp = (*stack_a);
	pos = 0;
	while (temp)
	{
		if (temp->index == 1)
		{
			if (temp->position > median)
				pos = 1;
			else
				pos = -1;
		}
		temp = temp->next;
	}
	while ((*stack_a)->index != 1)
	{
		if (pos > 0)
			ft_rra(stack_a);
		if (pos < 0)
			ft_ra(stack_a);
	}
}
