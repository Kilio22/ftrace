/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** error
*/

#include <criterion/criterion.h>
#include "fct_stack.h"
#include "parser.h"
#include "ftrace.h"

Test(ftrace, toto)
{
    ftrace_t ftrace = {0};
    char *opt[] = {"./ftrace", "/bin/ls", NULL};
    int fd;

    if (init_fct_stack(&ftrace.stack) == -1)
        return;
    if (start_prog_to_trace(&ftrace, opt) == -1)
        return;
    fd = start_elf(&ftrace, opt[1]);

    cr_assert_eq(trace_prog(&ftrace), 0);
    end_elf(&ftrace, fd);
}