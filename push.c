/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcaram <marcaram@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:44:26 by marcaram          #+#    #+#             */
/*   Updated: 2026/07/16 16:44:34 by marcaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_print_move("pb\n");
	ft_get_bench()->pa++;
	ft_get_bench()->total++;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_node(stack_a, stack_b);
	ft_print_move("pb\n");
	ft_get_bench()->pb++;
	ft_get_bench()->total++;
}
