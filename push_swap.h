#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct	s_stack	*next;
} t_stack;

int		*parse_input(int argc, char **argv, int *size);
void	print_error(void);

t_stack	*create_node(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
void	free_stack(t_stack **stack);
int		is_sorted(t_stack *stack);


void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

int     get_min(t_stack *stack);
int     get_max(t_stack *stack);
int     get_position(t_stack *stack, int value);
void    sort_two(t_stack **a);
void    sort_three(t_stack **a);
void    sort_five(t_stack **a, t_stack **b);
void	index_stack(t_stack **stack);
int		get_max_bits(int max_num);
void	radix_sort(t_stack **a, t_stack **b);

#endif