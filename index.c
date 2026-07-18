/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcaram <marcaram@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:43:53 by marcaram          #+#    #+#             */
/*   Updated: 2026/07/16 16:43:56 by marcaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Maps raw numbers to normalized 0-based indices for easier sorting */
void	ft_assign_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		count;

	current = stack;
	while (current)
	{
		count = 0;
		compare = stack;
		while (compare)
		{
			if (compare -> value < current -> value)
				count++;
			compare = compare -> next;
		}
		current -> index = count;
		current = current -> next;
	}
}
