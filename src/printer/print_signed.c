/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** print_signed
*/

#include "strace.h"

int print_long_value(strace_t *strace_args __attribute__((unused)),
unsigned long long int value)
{
    fprintf(stderr, "%ld", (long)value);
    return 0;
}

int print_ssize_t_value(strace_t *strace_args __attribute__((unused)),
unsigned long long int value)
{
    fprintf(stderr, "%ld", (ssize_t)value);
    return 0;
}