/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** change_detailled_mode
*/

#include "strace.h"

int change_detailled_mode(strace_t *strace_args, char *value)
{
    (void)value;
    strace_args->is_detailled_mode = true;
    return 0;
}