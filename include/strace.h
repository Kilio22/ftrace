/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** strace
*/

#ifndef STRACE_H_
#define STRACE_H_

#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/user.h>

#define ARGS_NB 3
#define SYSCALLS_NB 313
#define BUFF_SIZE 4096

typedef struct strace_s strace_t;
typedef struct arg_s arg_t;

enum ret_val_type_e
{
    DEFAULT,
    POINTER,
    INTEGER,
    STRING,
    LONG,
    SIZE_T,
    ULONG,
    SSIZE_T
};

typedef struct my_syscall_s my_syscall_t;
typedef struct my_syscall_arg_s my_syscall_arg_t;
typedef int (* const printer_fcts_t)(strace_t *strace_args,
unsigned long long int value);

struct my_syscall_arg_s
{
    enum ret_val_type_e val_type;
    int (*callback)(strace_t *strace_args, unsigned long long int value);
};

struct my_syscall_s
{
    unsigned long long int syscall_nb;
    char *fct_name;
    bool is_not_returning_value;
    enum ret_val_type_e ret_val_type;
    size_t ac;
    my_syscall_arg_t av[6];
};

struct arg_s
{
    int c;
    int (*change)(strace_t *strace_args, char *value);
};

struct strace_s
{
    char **args;
    pid_t pid;
};

extern const my_syscall_t my_syscalls[SYSCALLS_NB];

// Start given program
int start_prog_to_trace(strace_t *strace, char **av);

// To trace program
int trace_prog(strace_t *strace_args);
int handle_end_of_prog(strace_t *strace_args, int wstatus);
int get_syscall_infos(strace_t *strace_args,
struct user_regs_struct *registers);

// For the print
int print_hexa_value(strace_t *strace_args, unsigned long long int value);

#endif /* !STRACE_H_ */
