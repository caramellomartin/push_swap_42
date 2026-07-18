/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcaram <marcaram@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:45:10 by marcaram          #+#    #+#             */
/*   Updated: 2026/07/16 16:45:12 by marcaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Finds the node with the highest value in the stack */
static	int	ft_find_highest(t_stack *stack)
{
	int	highest;

	highest = stack -> value;
	while (stack)
	{
		if (stack -> value > highest)
			highest = stack -> value;
		stack = stack -> next;
	}
	return (highest);
}

/* Finds the current position (index in the list) of the minimum value */
int	ft_get_min_i(t_stack *stack, int min_value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack -> value == min_value)
			return (i);
		i++;
		stack = stack -> next;
	}
	return (i);
}

/* Finds the node with the lowest value in the stack */
int	ft_find_lowest(t_stack *stack)
{
	int	lowest;

	lowest = stack -> value;
	while (stack)
	{
		if (stack -> value < lowest)
			lowest = stack -> value;
		stack = stack -> next;
	}
	return (lowest);
}

/* Hardcoded algorithm to sort up to three nodes with maximum efficiency */
void	ft_sort_three(t_stack **stack_a)
{
	int	highest;

	if (!stack_a || !*stack_a || !(*stack_a)-> next)
		return ;
	highest = ft_find_highest(*stack_a);
	if ((*stack_a)-> value == highest)
		ra(stack_a);
	else if ((*stack_a)-> next -> value == highest)
		rra(stack_a);
	if ((*stack_a)-> value > (*stack_a)-> next -> value)
		sa(stack_a);
}

/* Routes the program to the correct sorting algorithm based on the mode */
void	execute_strategy(int strat, t_stack **a, t_stack **b)
{
	if (strat == 1)
		ft_sort_simple(a, b);
	else if (strat == 2)
		ft_sort_medium(a, b);
	else if (strat == 3)
		ft_sort_complex(a, b);
}
