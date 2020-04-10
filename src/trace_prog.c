/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** ftrace_prog
*/

#include "ftrace.h"

static long get_rip_value(ftrace_t *ftrace, struct user_regs_struct *registers)
{
    if (ptrace(PTRACE_GETREGS, ftrace->pid, 0, registers) == -1)
        return -1;
    return ptrace(PTRACE_PEEKTEXT, ftrace->pid, registers->rip);
}

static long analyse_opcode(ftrace_t *ftrace)
{
    struct user_regs_struct registers = {0};
    long rip_value = get_rip_value(ftrace, &registers);

    if (rip_value == -1)
        return 84;
    if ((rip_value & 0xFFFF) == 0x050f)
        return get_syscall_infos(ftrace, &registers);
    if ((rip_value & 0xFF) == 0xe8) {
        printf("Found another symbol\n");
        get_function_name(ftrace, registers.rip);
        // return enter_function();
    }
    // if ((rip_value & 0xFF) == 0xc3) // Ret close function
    //     return leave_function();
    return FTRACE_OK;
}

int trace_prog(ftrace_t *ftrace)
{
    int wstatus = 0;
    long ret_val = FTRACE_OK;

    while (42) {
        waitpid(ftrace->pid, &wstatus, 0);
        // detect_signal(wstatus);
        if (wstatus >> 8 == (SIGTRAP | (PTRACE_EVENT_EXIT << 8)))
            return handle_end_of_prog(ftrace, wstatus);
        ret_val = analyse_opcode(ftrace);
        if (ret_val != FTRACE_OK)
            return ret_val;
        if (ptrace(PTRACE_SINGLESTEP, ftrace->pid, 0, 0) == -1)
            return FTRACE_FAILURE;
    }
    return FTRACE_SUCCESS;
}