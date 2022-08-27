/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:23:23 by aradice           #+#    #+#             */
/*   Updated: 2022/08/25 21:30:19 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int val_a, int val_b)
{
	int	val;

	if (val_a < val_b)
		val = val_a;
	else
		val = val_b;
	return (val);
}

int	ft_abs(int val)
{
	if (val > 0)
		return (val);
	else
		return (-val);
}
