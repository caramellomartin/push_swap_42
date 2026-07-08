#include "push_swap.h"

void	ft_assign_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		count;

	current = stack;
	while (current)
	{
		count = 0;
		compare = stack;
		while (compare)
		{
			if (compare -> value < current -> value)
				count++;
			compare = compare -> next;
		}
		current -> index = count;
		current = current -> next;
	}
}
