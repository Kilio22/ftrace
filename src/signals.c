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
        return handle_end_of_prog(ftrace, wstatus);
    if (WIFSIGNALED(wstatus)) {
        print_signal(wstatus);
        return (1);
    }
    return (0);
}