#include "push_swap.h"

double	ft_compute_disorder(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	double	mistakes;
	double	total_pairs;

	if (!stack || !stack -> next)
		return (0.0);
	mistakes = 0.0;
	total_pairs = 0.0;
	current = stack;
	while (current)
	{
		compare = current -> next;
		while (compare)
		{
			total_pairs++;
			if (current -> value > compare -> value)
				mistakes++;
			compare = compare -> next;
		}
		current = current -> next;
	}
	if (total_pairs == 0.0)
		return (0.0);
	return (mistakes / total_pairs);
}
