// #include "push_swap.h"
// #include <stdio.h>

// void	print_stack(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		printf("[%d]", stack->value);
// 		if (stack->next)
// 			printf(" → ");
// 		stack = stack->next;
// 	}
// 	printf(" → NULL\n");
// }

// int main()
// {
// 	t_stack *nodea = NULL;
// 	nodea = create_node(5);
// 	t_stack *node3 = create_node(7);
// 	t_stack *node4 = create_node(4);
// 	t_stack *node2 = create_node(8);
// 	stack_add_back(&nodea, node2);
// 	stack_add_back(&nodea, node3);
// 	stack_add_back(&nodea, node4);


// 	t_stack *nodeb = NULL;
// 	nodeb = create_node(5);
// 	t_stack *nodeb3 = create_node(7);
// 	t_stack *nodeb4 = create_node(4);
// 	t_stack *nodeb2 = create_node(8);
// 	stack_add_back(&nodeb, nodeb2);
// 	stack_add_back(&nodeb, nodeb3);
// 	stack_add_back(&nodeb, nodeb4);

// 	print_stack(nodea);
// 	//sa(&nodea);
// 	pa(&nodea,&nodeb);
// 	print_stack(nodea);
// 	ra(&nodea);
// 	print_stack(nodea);
// 	rra(&nodea);
// 	print_stack(nodea);
// }