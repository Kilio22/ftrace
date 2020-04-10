/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** print_hexa
*/

#include "ftrace.h"

int print_hexa_value(ftrace_t *ftrace __attribute__((unused)),
unsigned long long int value)
{
    fprintf(stderr, "0x%llx", value);
    return 0;
}