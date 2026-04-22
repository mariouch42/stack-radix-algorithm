#include "push_swap.h"

static void push(t_stack **dst, t_stack **src)
{
	t_stack *tmp;
	if(!*src)
		return;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;

}
void pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}
void pb(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}