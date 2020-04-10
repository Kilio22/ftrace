/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** end_of_prog
*/

#include "strace.h"

int handle_end_of_prog(strace_t *strace_args, int wstatus)
{
    int exit_status = 0;

    if (ptrace(PTRACE_GETEVENTMSG, strace_args->pid, 0, &wstatus) == -1)
        return 84;
    exit_status = WEXITSTATUS(wstatus);
    fprintf(stderr, "+++ exited with %d +++\n", exit_status);
    return exit_status;
}