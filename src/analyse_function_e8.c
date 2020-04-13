/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** get_function_name
*/

#include "ftrace.h"

static long calculate_dynamic_offset(ftrace_t *ftrace,
unsigned long call_addr)
{
    long jmpoffset = 0;
    unsigned long offset = 0;
    long value = ptrace(PTRACE_PEEKTEXT, ftrace->pid, call_addr + 2);

    if (value == -1)
        return -1;
    jmpoffset = value & 0xFFFFFFFF;
    offset = call_addr + 6 + jmpoffset;
    return offset;
}

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
    long dynamic_offset = 0;
    unsigned long symbol_address = 0;
    char *f_name;

    if (offset == -1)
        return -1;
    symbol_address = next_instuction_address + offset;
    f_name = find_local_symbol(ftrace, symbol_address);
    if (f_name)
        return enter_function(ftrace, f_name, symbol_address);
    if (ftrace->library_list == NULL)
        set_list_library(ftrace);
    dynamic_offset = calculate_dynamic_offset(ftrace, symbol_address);
    if (ftrace->library_list == NULL || dynamic_offset == -1)
        return enter_function(ftrace, make_function_name(symbol_address, "toto"), symbol_address);
    f_name = find_dynamic_symbol(ftrace, dynamic_offset);
    if (f_name)
        return enter_function(ftrace, f_name, symbol_address);
    return enter_function(ftrace, make_function_name(symbol_address, "toto"), symbol_address);
}
