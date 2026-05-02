#include "push_swap.h"

static	void	reverse_rotate(t_stack **stack)
{
	t_stack	*befor_last;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	befor_last = NULL;
	last = *stack;
	while (last->next)
	{
		befor_last = last;
		last = last->next;
	}
	befor_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write (1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write (1, "rrr\n", 4);
}
