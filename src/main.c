/*
** EPITECH PROJECT, 2019
** Repo_starter
** File description:
** main
*/

#include "ftrace.h"

int main(int ac, char **av)
{
    ftrace_t ftrace = {0};
    int fd = 0;
    int ret_val = 0;

    if (ac != 2)
        return FTRACE_FAILURE;
    if (init_fct_stack(&ftrace.stack) == -1)
        return FTRACE_FAILURE;
    if (start_prog_to_trace(&ftrace, av) == -1)
        return FTRACE_FAILURE;
    fd = start_elf(&ftrace, av[1]);
    if (fd == -1)
        return FTRACE_FAILURE;
    ret_val = trace_prog(&ftrace);
    end_elf(&ftrace, fd);
    return ret_val;
}
