/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** opcode_ff2
*/

#include "ftrace.h"

static int get_regs(ftrace_t *ftrace, int64_t *regs)
{
    struct user_regs_struct r = {};

    if (ptrace(PTRACE_GETREGS, ftrace->pid, 0, &r) == -1)
        return -1;
    regs[0] = r.rax;
    regs[1] = r.rcx;
    regs[2] = r.rdx;
    regs[3] = r.rbx;
    regs[4] = r.rsp;
    regs[5] = r.rbp;
    regs[6] = r.rsi;
    regs[7] = r.rdi;
    return 0;
}

long analyse_function_ff2(ftrace_t *ftrace, uint64_t rip, uint8_t modrm)
{
    int64_t regs[8];
    int32_t value = get_disp(ftrace, rip, modrm);
    char *f_name = NULL;

    if (value == -1)
        return -1;
    if (modrm % 8 == 4 && modrm != 0xD4)
        return enter_function(ftrace,
make_function_name(rip, ftrace->binary_name), 0);
    if (get_regs(ftrace, regs) == -1)
        return -1;
    else if (modrm != 0x15)
        value += regs[modrm % 8];
    f_name = get_symbol(ftrace, value);
    return enter_function(ftrace, f_name, value);
}
