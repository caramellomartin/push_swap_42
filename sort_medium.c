#include "push_swap.h"

#include "push_swap.h"

static int	ft_get_max_i(t_stack *stack, int max_index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack-> index == max_index)
			return (i);
		stack = stack-> next;
		i++;
	}
	return (0);
}

static void	ft_push_chunks(t_stack **stack_a, t_stack **stack_b)
{
	int	pushed;

	pushed = 0;
	while (*stack_a)
	{
		if ((*stack_a)-> index <= pushed)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else if ((*stack_a)-> index <= pushed + 15)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			pushed++;
		}
		else
			ra(stack_a);
	}
}

void	ft_sort_medium(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pos;

	ft_push_chunks(stack_a, stack_b);
	while (*stack_b)
	{
		size = ft_stack_size(*stack_b);
		pos = ft_get_max_i(*stack_b, size - 1);
		while ((*stack_b)-> index != size - 1)
		{
			if (pos <= size / 2)
				rb(stack_b);
			else
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}
