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
    int ret_val = 0;

    if (ac != 2)
        return FTRACE_FAILURE;
    if (init_fct_stack(&ftrace.stack) == -1)
        return FTRACE_FAILURE;
    if (start_prog_to_trace(&ftrace, av) == -1)
        return FTRACE_FAILURE;
    init_symbols_list(&ftrace);
    if (start_elf(&ftrace) == -1)
        return FTRACE_FAILURE;
    ret_val = trace_prog(&ftrace);
    end_elf(&ftrace);
    destroy_fct_stack(&ftrace.stack);
    if (ftrace.library_list != NULL)
        free_maps(ftrace.library_list);
    return ret_val;
}
