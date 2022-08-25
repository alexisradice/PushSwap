/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:45:10 by aradice           #+#    #+#             */
/*   Updated: 2022/08/25 23:16:48 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parsing(char **argv)
{
	int	i;
	int	y;
	
	i = 1;
	y = 1;
	while (argv[i])
	{
		if (!ft_atoi(argv[i]))
		{
			printf("test");
			exit(1);
		}
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
		{
			printf("test2");
			exit(1);
		}
		y = i + 1;
		while (argv[y])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[y]))
			{
				printf("test3");
				exit(1);
			}
			y++;
		}
		i++;
	}
}