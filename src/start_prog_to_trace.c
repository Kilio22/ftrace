/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** start_prog_to_trace
*/

#include "ftrace.h"

int start_prog_to_trace(ftrace_t *ftrace, char **av)
{
    pid_t pid = fork();
    int wstatus = 0;

    if (pid == 0) {
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        execvp(av[1], &av[1]);
        exit(0);
    } else {
        if (pid == -1)
            return -1;
        ftrace->pid = pid;
        ftrace->binary_name = av[1];
        waitpid(pid, &wstatus, 0);
        if (ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_TRACEEXIT) == -1)
            return -1;
        if (ptrace(PTRACE_SINGLESTEP, pid, 0, 0) == -1)
            return -1;
    }
    return 0;
}