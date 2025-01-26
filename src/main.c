#include "push_swap.h"

static void	free_matrix(char **m)
{
	size_t	i;

	i = 0;
	while (m[i])
	{
		free(m[i]);
		i++;
	}
	free(m);
}

static char **get_args(int argc, char **argv)
{
    if (argc == 2)
        return (ft_split(argv[1], ' '));
    return (argv + 1);
}

int main (int argc, char **argv)
{
    t_stack_node *a;
    t_stack_node *b;
    char **args;

    a = NULL;
    b = NULL;

    if (argc < 2)
        return (0);
    args = get_args(argc, argv);
    init_stack(&a, args);
    if (!a)
    {
        if (argc == 2)
            free_matrix(args);
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    push_swap(&a, &b);
    if (argc == 2)
        free_matrix(args);
    free_stack(&a);
    free_stack(&b);
    return (0);
}