#include "push_swap.h"

static t_stack_node *stack_next_lower(int value, t_stack_node *stack)
{
    t_stack_node *next_lower;

    next_lower = NULL;
    while (stack)
    {
        if (stack->value < value && (!next_lower || stack->value > next_lower->value))
            next_lower = stack;
        stack = stack->next;
    }
    return (next_lower);
}

static int calculate_cost(t_stack_node *a, t_stack_node *b, int stack_len_a, int stack_len_b)
{
    int rotate_together;
    int reverse_rotate_together;
    int rotate_separately;

    rotate_together = find_max(2, a->index, b->index);
    reverse_rotate_together = find_max(2, stack_len_a - a->index, stack_len_b - b->index);
    rotate_separately = find_min(2, a->index, stack_len_a - a->index) + find_min(2, b->index, stack_len_b - b->index);
    return (find_min(3, rotate_together, reverse_rotate_together, rotate_separately));
}

void find_cheapest_move(t_stack_node *a, t_stack_node *b, t_stack_node **a_target, t_stack_node **b_target)
{
    int cost;
    int tmp_cost;
    t_stack_node *tmp;
    int a_len;

    cost = INT_MAX;
    a_len = stack_len(a);
    while (a)
    {
        tmp = stack_next_lower(a->value, b);
        if (!tmp)
            tmp = stack_max(b);
        tmp_cost = calculate_cost(a, tmp, a_len, stack_len(b));
        if (tmp_cost < cost)
        {
            cost = tmp_cost;
            *b_target = tmp;
            *a_target = a;
        }
        a = a->next;
    }
}
