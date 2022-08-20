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

	median = (argc - 1) / 2;
	count = 1;
	while ((*stack_a)->next->next->next != NULL)
	{
		if (count != median)
		{
			if((*stack_a)->value < median)
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
	ft_set_position(stack_a);
	ft_set_position(stack_b);

}

void	ft_set_position(t_stack **stack)
{
	int count;
	t_stack	*test;

	count = 0;
	test = (*stack);
	while (test)
	{
		(*stack)->position = count;
		count++;
		test = test->next;
		printf("%d\n", (*stack)->position);
	}
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
	int	temp;

	if ((*stack)->value && (*stack)->next)
	{
		temp = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = temp;
		printf("%d-=-%d-=-%d\n",(*stack)->index, (*stack)->next->index, (*stack)->next->next->index);
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

void	ft_display_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (stack != NULL)
	{
		printf("Value: %d - Index: %d\n", stack->value, stack->index);
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
	ft_display_stack(stack_a);
	// ft_display_stack(stack_b);
	ft_push_swap(&stack_a, &stack_b, argc);
	// ft_push(&stack_b, &stack_a);
	// ft_swap(&stack_a);
	// ft_rotate(&stack_a);
	// ft_reverse_rotate(&stack_a);
	printf("After\n");
	ft_display_stack(stack_a);
	// ft_display_stack(stack_b);
	ft_free_all(stack_a);
	ft_free_all(stack_b);
    return (0);
}
