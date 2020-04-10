/*
** EPITECH PROJECT, 2019
** Repo_starter
** File description:
** main
*/

#include <stdlib.h>
#include "strace.h"

int main(int ac, char **av)
{
    strace_t strace = {0};

    if (ac < 2)
        return 84;
    if (start_prog_to_trace(&strace, av) == -1)
        return 84;
    return trace_prog(&strace);
}
