#include "push_swap.h"

static	int	ft_find_highest(t_stack *stack)
{
	int	highest;

	highest = stack -> value;
	while (stack)
	{
		if (stack -> value > highest)
			highest = stack -> value;
		stack = stack -> next;
	}
	return (highest);
}

int	ft_get_min_i(t_stack *stack, int min_value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack -> value == min_value)
			return (i);
		i++;
		stack = stack -> next;
	}
	return (i);
}

int	ft_find_lowest(t_stack *stack)
{
	int	lowest;

	lowest = stack -> value;
	while (stack)
	{
		if (stack -> value < lowest)
			lowest = stack -> value;
		stack = stack -> next;
	}
	return (lowest);
}

void	ft_sort_three(t_stack **stack_a)
{
	int	highest;

	if (!stack_a || !*stack_a || !(*stack_a)-> next)
		return ;
	highest = ft_find_highest(*stack_a);
	//Si el mayor esta arriba o en medio, lo mandamos al fondo
	if ((*stack_a)-> value == highest)
		ra(stack_a);
	else if ((*stack_a)-> next -> value == highest)
		rra(stack_a);
	//Si los dos primeros estan invertidos
	if ((*stack_a)-> value > (*stack_a)-> next -> value)
		sa(stack_a);
}
