/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcaram <marcaram@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:44:03 by marcaram          #+#    #+#             */
/*   Updated: 2026/07/16 16:44:09 by marcaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_sub(char **sub, t_stack **stack_a)
{
	int		j;
	int		val;
	t_stack	*new_node;

	j = 0;
	while (sub[j])
	{
		if (!ft_isnumber(sub[j], &val) || ft_isduplicate(*stack_a, val))
		{
			ft_free_split(sub);
			ft_free_stack(stack_a);
			ft_error();
		}
		new_node = ft_new_node(val);
		if (!new_node)
		{
			ft_free_split(sub);
			ft_free_stack(stack_a);
			ft_error();
		}
		ft_add_back(stack_a, new_node);
		j++;
	}
}

void	ft_parse_args(char **argv, int *strat, int *bench, t_stack **stack_a)
{
	int		i;
	char	**sub;

	i = 1;
	while (argv[i])
	{
		if (is_flag(argv[i], strat, bench))
		{
			i++;
			continue ;
		}
		sub = ft_split(argv[i], ' ');
		if (!sub || !sub[0])
		{
			ft_free_split(sub);
			ft_free_stack(stack_a);
			ft_error();
		}
		process_sub(sub, stack_a);
		ft_free_split(sub);
		i++;
	}
}
