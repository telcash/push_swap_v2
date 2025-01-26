#include "push_swap.h"

void pa(t_stack_node **a, t_stack_node **b)
{
    push(a, b);
    refresh_index(a);
    refresh_index(b);
    ft_putstr_fd("pa\n", 1);
}

void pb(t_stack_node **a, t_stack_node **b)
{
    push(b, a);
    refresh_index(a);
    refresh_index(b);
    ft_putstr_fd("pb\n", 1);
}