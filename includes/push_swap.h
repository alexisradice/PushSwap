/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:20:56 by aradice           #+#    #+#             */
/*   Updated: 2022/08/25 21:31:36 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				position;
	int				target_position;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_new_stack(int content);
void	ft_init_all(t_stack **stack, int argc, char **argv);
void	ft_index(t_stack *stack, int argc);
void	ft_small_sort(t_stack **stack);
void	ft_median_sort(t_stack **stack_a,
			t_stack **stack_b, int argc, int median);
void	ft_big_sort(t_stack **stack_a, t_stack **stack_b, int argc);
void	ft_set_target_position(t_stack **stack_a, t_stack **stack_b);
void	ft_target_position(t_stack *temp_a, t_stack *temp_b, int *target_pos);
void	ft_lowest_index(t_stack *temp_a, int *target_pos, int *lowest);
void	ft_set_position(t_stack **stack);
void	ft_set_cost(t_stack **stack_a, t_stack **stack_b);
t_stack	**ft_small_cost(t_stack **stack, t_stack **lowest_cost);
void	ft_push_swap(t_stack **stack_a, t_stack **stack_b, int argc);
void	ft_final_sort(t_stack **stack_a, int median);
void	ft_push(t_stack **stack_dest, t_stack **stack_src);
void	ft_swap(t_stack **stack);
t_stack	*ft_stack_last(t_stack *stack);
t_stack	*ft_stack_before_last(t_stack *stack);
void	ft_movements(t_stack **lowest_stack_b,
			t_stack **stack_a, t_stack **stack_b);
void	ft_move_rrr(t_stack **lowest_stack_b,
			t_stack **stack_a, t_stack **stack_b, int i);
void	ft_move_rr(t_stack **lowest_stack_b,
			t_stack **stack_a, t_stack **stack_b, int i);
void	ft_move_rrb(t_stack **lowest_stack_b, t_stack **stack_b, int i);
void	ft_move_rb(t_stack **lowest_stack_b, t_stack **stack_b, int i);
void	ft_move_rra(t_stack **lowest_stack_b, t_stack **stack_a, int i);
void	ft_move_ra(t_stack **lowest_stack_b, t_stack **stack_a, int i);
int		ft_min(int val_a, int val_b);
int		ft_abs(int val);
void	ft_rotate(t_stack **stack);
void	ft_reverse_rotate(t_stack **stack);
int		ft_count_stack(t_stack *stack);
void	ft_display_stack(t_stack *stack);
void	ft_free_all(t_stack *stack);
int		main(int argc, char **argv);
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

#endif