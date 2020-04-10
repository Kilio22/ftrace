/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** change_prog
*/

#include <getopt.h>
#include <string.h>
#include "strace.h"

static size_t my_array_len(char **array)
{
    size_t i = 0;

    if (!array)
        return 0;
    for (; array[i]; i++);
    return i;
}

static int update_command_line(strace_t *strace_args, char *value)
{
    size_t len = my_array_len(strace_args->args);
    char **new_array = reallocarray(strace_args->args,
(len + 2), sizeof(char *));
    size_t i = len;

    if (!new_array)
        return -1;
    new_array[i] = strdup(value);
    if (!new_array[i])
        return -1;
    new_array[i + 1] = NULL;
    strace_args->args = new_array;
    return 0;
}

int change_prog_to_trace(strace_t *strace_args, char *value)
{
    static int old_opt_ind = 0;

    if (strace_args->prog_to_trace != NULL && (optind - 1 == old_opt_ind + 1)) {
        if (update_command_line(strace_args, value) == -1)
            return -1;
        old_opt_ind = optind - 1;
        return 0;
    } else if (strace_args->prog_to_trace != NULL)
        return -1;
    if (strace_args->is_pid_mode == true)
        return -1;
    old_opt_ind = optind - 1;
    if (update_command_line(strace_args, value) == -1)
        return -1;
    strace_args->prog_to_trace = strdup(value);
    return 0;
}