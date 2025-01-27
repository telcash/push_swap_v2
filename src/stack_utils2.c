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

t_stack_node *stack_next_bigger(int value, t_stack_node *stack)
{
    t_stack_node *next_bigger;

    next_bigger = NULL;
    while (stack)
    {
        if (stack->value > value && (!next_bigger || stack->value < next_bigger->value))
            next_bigger = stack;
        stack = stack->next;
    }
    return (next_bigger);
}

t_stack_node *stack_next_lower(int value, t_stack_node *stack)
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