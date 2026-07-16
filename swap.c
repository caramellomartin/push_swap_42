/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcaram <marcaram@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:45:40 by marcaram          #+#    #+#             */
/*   Updated: 2026/07/16 16:45:42 by marcaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_nodes(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)-> next)
		return ;
	first = *stack;
	second = first -> next;
	first -> next = second -> next;
	second -> next = first;
	*stack = second;
}

void	sa(t_stack **stack_a)
{
	ft_swap_nodes(stack_a);
	write(1, "sa\n", 3);
	ft_get_bench()->sa++;
	ft_get_bench()->total++;
}

void	sb(t_stack **stack_b)
{
	ft_swap_nodes(stack_b);
	write(1, "sb\n", 3);
	ft_get_bench()->sb++;
	ft_get_bench()->total++;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap_nodes(stack_a);
	ft_swap_nodes(stack_b);
	write(1, "ss\n", 3);
	ft_get_bench()->ss++;
	ft_get_bench()->total++;
}
