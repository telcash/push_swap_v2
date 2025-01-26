#include "push_swap.h"

static void init_node(t_stack_node **new, int value, int index, t_stack_node *prev)
{
    (*new)->value = value;
    (*new)->index = index;
    (*new)->prev = prev;
    (*new)->next = NULL;
}

void init_stack(t_stack_node **stack, char **args)
{
    int index;
    int *values;
    t_stack_node *new;

    values = check_args(args);
    if (!values)
        return ;
    index = 0;
    while (args[index])
    {
        new = (t_stack_node *)malloc(sizeof(t_stack_node));
        if (!new)
        {
            free(values);
            free_stack(stack);
            return ;
        }
        init_node(&new, values[index], index, stack_last(*stack));
        index++;
        if (!*stack)
            *stack = new;
        else
            stack_last(*stack)->next = new;
    }
    free(values);    
}

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