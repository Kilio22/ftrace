/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** print_unsigned
*/

#include "strace.h"

int print_u_long_value(strace_t *strace_args __attribute__((unused)),
unsigned long long int value)
{
    fprintf(stderr, "%lu", (unsigned long)value);
    return 0;
}

int print_size_t_value(strace_t *strace_args __attribute__((unused)),
unsigned long long int value)
{
    fprintf(stderr, "%lu", (size_t)value);
    return 0;
}