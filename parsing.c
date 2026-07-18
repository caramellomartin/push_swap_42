/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:44:03 by marcaram          #+#    #+#             */
/*   Updated: 2026/07/17 18:23:21 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Validates and adds numbers from a split string into the stack */
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

/* Parses CLI arguments, handles flags, and builds the initial stack */
void	ft_parse_args(char **argv, int *strat, int *bench, t_stack **stack_a)
{
	int		i;
	char	**sub;

	*strat = 0;
	i = 1;
	while (argv[i])
	{
		if (is_flag(argv[i], strat, bench))
		{
			i++;
			continue ;
		}
		sub = ft_split(argv[i], ' ');
		if (!sub || !sub[0] || *strat == -1 || *bench == -1)
		{
			ft_free_split(sub);
			ft_free_stack(stack_a);
			ft_error();
		}
		process_sub(sub, stack_a);
		ft_free_split(sub);
		i++;
	}
	if (*strat == 0)
		*strat = 4;
}
