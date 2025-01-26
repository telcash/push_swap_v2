#include "push_swap.h"

static int is_num_dup(int *values, int i, long long num)
{
    int j;

    j = 0;
    while(j < i)
    {
        if (values[j] == num)
            return (1);
        j++;
    }
    return (0);
}

static int is_num_string(char *arg)
{
    while (*arg == 32 || (*arg >= 9 && *arg <= 13))
        arg++;
    if (*arg != '-' && *arg != '+' && !ft_isdigit(*arg))
        return (0);
    if (*arg == '-' || *arg == '+')
        arg++;
    if (!ft_isdigit(*arg))
        return (0);
    while (ft_isdigit(*arg))
        arg++;
    if (*arg)
        return (0);
    return (1);
}

static int get_args_len(char **args)
{
    int len;

    len = 0;
    while (args[len])
        len++;
    return (len);
}

int *check_args(char **args)
{
    int *values;
    long long num;
    int len;
    int index;

    len = get_args_len(args);
    values = (int *)malloc(sizeof(int) * len);
    if (!values)
        return (NULL);
    index = 0;
    while (args[index])
    {
        num = ft_atol(args[index]);
        if (num < INT_MIN || num >INT_MAX || !is_num_string(args[index]) || is_num_dup(values, index, num))
        {
            free(values);
            return (NULL);
        }
        values[index] = num;
        index++;
    }
    return (values);
}
