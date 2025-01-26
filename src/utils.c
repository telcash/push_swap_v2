#include "push_swap.h"

long long ft_atol(const char *nptr)
{
    int sign;
    long long num;

    sign = 1;
    num = 0;
    while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
        nptr++;
    if (*nptr == '-')
        sign = -1;
    if (*nptr == '-' || *nptr == '+')
        nptr++;
    while (ft_isdigit(*nptr))
    {
        num = num * 10 + *nptr - '0';
        nptr++;
    }
    return (num * sign);
}

int find_min(int count, ...)
{
    va_list args;
    int min;
    int tmp;

    va_start(args, count);
    min = va_arg(args, int);
    while (--count)
    {
        tmp = va_arg(args, int);
        if (tmp < min)
            min = tmp;
    }
    va_end(args);
    return (min);
}

int find_max(int count, ...)
{
    va_list args;
    int max;
    int tmp;

    va_start(args, count);
    max = va_arg(args, int);
    while (--count)
    {
        tmp = va_arg(args, int);
        if (tmp > max)
            max = tmp;
    }
    va_end(args);
    return (max);
}
