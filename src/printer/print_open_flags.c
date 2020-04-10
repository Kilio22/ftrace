/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** print_open_flags
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "strace.h"

static const my_flags_t open_flags[] = {
    {O_RDONLY, "O_RDONLY"},
    {O_WRONLY, "O_WRONLY"},
    {O_RDWR, "O_RDWR"},
    {O_CREAT, "O_CREAT"},
    {O_EXCL, "O_EXCL"},
    {O_NOCTTY, "O_NOCTTY"},
    {O_TRUNC, "O_TRUNC"},
    {O_APPEND, "O_APPEND"},
    {O_NONBLOCK, "O_NONBLOCK"},
    {O_NDELAY, "O_NDELAY"},
    {O_DSYNC, "O_DSYNC"},
    {O_ASYNC, "O_ASYNC"},
    {O_DIRECTORY, "O_DIRECTORY"},
    {O_NOFOLLOW, "O_NOFOLLOW"},
    {O_SYNC, "O_SYNC"},
    {0, NULL}
};

int print_open_flags(strace_t *strace_args __attribute__((unused)),
unsigned long long int value)
{
    int printed = 0;

    for (size_t i = 0; open_flags[i].str != NULL; i++) {
        if ((value & open_flags[i].value) == open_flags[i].value
&& printed > 0) {
            fprintf(stderr, "|%s", open_flags[i].str);
            printed++;
        } else if ((value & open_flags[i].value) == open_flags[i].value
&& printed == 0) {
            fprintf(stderr, "%s", open_flags[i].str);
            printed++;
        }
    }
    return 0;
}