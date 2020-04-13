/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** get_function_name
*/

#include "ftrace.h"

static long get_modrm(ftrace_t *ftrace, long rip_value)
{
    long ret_val = ptrace(PTRACE_PEEKTEXT, ftrace->pid, rip_value + 1);
    int mod = 0;

    if (ret_val == -1)
        return -1;
    mod = ret_val & 0xFF;
    return mod;
}

long analyse_function_ff(ftrace_t *ftrace, unsigned long long rip)
{
    long mod = get_modrm(ftrace, rip);

    mod >>= 3;
    mod &= 0b111;
    if (mod != 2 && mod != 3)
        return fprintf(stderr, "En a encore eu de la chance\n"), FTRACE_OK;
    return enter_function(ftrace, make_function_name(rip, "toto"), 0);
}
