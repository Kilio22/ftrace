/*
** EPITECH PROJECT, 2019
** PSU_strace_2019
** File description:
** strace
*/

#include "strace.h"
#include "syscall.h"

static void display_arguments(size_t i, struct user_regs_struct regs)
{
    printf("%s(", sys[i].str);
    for (size_t count = 0; count < sys[i].nb_arg; count++) {
        if (count == 0)
            printf("0x%llx", regs.rdi);
        if (count == 1)
            printf("0x%llx", regs.rsi);
        if (count == 2)
            printf("0x%llx", regs.rdx);
        if (count == 3)
            printf("0x%llx", regs.r10);
        if (count == 4)
            printf("0x%llx", regs.r8);
        if (count == 5)
            printf("0x%llx", regs.r9);
        if (count + 1 != sys[i].nb_arg)
            printf(", ");
    }
    printf(") = 0x%llx\n", regs.rax);
}


static void display_information(pid_t pid)
{
    struct user_regs_struct regs;

    ptrace(PTRACE_GETREGS, pid, NULL, &regs);
    for (size_t i = 0; i < 313; i++) {
        if (i == regs.orig_rax)
            display_arguments(i, regs);
    }
    ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
}

int strace(char *command)
{
    pid_t pid;
    int status;

    char *arg[] = {command, NULL};

    pid = fork();
    if (pid == -1)
        return (EXIT_FAILURE);
    if (pid == 0) {
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        if (execvp(command, arg) == -1)
            perror("execvp: ");
    }
    else {
        while (waitpid(pid, &status, 0) && !WIFEXITED(status))
            display_information(pid);
    }
    printf("exit_group(%d) = ?\n", WEXITSTATUS(status));
    printf("+++ exited with %d +++\n", WEXITSTATUS(status));
    return (0);
}