/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcaram <marcaram@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:45:19 by marcaram          #+#    #+#             */
/*   Updated: 2026/07/16 16:45:21 by marcaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Finds the position of a specific target index in the stack */
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

/* Pushes nodes to Stack B in dynamic blocks (chunks) to pre-sort data */
static void	ft_push_chunks(t_stack **stack_a, t_stack **stack_b)
{
	int	pushed;
	int	chunk_size;

	pushed = 0;
	chunk_size = ft_stack_size(*stack_a) / 7;
	while (*stack_a)
	{
		if ((*stack_a)-> index <= pushed)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else if ((*stack_a)-> index <= pushed + chunk_size)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			pushed++;
		}
		else
			ra(stack_a);
	}
}

/* Chunk-based sorting strategy optimized for medium-sized lists */
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
