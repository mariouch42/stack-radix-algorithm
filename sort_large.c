#include "push_swap.h"

void	index_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		rank;

	current = *stack;
	while (current)
	{
		compare = *stack;
		rank = 0;
		while (compare)
		{
			if (compare->value < current->value)
				rank++;
			compare = compare->next;
		}
		current->index = rank;
		current = current->next;
	}
}

int	get_max_bits(int max_num)
{
	int	bits;

	bits = 0;
	while ((max_num >> bits != 0))
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = stack_size(*a);
	max_bits = get_max_bits(size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
