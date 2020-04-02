/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** main
*/

#include "strace.h"

void usage() 
{
    printf("USAGE: ./ftrace <command>]\n");
}

int parse_arg(int argc, char **argv)
{
    int res;

    if (argc != 2) {
        return (84);
    }
    res = (strace(argv[1]));
    return res;
}
