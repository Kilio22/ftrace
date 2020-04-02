/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** main
*/

#include "strace.h"

void usage() 
{
    printf("USAGE: ./ftrace <command>]\n");
}

int main(int argc, char **argv)
{
    int opt;

    opt = getopt(argc, argv, "help");
    if (opt == 'h' || argc != 2) {
        usage();
        return 84;
    }
    return (strace(argv[1]));
}
