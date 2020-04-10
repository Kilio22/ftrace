/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** signals
*/

#include "ftrace.h"

int detect_signal(int wstatus)
{
    if (wstatus >> 8 == (SIGTRAP | (PTRACE_EVENT_EXIT << 8)))
        return handle_end_of_prog(ftrace, wstatus);
    else
         print_signal(int wstatus)
}