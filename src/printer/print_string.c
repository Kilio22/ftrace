/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** print_string
*/

#include <errno.h>
#include "strace.h"

char *get_string(strace_t *strace_args, unsigned long long int addr)
{
    char *buff = NULL;
    size_t allocated = BUFF_SIZE;
    size_t offset = 0;
    long value = 0;

    buff = malloc(sizeof(char) * BUFF_SIZE);
    while (42) {
        value = ptrace(PTRACE_PEEKDATA, strace_args->pid, addr + offset, 0);
        if (value == -1)
            break;
        if (offset == allocated) {
            buff = realloc(buff, allocated + BUFF_SIZE);
            allocated += BUFF_SIZE;
        }
        buff[offset] = ((char *)&value)[0];
        if (buff[offset] == '\0')
            return buff;
        offset++;
    }
    return buff;
}

int print_string_value(strace_t *strace_args, unsigned long long int value)
{
    char *string = NULL;

    if (value == 0) {
        fprintf(stderr, "NULL");
        return 0;
    }
    string = get_string(strace_args, value);
    if (string == NULL) {
        return -1;
    } else {
        fprintf(stderr, "\"%s\"", string);
    }
    return 0;
}