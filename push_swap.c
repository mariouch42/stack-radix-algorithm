#include "push_swap.h"
//#include <stdio.h>

// void	print_stack(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		printf("[%d]", stack->index);
// 		if (stack->next)
// 			printf(" → ");
// 		stack = stack->next;
// 	}
// 	printf(" → NULL\n");
// }

int main(int argc, char **argv)
{
	int *arr;
	int size;
	int i;
	t_stack *a;
	t_stack *b;

	if (argc < 2)
		return (0);
	
	arr = parse_input(argc, argv, &size);
	if (!arr)
	{
		print_error();
		return (1);
	}
	a = NULL;
	b = NULL;
	i = 0;
	while(i < size)
	{
		stack_add_back(&a, create_node(arr[i]));
		i++;
	}
	free(arr);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	if (size == 2)
		sort_two(&a);
	else if (size == 3)
        sort_three(&a);
	else if (size <= 5)
		sort_five(&a, &b);
	else
	{
		index_stack(&a);
		radix_sort(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}