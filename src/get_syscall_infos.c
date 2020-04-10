/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** get_syscall_infos
*/

#include "strace.h"

static const my_syscall_t *get_syscall(unsigned long long int rax)
{
    for (size_t i = 0; i < SYSCALLS_NB; i++) {
        if (my_syscalls[i].syscall_nb == rax) {
            return &my_syscalls[i];
        }
    }
    return NULL;
}

static void get_registers_values(unsigned long long int (*registers_values)[6],
struct user_regs_struct *registers)
{
    (*registers_values)[0] = registers->rdi;
    (*registers_values)[1] = registers->rsi;
    (*registers_values)[2] = registers->rdx;
    (*registers_values)[3] = registers->r10;
    (*registers_values)[4] = registers->r8;
    (*registers_values)[5] = registers->r9;
}

static int get_return_value(strace_t *strace,
struct user_regs_struct *registers, const my_syscall_t *sys_call)
{
    int wstatus = 0;

    if (ptrace(PTRACE_SINGLESTEP, strace->pid, 0, 0) == -1)
        return 84;
    waitpid(strace->pid, &wstatus, 0);
    fprintf(stderr, " = ");
    if (sys_call->is_not_returning_value == true) {
        fprintf(stderr, "?\n");
    } else {
        if (ptrace(PTRACE_GETREGS, strace->pid, 0, registers) == -1)
            return 84;
        print_hexa_value(strace, registers->rax);
        fprintf(stderr, "\n");
    }
    if (wstatus >> 8 == (SIGTRAP | (PTRACE_EVENT_EXIT << 8)))
        return handle_end_of_prog(strace, wstatus);
    return -2;
}

int get_syscall_infos(strace_t *strace, struct user_regs_struct *registers)
{
    const my_syscall_t *sys_call = get_syscall(registers->rax);
    unsigned long long int registers_values[6] = {0};

    if (sys_call == NULL)
        return -2;
    get_registers_values(&registers_values, registers);
    fprintf(stderr, "%ld. %s(", strace->counter, sys_call->fct_name);
    strace->counter++;
    for (size_t i = 0; i < sys_call->ac; i++) {
        print_hexa_value(strace, registers_values[i]);
        if (i + 1 < sys_call->ac)
            fprintf(stderr, ", ");
    }
    fprintf(stderr, ")");
    return get_return_value(strace, registers, sys_call);
}