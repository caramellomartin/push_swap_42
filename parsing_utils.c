/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:44:12 by marcaram          #+#    #+#             */
/*   Updated: 2026/07/17 18:23:26 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_strat(char *argv, int *strat)
{
	size_t				i;
	static const t_flag	lut[] = {
	{"--simple", 1}, {"--medium", 2},
	{"--complex", 3}, {"--adaptive", 4}, {NULL, 0}
	};

	i = 0;
	while (lut[i].name != NULL)
	{
		if (ft_strncmp(argv, lut[i].name, ft_strlen(lut[i].name) + 1) == 0)
		{
			if (*strat != 0)
			{
				*strat = -1;
				return (0);
			}
			*strat = lut[i].value;
			ft_get_bench()->is_adaptive = lut[i].value;
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_flag(char *argv, int *strat, int *bench)
{
	if (ft_strncmp(argv, "--bench", 8) == 0)
	{
		if (*bench != 0)
		{
			*bench = -1;
			return (0);
		}
		*bench = 1;
		return (1);
	}
	return (ft_check_strat(argv, strat));
}

int	ft_checkdig(const char *str, int sign, int *result)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		res = (res * 10) + (str[i] - '0');
		if ((sign == 1 && res > INT_MAX)
			|| (sign == -1 && res > (long)INT_MAX + 1))
			return (0);
		i++;
	}
	*result = (int)(res * sign);
	return (1);
}

int	ft_isnumber(const char *str, int *result)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	if (!str || !str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	return (ft_checkdig(&str[i], sign, result));
}

int	ft_isduplicate(t_stack *stack, int val)
{
	while (stack)
	{
		if (stack->value == val)
			return (1);
		stack = stack->next;
	}
	return (0);
}
