/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** opcode_ff
*/

#include "ftrace.h"

static uint8_t get_modrm(ftrace_t *ftrace, long rip_value)
{
    long text = ptrace(PTRACE_PEEKTEXT, ftrace->pid, rip_value);
    uint8_t modrm = 0;

    if (text == -1)
        return -1;
    modrm = text & 0xFF;
    return modrm;
}

long analyse_function_ff(ftrace_t *ftrace, unsigned long long rip)
{
    uint8_t modrm = get_modrm(ftrace, rip + 1);

    if (((modrm >> 3) & 0b111) == 2)
        return analyse_function_ff2(ftrace, rip, modrm);
    return fprintf(stderr, "On a encore eu de la chance\n"), FTRACE_OK;
}
