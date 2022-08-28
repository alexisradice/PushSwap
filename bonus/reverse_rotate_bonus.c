/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:23:07 by aradice           #+#    #+#             */
/*   Updated: 2022/08/27 20:19:38 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!*stack || (*stack)->next == NULL)
		return ;
	temp = ft_stack_last(*stack);
	temp2 = ft_stack_before_last(*stack);
	temp->next = *stack;
	temp2->next = NULL;
	*stack = temp;
}

void	ft_rra(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
}

void	ft_rrb(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}
