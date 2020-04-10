/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** attach_to_pid
*/

#include "strace.h"

int attach_to_pid(strace_t *strace_args)
{
    int wstatus = 0;

    if (ptrace(PTRACE_ATTACH, strace_args->pid, 0, 0) == -1)
        return -1;
    waitpid(strace_args->pid, &wstatus, 0);
    if (ptrace(PTRACE_SETOPTIONS, strace_args->pid,
0, PTRACE_O_TRACEEXIT) == -1)
        return -1;
    if (ptrace(PTRACE_SINGLESTEP, strace_args->pid, 0, 0) == -1)
        return -1;
    return 0;
}