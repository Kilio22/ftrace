/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** start_prog_to_trace
*/

#include "strace.h"

int start_prog_to_trace(strace_t *strace_args)
{
    pid_t pid = fork();
    int wstatus = 0;

    if (pid == 0) {
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        execvp(strace_args->prog_to_trace, strace_args->args);
    } else {
        if (pid == -1)
            return -1;
        strace_args->pid = pid;
        waitpid(pid, &wstatus, 0);
        if (ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_TRACEEXIT) == -1)
            return -1;
        if (ptrace(PTRACE_SINGLESTEP, pid, 0, 0) == -1)
            return -1;
    }
    return 0;
}