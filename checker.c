/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 21:19:52 by jzaquina          #+#    #+#             */
/*   Updated: 2026/07/17 22:02:52 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	parse_data(char **argv, t_stack **stack_a)
{
	int		i;
	char	**sub;

	i = 1;
	while (argv[i])
	{
		sub = ft_split(argv[i], ' ');
		process_sub(sub, stack_a);
		ft_free_split(sub);
		i++;
	}
}

void	sort_a(t_stack **stack_a)
{
	// obtener la primera linea (GNL)
	// leer y comprobar si es operador
	// aplicar operador
	// bucle hasta obtener todos
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc <= 1)
		return (0);
	parse_data(argv, &stack_a);
	sort_a(&stack_a);
	// verificar si stack_a esta ordenado y stack_b esta vacio
	return (0);
}
