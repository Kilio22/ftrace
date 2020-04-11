/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** signals
*/

#include "ftrace.h"

int detect_signal(int wstatus, ftrace_t *ftrace)
{
    siginfo_t signal;

    if (wstatus >> 8 == (SIGTRAP | (PTRACE_EVENT_EXIT << 8)))
        handle_end_of_prog(ftrace, wstatus);
    else if (ptrace(PTRACE_GETSIGINFO, ftrace->pid, 0, &signal) >= 0 &&
        signal.si_signo != SIGTRAP && signal.si_signo != SIGSTOP)
        print_signal(signal.si_signo, ftrace);
    return (0);
}