#include "push_swap.h"

void swap(t_stack_node **stack)
{
    t_stack_node *tmp;
    if (!*stack || !(*stack)->next)
        return ;
    tmp = *stack;
    *stack = tmp->next;
    tmp->next = (*stack)->next;
    if ((*stack)->next)
        (*stack)->next->prev = tmp;
    (*stack)->next = tmp;
    (*stack)->prev = NULL;
    tmp->prev = *stack;
}

void push(t_stack_node **dst, t_stack_node **src)
{
    t_stack_node *tmp;

    if (!*src)
        return ;
    tmp = *src;
    *src = tmp->next;
    if (*src)
        (*src)->prev = NULL;
    if (!*dst)
    {
        *dst = tmp;
        tmp->prev = NULL;
        tmp->next = NULL;
    }
    else
    {
        tmp->next = *dst;
        (*dst)->prev = tmp;
        *dst = tmp;
    }
}

void rotate(t_stack_node **stack)
{
    t_stack_node *last_node;

    if (!*stack || !(*stack)->next)
        return ;
    last_node = stack_last(*stack);
    last_node->next = *stack;
    (*stack) = (*stack)->next;
    (*stack)->prev = NULL;
    last_node->next->next = NULL;
    last_node->next->prev = last_node;
}

void reverse_rotate(t_stack_node **stack)
{
    t_stack_node *last_node;

    if (!*stack || !(*stack)->next)
        return ;
    last_node = stack_last(*stack);
    last_node->prev->next = NULL;
    last_node->next = *stack;
    last_node->prev = NULL;
    (*stack) = last_node;
    last_node->next->prev = last_node;
}
