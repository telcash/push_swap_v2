#include "push_swap.h"

void rra(t_stack_node **a)
{
    reverse_rotate(a);
    refresh_index(a);
    ft_putstr_fd("rra\n", 1);
}

void rrb(t_stack_node **b)
{
    reverse_rotate(b);
    refresh_index(b);
    ft_putstr_fd("rrb\n", 1);
}

void rrr(t_stack_node **a, t_stack_node **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    refresh_index(a);
    refresh_index(b);
    ft_putstr_fd("rrr\n", 1);
}