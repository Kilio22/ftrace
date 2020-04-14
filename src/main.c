/*
** EPITECH PROJECT, 2019
** Repo_starter
** File description:
** main
*/

#include "ftrace.h"
#include "parser.h"

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
    init_list_symbols(&ftrace);
    fd = start_elf(&ftrace, av[1]);
    if (fd == -1)
        return FTRACE_FAILURE;
    display_list(&ftrace);
    ret_val = trace_prog(&ftrace);
    end_elf(&ftrace, fd);
    destroy_fct_stack(&ftrace.stack);
    if (ftrace.library_list != NULL)
        free_maps(ftrace.library_list);
    return ret_val;
}
