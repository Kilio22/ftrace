/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** print_hexa
*/

#include "strace.h"

int print_hexa_value(strace_t *strace __attribute__((unused)),
unsigned long long int value)
{
    fprintf(stderr, "0x%llx", value);
    return 0;
}