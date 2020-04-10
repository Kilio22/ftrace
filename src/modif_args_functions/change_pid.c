/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** change_pid
*/

#include "strace.h"

int change_pid(strace_t *strace_args, char *value)
{
    if (strace_args->prog_to_trace != NULL || value == NULL)
        return -1;
    strace_args->is_pid_mode = true;
    for (size_t i = 0; value[i]; i++) {
        if (!isdigit(value[i])) {
            return -1;
        }
    }
    strace_args->pid = (pid_t)atoi(value);
    return 0;
}