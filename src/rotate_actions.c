#include "push_swap.h"

void ra(t_stack_node **a)
{
    rotate(a);
    refresh_index(a);
    ft_putstr_fd("ra\n", 1);
}

void rb(t_stack_node **b)
{
    rotate(b);
    refresh_index(b);
    ft_putstr_fd("rb\n", 1);
}

void rr(t_stack_node **a, t_stack_node **b)
{
    rotate(a);
    rotate(b);
    refresh_index(a);
    refresh_index(b);
    ft_putstr_fd("rr\n", 1);
}
