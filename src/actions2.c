#include "push_swap.h"

void rotate_to_top(t_stack_node **stack, t_stack_node *node)
{
    if (node->index <= stack_len(*stack) / 2)
        while ((*stack)->value != node->value)
            ra(stack);
    else
        while ((*stack)->value != node->value)
            rra(stack);
}

void rotate_to_bottom(t_stack_node **stack, t_stack_node *node)
{
    if (node->index <= stack_len(*stack) / 2)
        while (stack_last(*stack)->value != node->value)
            ra(stack);
    else
        while (stack_last(*stack)->value != node->value)
            rra(stack);
}