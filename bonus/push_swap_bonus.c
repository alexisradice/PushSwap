/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 04:09:37 by aradice           #+#    #+#             */
/*   Updated: 2022/08/28 04:09:37 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free_all(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	while (stack_a != NULL)
	{
		temp_a = stack_a;
		stack_a = stack_a->next;
		free(temp_a);
	}
	while (stack_b != NULL)
	{
		temp_b = stack_b;
		stack_b = stack_b->next;
		free(temp_b);
	}
	exit (1);
}

void	ft_push_swap(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (argc == 3)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			ft_sa(stack_a);
	}
	else if (argc == 4)
		ft_small_sort(stack_a);
	else
		ft_big_sort(stack_a, stack_b, argc);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	ft_parsing(argv);
	ft_init_all(&stack_a, argc, argv);
	ft_index(stack_a, argc);
	ft_checker(argc, &stack_a, &stack_b);
	ft_free_all(stack_a, stack_b);
	return (0);
}
