/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** strace_prog
*/

#include "strace.h"

long get_rip_value(strace_t *strace_args, struct user_regs_struct *registers)
{
    if (ptrace(PTRACE_GETREGS, strace_args->pid, 0, registers) == -1)
        return -1;
    return ptrace(PTRACE_PEEKTEXT, strace_args->pid, registers->rip);
}

int trace_prog(strace_t *strace_args)
{
    int wstatus = 0;
    struct user_regs_struct registers = {0};
    long rip_value = 0;
    long ret_val = -2;

    while (42) {
        waitpid(strace_args->pid, &wstatus, 0);
        if (wstatus >> 8 == (SIGTRAP | (PTRACE_EVENT_EXIT << 8)))
            return handle_end_of_prog(strace_args, wstatus);
        rip_value = get_rip_value(strace_args, &registers);
        if (rip_value == -1)
            return 84;
        if ((rip_value & 0xFFFF) == 0x050f)
            ret_val = get_syscall_infos(strace_args, &registers);
        if (ret_val != -2)
            return ret_val;
        if (ptrace(PTRACE_SINGLESTEP, strace_args->pid, 0, 0) == -1)
            return 84;
    }
    return 0;
}