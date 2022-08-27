/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:23:10 by aradice           #+#    #+#             */
/*   Updated: 2022/08/25 21:23:11 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_stack_last(*stack)->next = temp;
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	ft_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
