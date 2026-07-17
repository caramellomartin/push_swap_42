/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcaram <marcaram@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:44:41 by marcaram          #+#    #+#             */
/*   Updated: 2026/07/16 16:44:45 by marcaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_print_move("rra\n");
	ft_get_bench()->rra++;
	ft_get_bench()->total++;
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate_nodes(stack_b);
	ft_print_move("rrb\n");
	ft_get_bench()->rrb++;
	ft_get_bench()->total++;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_nodes(stack_a);
	reverse_rotate_nodes(stack_b);
	ft_print_move("rrr\n");
	ft_get_bench()->rrr++;
	ft_get_bench()->total++;
}
