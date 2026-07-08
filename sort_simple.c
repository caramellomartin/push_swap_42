#include "push_swap.h"

static void	ft_push_minimums(t_stack **stack_a, t_stack **stack_b)
{
	int	lowest;
	int	i;
	int	size;

	while (ft_stack_size(*stack_a) > 3)
	{
		lowest = ft_find_lowest(*stack_a);
		i = ft_get_min_i(*stack_a, lowest);
		size = ft_stack_size(*stack_a);
		while ((*stack_a)-> value != lowest)
		{
			if (i <= size / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
}

void	ft_sort_simple(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else
	{
		ft_push_minimums(stack_a, stack_b);
		ft_sort_three(stack_a);
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}
