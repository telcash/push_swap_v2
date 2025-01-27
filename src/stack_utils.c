#include "push_swap.h"

t_stack_node *stack_last(t_stack_node *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

void free_stack(t_stack_node **stack)
{
    t_stack_node *tmp;

    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
}

int is_stack_sorted(t_stack_node *stack)
{
    while (stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void refresh_index(t_stack_node **stack)
{
    t_stack_node *tmp;
    int i;

    i = 0;
    tmp = *stack;
    while (tmp)
    {
        tmp->index = i++;
        tmp = tmp->next;
    }
}
