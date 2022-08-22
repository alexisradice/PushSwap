#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
void	ft_big_sort(t_stack **stack_a, t_stack **stack_b, int argc);
void	ft_set_target_position(t_stack **stack_a, t_stack **stack_b);
void	ft_set_position(t_stack **stack);
void	ft_set_cost(t_stack **stack_a, t_stack **stack_b);
t_stack	**ft_small_cost(t_stack *stack, t_stack **lowest_cost);
void	ft_push_swap(t_stack **stack_a, t_stack **stack_b, int argc);
void	ft_push(t_stack **stack_dest, t_stack **stack_src);
void	ft_swap(t_stack **stack);
t_stack	*ft_stack_last(t_stack *stack);
t_stack	*ft_stack_before_last(t_stack *stack);
void 	ft_movements(t_stack **stack_a, t_stack **stack_b);
int		ft_min(int val_a, int val_b);
int 	ft_abs(int val);
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