/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:23:04 by aradice           #+#    #+#             */
/*   Updated: 2022/08/27 20:19:24 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_push(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*temp;

	if (!(*stack_src))
		return ;
	temp = (*stack_src)->next;
	(*stack_src)->next = (*stack_dest);
	(*stack_dest) = (*stack_src);
	(*stack_src) = temp;
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
}
