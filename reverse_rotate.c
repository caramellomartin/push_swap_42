#include "push_swap.h"

static void	reverse_rotate_nodes(t_stack **stack)
{
	t_stack	*last;
	t_stack	*sec_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	sec_last = NULL;
	last = *stack;
	while (last -> next)
	{
		sec_last = last;
		last = last -> next;
	}
	sec_last -> next = NULL;
	last -> next = *stack;
	*stack = last;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate_nodes(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate_nodes(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_nodes(stack_a);
	reverse_rotate_nodes(stack_b);
	write(1, "rrr\n", 4);
}
