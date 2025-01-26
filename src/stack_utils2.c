#include "push_swap.h"

t_stack_node *stack_min(t_stack_node *stack)
{
    t_stack_node *min;

    min = stack;
    while (stack)
    {
        if (stack->value < min->value)
            min = stack;
        stack = stack->next;
    }
    return (min);
}

t_stack_node *stack_max(t_stack_node *stack)
{
    t_stack_node *max;

    max = stack;
    while (stack)
    {
        if (stack->value > max->value)
            max = stack;
        stack = stack->next;
    }
    return (max);
}

int stack_len(t_stack_node *stack)
{
    int len;

    len = 0;
    while (stack)
    {
        len++;
        stack = stack->next;
    }
    return (len);
}

t_stack_node *stack_next_bigger(t_stack_node *stack, int value)
{
    t_stack_node *next_bigger;

    next_bigger = stack_max(stack);
    if (value > next_bigger->value)
        return (next_bigger);
    while (stack)
    {
        if (stack->value > value && stack->value < next_bigger->value)
            next_bigger = stack;
        stack = stack->next;
    }
    return (next_bigger);
}