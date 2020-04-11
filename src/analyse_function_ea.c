/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** analyse_function_ea
*/

#include "ftrace.h"

long analyse_function_ea(ftrace_t *ftrace, unsigned long long rip)
{
    (void)rip;
    return enter_function(ftrace, strdup("FF"), 0);
}
