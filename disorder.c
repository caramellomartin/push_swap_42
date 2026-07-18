/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcaram <marcaram@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:43:47 by marcaram          #+#    #+#             */
/*   Updated: 2026/07/16 16:43:51 by marcaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calculates the percentage of unsorted pairs to pick the best strategy */
double	ft_compute_disorder(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	double	mistakes;
	double	total_pairs;

	if (!stack || !stack -> next)
		return (0.0);
	mistakes = 0.0;
	total_pairs = 0.0;
	current = stack;
	while (current)
	{
		compare = current -> next;
		while (compare)
		{
			total_pairs++;
			if (current -> value > compare -> value)
				mistakes++;
			compare = compare -> next;
		}
		current = current -> next;
	}
	if (total_pairs == 0.0)
		return (0.0);
	return (mistakes / total_pairs);
}
