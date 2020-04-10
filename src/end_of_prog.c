/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** end_of_prog
*/

#include "ftrace.h"

long handle_end_of_prog(ftrace_t *ftrace, int wstatus)
{
    long exit_status = 0;

    if (ptrace(PTRACE_GETEVENTMSG, ftrace->pid, 0, &wstatus) == -1)
        return 84;
    exit_status = WEXITSTATUS(wstatus);
    fprintf(stderr, "+++ exited with %ld +++\n", exit_status);
    return exit_status;
}