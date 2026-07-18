/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 21:19:52 by jzaquina          #+#    #+#             */
/*   Updated: 2026/07/18 10:41:07 by jzaquina         ###   ########.fr       */
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


void	exec_op(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(stack_a);
}

void	sort_a(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	// obtener la primera linea (GNL)
	line = get_next_line(1);
	while (line)
	{
		exec_op(stack_a, stack_b, line);

	}
	// leer y comprobar si es operador
	// aplicar operador
	// bucle hasta obtener todos
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	parse_data(argv, &stack_a);
	sort_a(&stack_a, &stack_b);
	// verificar si stack_a esta ordenado y stack_b esta vacio
	return (0);
}
