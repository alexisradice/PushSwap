/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:48:19 by aradice           #+#    #+#             */
/*   Updated: 2022/08/27 21:37:59 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void ft_checker(int argc, t_stack **stack_a, t_stack **stack_b)
{
	int		fd;
	char	*line;
	
	fd = 0;
	while(1)
	{
		line = ft_strdup("");
		line = ft_read_moves(fd, line);
		if(!line)
		{
			if (ft_check_sort(stack_a, argc))
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
			break;
		}
		if (!ft_check_moves(stack_a, stack_b, line))
		{
			write(2, "Error\n", 6);
			free(line);
			break;
		}
		free(line);
	}
	close(fd);
}

int	ft_check_sort(t_stack **stack_a, int argc)
{
	t_stack	*temp;
	int		val;
	int		i;

	temp = (*stack_a);
	val = 0;
	i = 0;
	if (temp->index != 1)
		return (0);
	while (temp)
	{
		if (temp->index > val)
			val = temp->index;
		else
			return (0);
		temp = temp->next;
		i++;
	}
	if (i != argc - 1)
		return (0);
	return (1);
}

int ft_check_moves(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if(ft_strcmp(line, "sa\n") == 0)
		ft_sa(stack_a);
	else if(ft_strcmp(line, "sb\n") == 0)
		ft_sb(stack_b);
	else if(ft_strcmp(line, "ss\n") == 0)
		ft_ss(stack_a, stack_b);
	else if(ft_strcmp(line, "pa\n") == 0)
		ft_pa(stack_a, stack_b);
	else if(ft_strcmp(line, "pb\n") == 0)
		ft_pb(stack_a, stack_b);
	else if(ft_strcmp(line, "ra\n") == 0)
		ft_ra(stack_a);
	else if(ft_strcmp(line, "rb\n") == 0)
		ft_rb(stack_b);
	else if(ft_strcmp(line, "rr\n") == 0)
		ft_rr(stack_a, stack_b);
	else if(ft_strcmp(line, "rra\n") == 0)
		ft_rra(stack_a);
	else if(ft_strcmp(line, "rrb\n") == 0)
		ft_rrb(stack_b);
	else if(ft_strcmp(line, "rrr\n") == 0)
		ft_rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

char	*ft_read_moves(int fd, char *line)
{
	int		readval;
	char	*buffer;

	buffer = malloc(sizeof(char) * 2);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	readval = 1;
	while (!ft_strchr_checker(line, '\n') && readval != 0)
	{
		readval = read(fd, buffer, 1);
		if (readval == -1)
			ft_read_error(line, buffer);
		buffer[readval] = '\0';
		line = ft_strjoin_checker(line, buffer);
	}
	free(buffer);
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}

void	ft_read_error(char *line, char *buffer)
{
	free(buffer);
	free(line);
	ft_printf("Error\n");
	exit(1);
}
