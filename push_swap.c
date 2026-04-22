#include "push_swap.h"

int main(int argc, char **argv)
{
	int *arr;
	int size;
	int i;
	t_stack *a;
	t_stack *b;

	if(argc < 2)
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
	if(is_sorted(a))
	{
		free(a);
		return (0);
	}

	free_stack(&a);
	free_stack(&b);
	return (0);


}