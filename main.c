#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("[%d]", stack->value);
		if (stack->next)
			printf(" → ");
		stack = stack->next;
	}
	printf(" → NULL\n");
}

int main()
{
	t_stack *node = NULL;
	node = create_node(5);
	t_stack *node3 = create_node(7);
	t_stack *node4 = create_node(4);
	t_stack *node2 = create_node(8);
	stack_add_back(&node, node2);
	stack_add_back(&node, node3);
	stack_add_back(&node, node4);

	print_stack(node);
	sa(&node);
	print_stack(node);

}