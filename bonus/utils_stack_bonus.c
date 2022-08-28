/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:23:20 by aradice           #+#    #+#             */
/*   Updated: 2022/08/27 16:56:25 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*ft_stack_last(t_stack *stack)
{
	t_stack	*test;

	test = stack;
	while (test)
	{
		if (test->next == NULL)
		{
			return (test);
		}
		test = test->next;
	}
	return (test);
}

t_stack	*ft_stack_before_last(t_stack *stack)
{
	t_stack	*test;

	test = stack;
	while (test)
	{
		if (test->next->next == NULL)
		{
			return (test);
		}
		test = test->next;
	}
	return (test);
}

int	ft_count_stack(t_stack *stack)
{
	t_stack	*temp;
	int		count;

	temp = stack;
	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	stack = temp;
	return (count);
}
