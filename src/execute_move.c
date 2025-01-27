#include "push_swap.h"

static void execute_move_rotate_together(t_stack_node **a, t_stack_node **b, t_stack_node **a_target, t_stack_node **b_target)
{
    while (*a != *a_target && *b != *b_target)
        rr(a, b);
    while (*a != *a_target)
        ra(a);
    while (*b != *b_target)
        rb(b);
}

static void execute_move_reverse_rotate_together(t_stack_node **a, t_stack_node **b, t_stack_node **a_target, t_stack_node **b_target)
{
    while (*a != *a_target && *b != *b_target)
        rrr(a, b);
    while (*a != *a_target)
        rra(a);
    while (*b != *b_target)
        rrb(b);
}

static void execute_move_rotate_separately(t_stack_node **a, t_stack_node **b, t_stack_node **a_target, t_stack_node **b_target)
{
    if ((*a_target)->index < stack_len(*a) / 2)
    {
        while (*a != *a_target)
            ra(a);
    }
    else
    {
        while (*a != *a_target)
            rra(a);
    }
    if ((*b_target)->index < stack_len(*b) / 2)
    {
        while (*b != *b_target)
            rb(b);
    }
    else
    {
        while (*b != *b_target)
            rrb(b);
    }
}

void execute_move(t_stack_node **a, t_stack_node **b, t_stack_node **a_target, t_stack_node **b_target)
{
    int rotate_together;
    int reverse_rotate_together;
    int rotate_separately;

    rotate_together = find_max(2, (*a_target)->index, (*b_target)->index);
    reverse_rotate_together = find_max(2, stack_len(*a) - (*a_target)->index, stack_len(*b) - (*b_target)->index);
    rotate_separately = find_min(2, (*a_target)->index, stack_len(*a) - (*a_target)->index) + find_min(2, (*b_target)->index, stack_len(*b) - (*b_target)->index);
    if (rotate_together == find_min(3, rotate_together, reverse_rotate_together, rotate_separately))
        execute_move_rotate_together(a, b, a_target, b_target);
    else if (reverse_rotate_together == find_min(3, rotate_together, reverse_rotate_together, rotate_separately))
        execute_move_reverse_rotate_together(a, b, a_target, b_target);
    else
        execute_move_rotate_separately(a, b, a_target, b_target);
    //pb(a, b);
}