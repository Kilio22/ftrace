/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** signals
*/

#include "ftrace.h"

int detect_signal(int wstatus, ftrace_t *ftrace)
{
    if (wstatus >> 8 == (SIGTRAP | (PTRACE_EVENT_EXIT << 8)))
        handle_end_of_prog(ftrace, wstatus);
    else if (WIFSIGNALED(wstatus)) {
        print_signal(WTERMSIG(wstatus), ftrace);
        return (1);
    }
    else if (WIFSTOPPED(wstatus)) {
        if (WSTOPSIG(wstatus) != SIGTRAP && WSTOPSIG(wstatus) != SIGSTOP) {
	        print_signal(WSTOPSIG(wstatus), ftrace);
            return (1);
        }
    }
    return (0);
}