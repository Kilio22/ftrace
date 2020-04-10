/*
** EPITECH PROJECT, 2019
** Repo_starter
** File description:
** main
*/

#include <stdlib.h>
#include "strace.h"

int main(int ac, char **av)
{
    strace_t strace_args = {0};

    if (parse_args(ac, av, &strace_args) == -1)
        return 84;
    if (strace_args.prog_to_trace == NULL && strace_args.pid == 0)
        return 84;
    if (strace_args.is_pid_mode == true) {
        if (attach_to_pid(&strace_args) == -1)
            return 84;
    } else {
        if (start_prog_to_trace(&strace_args) == -1)
            return 84;
    }
    return trace_prog(&strace_args);
}
