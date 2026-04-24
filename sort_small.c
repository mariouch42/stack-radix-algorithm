#include "push_swap.h"

void sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void sort_three(t_stack **a)
{
	int first;
	int second;
	int third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;

	if(first > second && second < third && first < third)
		sa(a);
	else if (first > second && second >third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static void push_min_to_b(t_stack **a, t_stack **b)
{
	int min;
	int pos;
	int size;

	min = get_min(*a);
	pos = get_position(*a, min);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while ((*a)->value != min)
			ra(a);
	}
	else
	{
		while ((*a)->value != min)
			rra(a);
	}
	pb(a, b);
}
void sort_five(t_stack **a, t_stack **b)
{
	int size;

	size = stack_size(*a);

	while (size > 3)
	{
		push_min_to_b(a, b);
		size--;

	}
	sort_three(a);
	while(*b)
		pa(a, b);
}