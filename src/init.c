/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:22:46 by aradice           #+#    #+#             */
/*   Updated: 2022/08/25 21:22:47 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_all(t_stack **stack, int argc, char **argv)
{
	t_stack	*new_stack;
	int		i;
	int		temp;

	i = 0;
	temp = argc - 1;
	while (i < temp)
	{
		if (temp == argc - 1)
			*stack = ft_new_stack(ft_atoi(argv[temp]));
		else
		{
			new_stack = ft_new_stack(ft_atoi(argv[temp]));
			new_stack -> next = *stack;
			*stack = new_stack;
		}
		temp--;
	}
}

t_stack	*ft_new_stack(int content)
{
	t_stack	*test;

	test = malloc (sizeof(t_stack) * 1);
	if (!test)
		return (NULL);
	test -> value = content;
	test -> index = 0;
	test -> next = NULL;
	return (test);
}

void	ft_index(t_stack *stack, int argc)
{
	t_stack	*min_stack;
	t_stack	*temp_stack;
	int		min;
	int		i;

	min_stack = stack;
	temp_stack = stack;
	min = stack->value;
	i = 1;
	while (i < argc)
	{
		stack = temp_stack;
		min = INT_MAX;
		while (stack)
		{
			if (stack->value <= min && stack->index == 0)
			{
				min_stack = stack;
				min = stack->value;
			}
			stack = stack->next;
		}
		min_stack->index = i;
		i++;
	}
}
