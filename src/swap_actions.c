#include "push_swap.h"

void sa(t_stack_node **a)
{
    swap(a);
    refresh_index(a);
    ft_putstr_fd("sa\n", 1);
}

void sb(t_stack_node **b)
{
    swap(b);
    refresh_index(b);
    ft_putstr_fd("sb\n", 1);
}

void ss(t_stack_node **a, t_stack_node **b)
{
    swap(a);
    swap(b);
    refresh_index(a);
    refresh_index(b);
    ft_putstr_fd("ss\n", 1);
}