/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcaram <marcaram@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:45:04 by marcaram          #+#    #+#             */
/*   Updated: 2026/07/16 16:45:08 by marcaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_nodes(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)-> next)
		return ;
	first = *stack;
	last = *stack;
	while (last -> next)
		last = last -> next;
	*stack = first -> next;
	last -> next = first;
	first -> next = NULL;
}

void	ra(t_stack **stack_a)
{
	rotate_nodes(stack_a);
	write(1, "ra\n", 3);
	ft_get_bench()->ra++;
	ft_get_bench()->total++;
}

void	rb(t_stack **stack_b)
{
	rotate_nodes(stack_b);
	write(1, "rb\n", 3);
	ft_get_bench()->rb++;
	ft_get_bench()->total++;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_nodes(stack_a);
	rotate_nodes(stack_b);
	write(1, "rr\n", 3);
	ft_get_bench()->rr++;
	ft_get_bench()->total++;
}
