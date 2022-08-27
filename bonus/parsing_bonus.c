/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:45:10 by aradice           #+#    #+#             */
/*   Updated: 2022/08/27 16:56:13 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_parsing(char **argv)
{
	int		i;
	int		y;
	char	*test;

	i = 1;
	y = 1;
	while (argv[i])
	{
		test = ft_itoa(ft_atoi(argv[i]));
		if (!ft_atoi(argv[i]) && ft_abs(ft_atoi(argv[i])) != 0)
			ft_exit(test);
		if (ft_strcmp(test, argv[i]) != 0)
			ft_exit(test);
		y = i + 1;
		while (argv[y])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[y]))
				ft_exit(test);
			y++;
		}
		i++;
		free(test);
	}
}

void	ft_exit(char *test)
{
	free(test);
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
