/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcaram <marcaram@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:42:56 by marcaram          #+#    #+#             */
/*   Updated: 2026/07/16 16:45:53 by marcaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s1)
{
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && (s1[i] == s2[i]))
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_stack_size(t_stack	*stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack -> next;
	}
	return (size);
}
