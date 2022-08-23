#include "push_swap.h"

//t_stack	*get_previous_stack(t_stack *stack)
//{
//	while (stack && stack->next != NULL)
//		stack = stack->next;
//	return (stack);
//}

// void	ft_add_front_stack(t_stack **old, t_stack *new)
// {
// 	//get_previous_stack(t_stack *stack);
// 	new -> next = *old;
// 	*old = new;
// }

t_stack	*ft_new_stack(int content)
{
	t_stack	*test;

	test = malloc (sizeof(t_stack) * 1);
	if (!test)
		return (NULL);
	test -> value = content;
	test -> index = 0;
	test -> next = NULL;
	return (test);
}

void	ft_init_all(t_stack **stack, int argc, char **argv)
{
	t_stack *new_stack;
    int i;
	int temp;

    i = 0;
	temp = argc - 1;
	while(i < temp)
    {
		if (temp == argc - 1)
			*stack = ft_new_stack(ft_atoi(argv[temp]));
		else
		{
			new_stack = ft_new_stack(ft_atoi(argv[temp]));
			new_stack -> next = *stack;
			*stack = new_stack;
		}
		// printf("%d--%d",argc, ft_atoi(argv[temp]));
		temp--;
	}
}

// t_stack	*ft_init_all(t_stack *stack, int argc, char **argv)
// {
// 	t_stack *new_stack;
//     int i;

//     i = 1;
// 	while(i < argc)
//     {
// 		if (i <= 1)
// 			stack = ft_new_stack(ft_atoi(argv[i]));
// 		else
// 		{
// 			new_stack = ft_new_stack(ft_atoi(argv[i]));
// 			new_stack -> next = stack;
// 			stack = new_stack;
// 		}
// 		i++;
// 	}
// 	return (stack);
// }

void	ft_index(t_stack *stack, int argc)
{
	t_stack *min_stack;
	t_stack *temp_stack;
	int min;
	int i;

	min_stack = stack;
	temp_stack = stack;
	min = stack->value;
	i = 1;
	while (i < argc)
	{
		stack = temp_stack;
		min = INT_MAX;
		while (stack)
		{
			if (stack->value <= min && stack->index == 0)
			{
				min_stack = stack;
				min = stack->value;
			}
			stack = stack->next;
		}
		min_stack->index = i;
		i++;
	}
}

void	ft_small_sort(t_stack **stack)
{
	while((*stack)->index > (*stack)->next->index || (*stack)->next->index > (*stack)->next->next->index)
	{
		if ((*stack)->index > (*stack)->next->index && (*stack)->index > (*stack)->next->next->index)
			ft_ra(stack);
		else if ((*stack)->next->index > (*stack)->index && (*stack)->next->index > (*stack)->next->next->index)
			ft_rra(stack);
		else if ((*stack)->index > (*stack)->next->index)
			ft_sa(stack);
		// printf("%d--%d--%d\n",(*stack)->value, (*stack)->next->value, (*stack)->next->next->value);
	}
	// printf("%d-%d-%d",(*stack)->value, (*stack)->next->value, (*stack)->next->next->value);
}

void	ft_big_sort(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int median;
	int count;
	int i;
	int count_b;
	t_stack	*lowest_cost;
	
	lowest_cost = NULL;
	median = (argc - 1) / 2;
	count = 1;
	count_b = 0;
	i = 0;
	while ((*stack_a)->next->next->next != NULL)
	{
		if (count != median)
		{
			if((*stack_a)->index < median)
			{
				ft_pb(stack_a, stack_b);
				count++;
			}
			else
				ft_ra(stack_a);
		}
		else
			ft_pb(stack_a, stack_b);
		// printf("%d**%d\n", (*stack_a)->value, (*stack_a)->index);
		// printf("%d**%d\n", count, median);
	}
	ft_small_sort(stack_a);
	count_b = ft_count_stack(*stack_b);
	while(i < count_b)
	{
		ft_set_position(stack_a);
		ft_set_position(stack_b);
		ft_set_target_position(stack_a, stack_b);
		ft_set_cost(stack_a, stack_b);

		printf("Stack A\n");
		ft_display_stack(*stack_a);
		printf("Stack B\n");
		ft_display_stack(*stack_b);

		// printf("SmallA: %d, SmallB: %d\n", (*ft_small_cost(*stack_a, &lowest_cost))->cost_a, (*ft_small_cost(*stack_b, &lowest_cost))->cost_a);
		ft_movements(ft_small_cost(*stack_b, &lowest_cost), stack_a, stack_b);
		i++;
	}
	ft_set_position(stack_a);
	printf("Stack A\n");
	ft_display_stack(*stack_a);
	printf("Stack B\n");
	ft_display_stack(*stack_b);
	// ft_final_sort(stack_a);
}

void	ft_final_sort(t_stack **stack_a)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if ((*stack_a)->index != ((*stack_a)->position + 1))
	{
		count = (*stack_a)->index - ((*stack_a)->position + 1);
		// printf("COUNT: %d", count);
	}
	if (count < 0)
	{
		while (i < count)
		{
			ft_ra(stack_a);
			i++;
		}
	}
	else if (count > 0)
	{
		while (i < count)
		{
			ft_rra(stack_a);
			i++;
		}
	}
}

void	ft_set_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp_a;
	t_stack *temp_b;
	int target_pos;
	int lowest;

	temp_a = (*stack_a);
	temp_b = (*stack_b);
	target_pos = INT_MAX;
	lowest = INT_MAX;
	while (temp_b)
	{
		temp_a = (*stack_a);
		target_pos = INT_MAX;
		lowest = INT_MAX;
		while (temp_a)
		{	
			if (temp_a->index < temp_b->index && temp_a->next != NULL && temp_a->next->index > temp_b->index)
			{
				target_pos = temp_a->next->position;
			}
			temp_a = temp_a->next;
		}
		temp_a = (*stack_a);
		if (target_pos == INT_MAX)
		{
			while (temp_a)
			{	
				// printf("qqqq; %d\n", target_pos);
				if (temp_a->index < lowest)
				{
					target_pos = temp_a->position;
					lowest = temp_a->index;
				}
				temp_a = temp_a->next;
			}
		}
		temp_b->target_position = target_pos;
		temp_b = temp_b->next;
	}
}

void	ft_set_position(t_stack **stack)
{
	int count;
	t_stack	*test;

	count = 0;
	test = (*stack);
	while (test)
	{
		test->position = count;
		count++;
		test = test->next;
		// printf("%d\n", (*stack)->position);
	}
}

void	ft_set_cost(t_stack **stack_a, t_stack **stack_b)
{
	// t_stack *temp_a;
	t_stack *temp_b;
	int median_a;
	int median_b;
	// temp_a = (*stack_a);
	temp_b = (*stack_b);
	median_a = ft_count_stack(*stack_a) / 2 + 1;
	median_b = ft_count_stack(*stack_b) / 2 + 1;
	// printf("MedianA: %d - MedianB: %d\n", median_a, median_b);
	while (temp_b)
	{
		if (temp_b->position < median_b)
			temp_b->cost_b = temp_b->position;
		else
			temp_b->cost_b = temp_b->position - ft_count_stack(*stack_b);
		if (temp_b->target_position < median_a)
			temp_b->cost_a = temp_b->target_position;
		else
			temp_b->cost_a = temp_b->target_position - ft_count_stack(*stack_a);
		temp_b = temp_b->next;
	}
}

void ft_movements(t_stack **lowest_stack_b, t_stack **stack_a, t_stack **stack_b)
{
	// t_stack *temp_a;
	// t_stack *temp_b;
	int i;

	// temp = (*stack_b);
	i = 0;
	if ((*lowest_stack_b)->cost_b < 0 && (*lowest_stack_b)->cost_a < 0)
	{
		while(i < ft_min((*lowest_stack_b)->cost_a, (*lowest_stack_b)->cost_b))
		{
			ft_rrr(stack_a, stack_b);
			i++;
		}
		(*lowest_stack_b)->cost_a += i;
		(*lowest_stack_b)->cost_b += i;
		i = 0;
	}
	
	if ((*lowest_stack_b)->cost_b > 0 && (*lowest_stack_b)->cost_a > 0)
	{
		while(i < ft_min((*lowest_stack_b)->cost_a, (*lowest_stack_b)->cost_b))
		{
			ft_rr(stack_a, stack_b);
			i++;
		}
		(*lowest_stack_b)->cost_a -= i;
		(*lowest_stack_b)->cost_b -= i;
		i = 0;
	}
	if ((*lowest_stack_b)->cost_b < 0)
	{
		while(i < ft_abs((*lowest_stack_b)->cost_b))
		{
			ft_rrb(stack_b);
			i++;
		}
		(*lowest_stack_b)->cost_b += i;
		i = 0;
	}
	if ((*lowest_stack_b)->cost_b > 0)
	{
		while(i < ft_abs((*lowest_stack_b)->cost_b))
		{
			ft_rb(stack_b);
			i++;
		}
		(*lowest_stack_b)->cost_b -= i;
		i = 0;
	}
	if ((*lowest_stack_b)->cost_a < 0)
	{
		while(i < ft_abs((*lowest_stack_b)->cost_a))
		{
			ft_rra(stack_a);
			i++;
		}
		(*lowest_stack_b)->cost_a += i;
		i = 0;
	}
	if ((*lowest_stack_b)->cost_a > 0)
	{
		while(i < ft_abs((*lowest_stack_b)->cost_a))
		{
			ft_ra(stack_a);
			i++;
		}
		(*lowest_stack_b)->cost_a -= i;
		i = 0;
	}
	ft_pa(stack_a, stack_b);
}

int	ft_min(int val_a, int val_b)
{
	int val;
	if (val_a < val_b)
		val = val_a;
	else
		val = val_b;
	return (val);
}

int ft_abs(int val)
{
	if (val > 0)
		return (val);
	else
		return (-val);
}

t_stack	**ft_small_cost(t_stack *stack, t_stack **lowest_cost)
{
	t_stack	*temp;
	int lowest;

	temp = stack;
	lowest = INT_MAX;
	while (stack != NULL)
	{
		if ((temp->cost_a + temp->cost_b) < lowest)
		{
			lowest = temp->cost_a + temp->cost_b;
			(*lowest_cost) = temp;
		}
		stack = stack->next;
	}
	stack = temp;
	return (lowest_cost);
}

void	ft_push_swap(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (argc == 3)
		ft_sa(stack_a);
	else if (argc == 4)
		ft_small_sort(stack_a);
	else
		ft_big_sort(stack_a, stack_b, argc);
}

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

void	ft_swap(t_stack **stack)
{
	t_stack	*temp;

	// printf("%d-=-%d-=-%d\n",(*stack)->index, (*stack)->next->index, (*stack)->next->next->index);
	if ((*stack) && (*stack)->next)
	{
		temp = (*stack);
		(*stack) = (*stack)->next;
		temp->next = (*stack)->next;
		(*stack)->next = temp;
		// printf("%d-=-%d-=-%d\n",(*stack)->index, (*stack)->next->index, (*stack)->next->next->index);
	}
}

t_stack	*ft_stack_last(t_stack *stack)
{
	t_stack	*test;

	test = stack;
	while (test)
	{
		if (test->next == NULL)
		{
			return (test);
		}
		test = test->next;
	}
	return (test);
}

t_stack	*ft_stack_before_last(t_stack *stack)
{
	t_stack	*test;

	test = stack;
	while (test)
	{
		if (test->next->next == NULL)
		{
			return (test);
		}
		test = test->next;
	}
	return (test);
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	// printf("1: %d\n", stack->value);
	ft_stack_last(*stack)->next = temp;
	// printf("2: %d\n", stack->value);
	// return (*stack);
	//remettre au debut comprendre pourquoi
}

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
	
	// printf("1: %d\n", stack->value);
	// ft_stack_last(stack)->next = temp;
	// printf("2: %d\n", stack->value);
}

void	ft_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

void	ft_sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_printf("pb\n");
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

void	ft_rra(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	ft_rrb(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_printf("rrr\n");
}

int	ft_count_stack(t_stack *stack)
{
	t_stack	*temp;
	int count;

	temp = stack;
	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	stack = temp;
	return (count);
}

void	ft_display_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (stack != NULL)
	{
		printf("Value: %3d - Index: %3d - Position: %3d - TargetPosition: %3d - CostA: %3d - CostB: %3d\n", stack->value, stack->index, stack->position, stack->target_position, stack->cost_a, stack->cost_b);
		stack = stack->next;
	}
	stack = temp;
}

void	ft_free_all(t_stack *stack)
{
	t_stack	*temp;

	while (stack != NULL)
	{
		// printf("Value: %d - Index: %d\n", stack->value, stack->index);
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	exit (1);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
    if (argc == 1)
		return (0);
	ft_init_all(&stack_a, argc, argv);
	ft_index(stack_a, argc);
	// printf("Before\n");
	// printf("Stack A\n");
	// ft_display_stack(stack_a);
	// printf("Stack B\n");
	// ft_display_stack(stack_b);
	ft_push_swap(&stack_a, &stack_b, argc);
	// ft_push(&stack_a, &stack_b);
	// ft_pa(&stack_a, &stack_b);
	// ft_swap(&stack_a);
	// ft_rotate(&stack_a);
	// ft_reverse_rotate(&stack_a);
	// printf("After\n");
	// printf("Stack A\n");
	// ft_display_stack(stack_a);
	// printf("Stack B\n");
	// ft_display_stack(stack_b);
	ft_free_all(stack_a);
	ft_free_all(stack_b);
    return (0);
}
