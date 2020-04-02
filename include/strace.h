/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** strace
*/

#ifndef STRACE_H_
#define STRACE_H_

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include <errno.h>
#include <signal.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <syscall.h>
#include <unistd.h>

typedef struct arg_e {
    size_t number;
    void *arg;
} arg_t;

int parse_arg(int argc, char **argv);
int strace(char *command);
void print_type(size_t i, size_t count, unsigned long long int param, pid_t pi);

#endif /* !STRACE_H_ */
