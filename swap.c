#include "push_swap.h"

void swap(t_stack **stack)
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