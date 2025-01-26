#include "push_swap.h"

static void sort_three(t_stack_node **a)
{
    if (is_stack_sorted(*a))
        return ;
    if ((*a)->value > (*a)->next->value && (*a)->value > (*a)->next->next->value)
    {
        ra(a);
        if ((*a)->value > (*a)->next->value)
            sa(a);
    }
    else if ((*a)->next->value > (*a)->value && (*a)->next->value > (*a)->next->next->value)
    {
        rra(a);
        if ((*a)->value > (*a)->next->value)
            sa(a);
    }
    else
        sa(a);
}

static void sort_five(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *next_bigger;
    
    while (stack_len(*a) > 3)
        pb(a, b);
    sort_three(a);
    while (*b)
    {
        next_bigger = stack_next_bigger(*a, (*b)->value);
        if (next_bigger->value > (*b)->value)
            rotate_to_top(a, next_bigger);
        else
            rotate_to_bottom(a, next_bigger);
        pa(a, b);
    }
    rotate_to_top(a, stack_min(*a));
}

static void sort_general(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *a_target;
    t_stack_node *b_target;

    pb(a, b);
    while (*a)
    {
        a_target = NULL;
        b_target = NULL;
        find_cheapest_move(*a, *b, &a_target, &b_target);
        execute_move(a, b, &a_target, &b_target);
    }
    while (*b)
        pa(a, b);
    rotate_to_top(a, stack_min(*a));
}

void push_swap(t_stack_node **a, t_stack_node **b)
{
    if (is_stack_sorted(*a))
        return ;
    if (stack_len(*a) == 2)
        sa(a);
    else if (stack_len(*a) == 3)
        sort_three(a);
    else if (stack_len(*a) <= 5)
        sort_five(a,b);
    else
        sort_general(a,b);
}