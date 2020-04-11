/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** get_function_name
*/

#include "ftrace.h"

long analyse_function_9a(ftrace_t *ftrace, unsigned long long rip)
{
    (void)rip;
    return enter_function(ftrace, strdup("9A"), 0);
}
