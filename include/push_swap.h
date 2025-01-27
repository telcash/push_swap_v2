#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/include/libft.h"
# include <limits.h>
# include <stdarg.h>

typedef struct s_stack_node
{
    int                 value;
    int                 index;
    struct s_stack_node *prev;
    struct s_stack_node *next;
}                       t_stack_node;

int                     *check_args(char **args);
void                    push_swap(t_stack_node **a, t_stack_node **b);
int                     find_cheapest_move_ab(t_stack_node *a, t_stack_node *b, t_stack_node **a_target, t_stack_node **b_target);
int                     find_cheapest_move_ba(t_stack_node *a, t_stack_node *b, t_stack_node **a_target, t_stack_node **b_target);
void                    execute_move(t_stack_node **a, t_stack_node **b, t_stack_node **a_target, t_stack_node **b_target);
void                    push(t_stack_node **dst, t_stack_node **src);
void                    swap(t_stack_node **stack);
void                    rotate(t_stack_node **stack);
void                    reverse_rotate(t_stack_node **stack);
void                    rotate_to_top(t_stack_node **stack, t_stack_node *node);
void                    rotate_to_bottom(t_stack_node **stack, t_stack_node *node);
void                    pa(t_stack_node **a, t_stack_node **b);
void                    pb(t_stack_node **a, t_stack_node **b);
void                    sa(t_stack_node **a);
void                    sb(t_stack_node **b);
void                    ss(t_stack_node **a, t_stack_node **b);
void                    ra(t_stack_node **a);
void                    rb(t_stack_node **b);
void                    rr(t_stack_node **a, t_stack_node **b);
void                    rra(t_stack_node **a);
void                    rrb(t_stack_node **b);
void                    rrr(t_stack_node **a, t_stack_node **b);
void                    init_stack(t_stack_node **stack, char **args);
t_stack_node            *stack_last(t_stack_node *stack);
void                    free_stack(t_stack_node **stack);
int                     is_stack_sorted(t_stack_node *stack);
void                    refresh_index(t_stack_node **stack);
t_stack_node            *stack_min(t_stack_node *stack);
t_stack_node            *stack_max(t_stack_node *stack);
int                     stack_len(t_stack_node *stack);
t_stack_node            *stack_next_bigger(int value, t_stack_node *stack);
t_stack_node            *stack_next_lower(int value, t_stack_node *stack);
long long               ft_atol(const char *nptr);
int                     find_min(int count, ...);
int                     find_max(int count, ...);
int                     ft_abs(int a, int b);
#endif