/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** print_decimal
*/

#include "strace.h"

int print_decimal_value(strace_t *strace_args __attribute__((unused)),
unsigned long long int value)
{
    fprintf(stderr, "%d", (int)value);
    return 0;
}