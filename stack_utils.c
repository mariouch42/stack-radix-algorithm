#include "push_swap.h"

t_stack *create_node(int value)
{
	t_stack *new ;

	new =  malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack *tmp;

	if(!*stack)
	{
		*stack = new;
		return;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int stack_size(t_stack *stack)
{
	int size;

	size = 0;
	while(stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void free_stack(t_stack **stack)
{
	t_stack *tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int is_sorted(t_stack *stack)
{
    if (!stack)
        return (1);
    while (stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}