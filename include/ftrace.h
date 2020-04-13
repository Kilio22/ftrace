/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** ftrace
*/

#ifndef STRACE_H_
#define STRACE_H_

#include <ctype.h>
#include <fcntl.h>
#include <gelf.h>
#include <libelf.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include "codes.h"
#include "fct_stack.h"
#include "parser.h"

#define SYSCALLS_NB 313
#define SIGNALS_NB 30
#define BUFF_SIZE 4096

#define CANNOT_GET_DYN_FUNCTIONS ftrace->elf.plt_data == NULL ||\
ftrace->elf.plt_shdr == NULL ||\
ftrace->elf.dyn_data == NULL || ftrace->elf.dyn_shdr == NULL

#define GETSYM(data, ndx, dst) gelf_getsym(data, ndx, dst)

#define GET_SYM_NAME(elf, index, offset) strdup(elf_strptr(elf, index, offset))

#define ANALYSE_OP_IF(opcode)             \
    if ((rip_value & 0xFF) == 0x##opcode) \
    analyse_function_##opcode(ftrace, registers.rip)

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

struct elf_file_s {
    Elf *elf;
    GElf_Shdr *sym_shdr;
    Elf_Data *sym_data;
    GElf_Shdr *plt_shdr;
    Elf_Data *plt_data;
    GElf_Shdr *dyn_shdr;
    Elf_Data *dyn_data;
};

struct ftrace_s
{
    char **args;
    pid_t pid;
    size_t counter;
    struct elf_file_s elf;
    struct fct_stack_s stack;
    process_library_t **library_list;
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
long get_rip_value(ftrace_t *ftrace, struct user_regs_struct *registers);

/* Function analysis */
long analyse_function_e8(ftrace_t *ftrace, unsigned long long rip);
long analyse_function_ff(ftrace_t *ftrace, unsigned long long rip);

// To find symbols
char *find_dynamic_symbol(ftrace_t *ftrace, unsigned long offset);
char *find_local_symbol(ftrace_t *ftrace, unsigned long addr);

// Elf utils
int start_elf(ftrace_t *ftrace, char *filepath);
void end_elf(ftrace_t *ftrace, int fd);

// For the print
int print_hexa_value(ftrace_t *ftrace, unsigned long long int value);
void print_signal(int signal_value, ftrace_t *ftrace);
char *make_function_name(unsigned long addr, char *lib_name);

//To detect signals
int detect_signal(int wstatus, ftrace_t *ftrace);

void set_list_library(ftrace_t *ftrace);
process_library_t *find_library(ftrace_t *ftrace, unsigned long addr);

#endif /* !STRACE_H_ */
