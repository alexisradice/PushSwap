/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:22:55 by aradice           #+#    #+#             */
/*   Updated: 2022/08/27 16:57:17 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_set_position(t_stack **stack)
{
	int		count;
	t_stack	*test;

	count = 0;
	test = (*stack);
	while (test)
	{
		test->position = count;
		count++;
		test = test->next;
	}
}
