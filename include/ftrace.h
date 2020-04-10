/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** ftrace
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
#include <signal.h>
#include <fcntl.h>
#include <libelf.h>
#include <gelf.h>

#define ARGS_NB 3
#define SYSCALLS_NB 313
#define SIGNALS_NB 30
#define BUFF_SIZE 4096
#define FTRACE_EXIT_FAILURE 84
#define FTRACE_EXIT_SUCCESS 0

typedef struct ftrace_s ftrace_t;

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
typedef struct my_signal_s my_signal_t;
typedef int (* const printer_fcts_t)(ftrace_t *ftrace,
unsigned long long int value);

struct my_syscall_arg_s
{
    enum ret_val_type_e val_type;
    int (*callback)(ftrace_t *ftrace, unsigned long long int value);
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

struct ftrace_s
{
    char **args;
    pid_t pid;
    Elf *elf_file;
    GElf_Shdr *symbol_header;
    size_t counter;
};

struct my_signal_s
{
    char *name;
    int value;
};

extern const my_syscall_t my_syscalls[SYSCALLS_NB];
extern const my_signal_t my_signals[SIGNALS_NB];
// Start given program
int start_prog_to_trace(ftrace_t *ftrace, char **av);

// To trace program
int trace_prog(ftrace_t *ftrace);
long handle_end_of_prog(ftrace_t *ftrace, int wstatus);
long get_syscall_infos(ftrace_t *ftrace,
struct user_regs_struct *registers);
char *get_function_name(ftrace_t *ftrace, long rip_value);

// Elf utils
int start_elf(ftrace_t *ftrace, char *filepath);

// For the print
int print_hexa_value(ftrace_t *ftrace, unsigned long long int value);
void print_signal(int signal_value);

//To detect signals
int detect_signal(int wstatus, ftrace_t *ftrace);

#endif /* !STRACE_H_ */
