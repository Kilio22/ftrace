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

long analyse_function_e8(ftrace_t *ftrace, unsigned long long rip)
{
    long offset = get_offset(ftrace, rip);
    long next_instuction_address = rip + 5;
    unsigned long symbol_address = 0;
    char *f_name;

    if (offset == -1)
        return -1;
    symbol_address = next_instuction_address + offset;
    f_name = get_function_name(ftrace, symbol_address);
    return enter_function(&ftrace->stack,
        f_name, symbol_address, &ftrace->counter);
}
