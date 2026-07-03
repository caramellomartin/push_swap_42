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
