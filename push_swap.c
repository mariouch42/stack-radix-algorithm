#include "push_swap.h"

static void	init_stack(t_stack **a, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack_add_back(a, create_node(arr[i]));
		i++;
	}
}

static void	run_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
	{
		index_stack(a);
		radix_sort(a, b);
	}
}

int	main(int argc, char **argv)
{
	int		*arr;
	int		size;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		return (0);
	arr = parse_input(argc, argv, &size);
	if (!arr)
		return (print_error(), 1);
	a = NULL;
	b = NULL;
	init_stack(&a, arr, size);
	free(arr);
	if (is_sorted(a))
		return (free_stack(&a), 0);
	run_sort(&a, &b, size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
