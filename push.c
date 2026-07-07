#include "push_swap.h"

static void	ft_push_node(t_stack **src, t_stack **dest)
{
	t_stack	*first;

	if (!src || !*src)
		return ;
	first = *src;
	*src = (*src)-> next;
	first -> next = *dest;
	*dest = first;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_node(stack_b, stack_a);
	write(1, "pa\n", 3);
	ft_track_moves(1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_node(stack_a, stack_b);
	write(1, "pb\n", 3);
	ft_track_moves(1);
}
