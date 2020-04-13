/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** get_function_name
*/

#include "ftrace.h"

long analyse_function_ff(ftrace_t *ftrace, unsigned long long rip)
{
    (void)rip;
    return enter_function(ftrace, make_function_name(rip, "toto"), 0);
}
