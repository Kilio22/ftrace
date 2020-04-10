/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** print_pointer
*/

#include "strace.h"

int print_pointer_value(strace_t *strace_args __attribute__((unused)),
unsigned long long int value)
{
    if (value == 0)
        fprintf(stderr, "NULL");
    else
        fprintf(stderr, "0x%llx", value);
    return 0;
}