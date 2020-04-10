/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** parse_args
*/

#include <getopt.h>
#include "strace.h"

static const char optstring[] = "-sp:";

static const arg_t args[ARGS_NB] = {
    {'s', change_detailled_mode},
    {'p', &change_pid},
    {1, &change_prog_to_trace},
};

int handle_arg(int opt, strace_t *strace_args)
{
    for (size_t i = 0; i < ARGS_NB; i++) {
        if (args[i].c == opt)
            return args[i].change(strace_args, optarg);
    }
    return -1;
}

int parse_args(int ac, char **av, strace_t *strace_args)
{
    int opt = 0;

    strace_args->args = malloc(sizeof(char *));
    if (!strace_args->args)
        return -1;
    strace_args->args[0] = NULL;
    while ((opt = getopt(ac, av, optstring)) != -1) {
        if (handle_arg(opt, strace_args) == -1)
            return -1;
    }
    return 0;
}