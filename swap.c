#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (!stack || !(*stack)->next)
		return ;
	
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void sa(t_stack **a)
{
    swap(a);
    write(1, "sa\n", 3);
}