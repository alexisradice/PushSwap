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
	while((*stack)->value > (*stack)->next->value || (*stack)->next->index > (*stack)->next->next->value)
	{
		if ((*stack)->index > (*stack)->next->index && (*stack)->index > (*stack)->next->next->index)
			ft_rotate(stack);
		else if ((*stack)->next->index > (*stack)->index && (*stack)->next->index > (*stack)->next->next->index)
			ft_reverse_rotate(stack);
		else if ((*stack)->index > (*stack)->next->index)
			ft_swap(stack);
		// printf("%d--%d--%d\n",(*stack)->value, (*stack)->next->value, (*stack)->next->next->value);
	}
	// printf("%d-%d-%d",(*stack)->value, (*stack)->next->value, (*stack)->next->next->value);
}

void	ft_big_sort(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int median;
	int count;
	t_stack	*lowest_cost;
	
	lowest_cost = NULL;
	median = (argc - 1) / 2;
	count = 1;
	while ((*stack_a)->next->next->next != NULL)
	{
		if (count != median)
		{
			if((*stack_a)->index < median)
			{
				ft_push(stack_b, stack_a);
				count++;
			}
			else
				ft_rotate(stack_a);
		}
		else
			ft_push(stack_b, stack_a);
		// printf("%d**%d\n", (*stack_a)->value, (*stack_a)->index);
		// printf("%d**%d\n", count, median);
	}
	ft_small_sort(stack_a);
	// while(1)
	// {
		
		ft_set_position(stack_a);
		ft_set_position(stack_b);
		ft_set_target_position(stack_a, stack_b);
		ft_set_cost(stack_a, stack_b);
		printf("SmallA: %d, SmallB: %d", (*ft_small_cost(*stack_a, &lowest_cost))->cost_a, (*ft_small_cost(*stack_b, &lowest_cost))->cost_a);
		// ft_movements(ft_small_cost(*stack_a, &lowest_cost), ft_small_cost(*stack_b, &lowest_cost));
	// }
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
	printf("MedianA: %d - MedianB: %d\n", median_a, median_b);
	while (temp_b)
	{
		if (temp_b->position < median_b)
			temp_b->cost_b = temp_b->position;
		else
			temp_b->cost_b = temp_b->position - ft_count_stack(*stack_b);
		if (temp_b->target_position < median_a)
			temp_b->cost_a = temp_b->target_position;
		else
			temp_b->cost_a = temp_b->target_position - median_a;
		temp_b = temp_b->next;
	}
}

void ft_movements(t_stack **stack_a, t_stack **stack_b)
{
	// t_stack *temp;
	int i;

	// temp = (*stack_b);
	i = 0;
	if ((*stack_b)->cost_b < 0 && (*stack_b)->cost_a < 0)
	{
		while(i < ft_min((*stack_b)->cost_a, (*stack_b)->cost_b))
		{
			ft_rrr(stack_a, stack_b);
			i++;
		}
		(*stack_b)->cost_a += i;
		(*stack_b)->cost_b += i;
		i = 0;
	}
	
	if ((*stack_b)->cost_b > 0 && (*stack_b)->cost_a > 0)
	{
		while(i < ft_min((*stack_b)->cost_a, (*stack_b)->cost_b))
		{
			ft_rr(stack_a, stack_b);
			i++;
		}
		(*stack_b)->cost_a -= i;
		(*stack_b)->cost_b -= i;
		i = 0;
	}
	if ((*stack_b)->cost_b < 0)
	{
		while(i < (*stack_b)->cost_b)
		{
			ft_rrb(stack_b);
			i++;
		}
		(*stack_b)->cost_b += i;
		i = 0;
	}
	if ((*stack_b)->cost_b > 0)
	{
		while(i < (*stack_b)->cost_b)
		{
			ft_rb(stack_b);
			i++;
		}
		(*stack_b)->cost_b -= i;
		i = 0;
	}
	if ((*stack_b)->cost_a < 0)
	{
		while(i < (*stack_b)->cost_a)
		{
			ft_rrb(stack_a);
			i++;
		}
		(*stack_b)->cost_a += i;
		i = 0;
	}
	if ((*stack_b)->cost_a > 0)
	{
		while(i < (*stack_b)->cost_a)
		{
			ft_rb(stack_a);
			i++;
		}
		(*stack_b)->cost_a -= i;
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

	printf("test");
	temp = stack;
	lowest = INT_MAX;
	while (stack != NULL)
	{
		printf("test");
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
		ft_swap(stack_a);
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
	ft_printf("sa");
}

void	ft_sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss");
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pa");
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_printf("pb");
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra");
}

void	ft_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("ra");
}

void	ft_rra(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_printf("rra");
}

void	ft_rrb(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_printf("rrb");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_printf("rrr");
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
		printf("Value: %d - Index: %d - Position: %d - TargetPosition: %d - CostA: %d - CostB: %d\n", stack->value, stack->index, stack->position, stack->target_position, stack->cost_a, stack->cost_b);
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
	printf("Before\n");
	printf("Stack A\n");
	ft_display_stack(stack_a);
	printf("Stack B\n");
	ft_display_stack(stack_b);
	ft_push_swap(&stack_a, &stack_b, argc);
	// ft_push(&stack_b, &stack_a);
	// ft_swap(&stack_a);
	// ft_rotate(&stack_a);
	// ft_reverse_rotate(&stack_a);
	printf("After\n");
	printf("Stack A\n");
	ft_display_stack(stack_a);
	printf("Stack B\n");
	ft_display_stack(stack_b);
	ft_free_all(stack_a);
	ft_free_all(stack_b);
    return (0);
}
