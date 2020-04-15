/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** get_disp
*/

#include "ftrace.h"

static int32_t read_disp(ftrace_t *ftrace, uint64_t addr)
{
    long text = ptrace(PTRACE_PEEKTEXT, ftrace->pid, addr);
    int32_t disp = 0;

    if (text == -1)
        return -1;
    disp = text;
    return disp;
}

int32_t get_disp(ftrace_t *ftrace, uint64_t rip, uint8_t modrm)
{
    int offset = (modrm % 8 == 4) ? 3 : 2;
    int32_t disp = 0;

    if (modrm == 15 || modrm / 10 == 5 || modrm / 10 == 9) {
        disp = read_disp(ftrace, rip + offset);
        if (disp == -1)
            return -1;
        if (modrm / 10 == 5)
            disp &= 0xFF;
    }
    return disp;
}
