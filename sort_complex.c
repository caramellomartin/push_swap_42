/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcaram <marcaram@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:45:15 by marcaram          #+#    #+#             */
/*   Updated: 2026/07/16 16:45:17 by marcaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_max_bits(t_stack *stack)
{
	int	max_num;
	int	max_bits;

	max_num = ft_stack_size(stack) - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static int	ft_is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack -> next)
	{
		if ((stack -> value) > (stack -> next -> value))
			return (0);
		stack = stack -> next;
	}
	return (1);
}

void	ft_sort_complex(t_stack **stack_a, t_stack **stack_b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

	size = ft_stack_size(*stack_a);
	max_bits = ft_get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		if (ft_is_sorted(*stack_a))
			break ;
		j = 0;
		while (j < size)
		{
			if (((*stack_a)-> index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
