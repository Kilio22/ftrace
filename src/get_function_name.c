/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** get_function_name
*/

#include "ftrace.h"

static long get_offset(ftrace_t *ftrace, long rip_value)
{
    long ret_val = ptrace(PTRACE_PEEKTEXT, ftrace->pid, rip_value + 1);
    int offset = 0;

    if (ret_val == -1)
        return -1;
    offset = ret_val & 0xFFFFFFFF;
    return offset;
}

char *get_function_name(ftrace_t *ftrace, long rip_value)
{
    long offset = get_offset(ftrace, rip_value);
    long next_instuction_address = rip_value + 5;
    long symbol_address = 0;

    if (offset == -1) {
        printf("NULL\n");
        return NULL;
    }
    symbol_address = next_instuction_address + offset;

    printf("Offset = %ld, Address = %#lx\n", offset, symbol_address);
    return NULL;
}
