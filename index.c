#include "push_swap.h"

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

//STACK TEST
void	debug_print_stack(t_stack *stack, char *name)
{
	t_stack	*tmp;

	tmp = stack;
	printf("--- Estado del %s ---\n", name);
	if (!tmp)
	{
		printf("(vacío)\n");
		return ;
	}
	while (tmp)
	{
		printf("[Valor: %10d | Índice: %2d] -> ", tmp->value, tmp->index);
		if (tmp->next)
			printf("Siguiente nodo\n");
		else
			printf("NULL\n");
		tmp = tmp->next;
	}
	printf("------------------------\n\n");
}
