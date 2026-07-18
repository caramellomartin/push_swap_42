/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcaram <marcaram@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:45:23 by marcaram          #+#    #+#             */
/*   Updated: 2026/07/16 16:45:25 by marcaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Pushes the smallest elements to Stack B until only three remain in Stack A */
static void	ft_push_minimums(t_stack **stack_a, t_stack **stack_b)
{
	int	lowest;
	int	i;
	int	size;

	while (ft_stack_size(*stack_a) > 3)
	{
		lowest = ft_find_lowest(*stack_a);
		i = ft_get_min_i(*stack_a, lowest);
		size = ft_stack_size(*stack_a);
		while ((*stack_a)-> value != lowest)
		{
			if (i <= size / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
}

/* Selection-sort approach, pushing minimums to Stack B for small lists */
void	ft_sort_simple(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else
	{
		ft_push_minimums(stack_a, stack_b);
		ft_sort_three(stack_a);
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}
