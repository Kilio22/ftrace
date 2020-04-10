/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** syscalls
*/

#include "ftrace.h"

const my_syscall_t my_syscalls[SYSCALLS_NB] = {
    {
        .syscall_nb = 0,
        .fct_name = "read",
        .is_not_returning_value = false,
        .ret_val_type = SSIZE_T,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 1,
        .fct_name = "write",
        .is_not_returning_value = false,
        .ret_val_type = SSIZE_T,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 2,
        .fct_name = "open",
        .is_not_returning_value = false,
        .ret_val_type = INTEGER,
        .ac = 3,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 3,
        .fct_name = "close",
        .is_not_returning_value = false,
        .ret_val_type = INTEGER,
        .ac = 1,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 4,
        .fct_name = "stat",
        .is_not_returning_value = false,
        .ret_val_type = INTEGER,
        .ac = 2,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 5,
        .fct_name = "fstat",
        .is_not_returning_value = false,
        .ret_val_type = INTEGER,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 6,
        .fct_name = "lstat",
        .is_not_returning_value = false,
        .ret_val_type = INTEGER,
        .ac = 2,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 7,
        .fct_name = "poll",
        .is_not_returning_value = false,
        .ret_val_type = INTEGER,
        .ac = 3,
        .av = {
            {
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 8,
        .fct_name = "lseek",
        .is_not_returning_value = false,
        .ret_val_type = INTEGER,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = ULONG,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 9,
        .fct_name = "mmap",
        .is_not_returning_value = false,
        .ret_val_type = POINTER,
        .ac = 6,
        .av = {
            {
                .val_type = POINTER,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .callback = NULL
            },
            {
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = ULONG,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 10,
        .fct_name = "mprotect",
        .is_not_returning_value = false,
        .ret_val_type = INTEGER,
        .ac = 3,
        .av = {
            {
                .val_type = POINTER,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 11,
        .fct_name = "munmap",
        .is_not_returning_value = false,
        .ret_val_type = INTEGER,
        .ac = 2,
        .av = {
            {
                .val_type = POINTER,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 12,
        .fct_name = "brk",
        .is_not_returning_value = false,
        .ret_val_type = POINTER,
        .ac = 1,
        .av = {
            {
                .val_type = ULONG,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 13,
        .fct_name = "rt_sigaction",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 14,
        .fct_name = "rt_sigprocmask",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 15,
        .fct_name = "rt_sigreturn",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 16,
        .fct_name = "ioctl",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 17,
        .fct_name = "pread64",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 18,
        .fct_name = "pwrite64",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 19,
        .fct_name = "readv",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 20,
        .fct_name = "writev",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 21,
        .fct_name = "access",
        .is_not_returning_value = false,
        .ret_val_type = INTEGER,
        .ac = 2,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 22,
        .fct_name = "pipe",
        .is_not_returning_value = false,
        .ret_val_type = INTEGER,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 23,
        .fct_name = "select",
        .is_not_returning_value = false,
        .ret_val_type = INTEGER,
        .ac = 5,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 24,
        .fct_name = "sched_yield",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 25,
        .fct_name = "mremap",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = ULONG,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 26,
        .fct_name = "msync",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = POINTER,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 27,
        .fct_name = "mincore",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = POINTER,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 28,
        .fct_name = "madvise",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = POINTER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 29,
        .fct_name = "shmget",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 30,
        .fct_name = "shmat",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 31,
        .fct_name = "shmctl",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 32,
        .fct_name = "dup",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 33,
        .fct_name = "dup2",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 34,
        .fct_name = "pause",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0
    },
    {
        .syscall_nb = 35,
        .fct_name = "nanosleep",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 36,
        .fct_name = "getitimer",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 37,
        .fct_name = "alarm",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 38,
        .fct_name = "setitimer",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 39,
        .fct_name = "getpid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0
    },
    {
        .syscall_nb = 40,
        .fct_name = "sendfile",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = ULONG,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 41,
        .fct_name = "socket",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .callback = NULL
            },
            {
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 42,
        .fct_name = "connect",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 43,
        .fct_name = "accept",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 44,
        .fct_name = "sendto",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 6,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = POINTER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 45,
        .fct_name = "recvfrom",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 6,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = POINTER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 46,
        .fct_name = "sendmsg",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 47,
        .fct_name = "recvmsg",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 48,
        .fct_name = "shutdown",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 49,
        .fct_name = "bind",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 50,
        .fct_name = "listen",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 51,
        .fct_name = "getsockname",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 52,
        .fct_name = "getpeername",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 53,
        .fct_name = "socketpair",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 54,
        .fct_name = "setsockopt",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 55,
        .fct_name = "getsockopt",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 56,
        .fct_name = "clone",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 57,
        .fct_name = "fork",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0
    },
    {
        .syscall_nb = 58,
        .fct_name = "vfork",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0
    },
    {
        .syscall_nb = 59,
        .fct_name = "execve",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 60,
        .fct_name = "exit",
        .is_not_returning_value = true,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 61,
        .fct_name = "wait4",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 62,
        .fct_name = "kill",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 63,
        .fct_name = "uname",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 64,
        .fct_name = "semget",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 65,
        .fct_name = "semop",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 66,
        .fct_name = "semctl",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 67,
        .fct_name = "shmdt",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 68,
        .fct_name = "msgget",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 69,
        .fct_name = "msgsnd",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 70,
        .fct_name = "msgrcv",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 71,
        .fct_name = "msgctl",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 72,
        .fct_name = "fcntl",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 73,
        .fct_name = "flock",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 74,
        .fct_name = "fsync",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 75,
        .fct_name = "fdatasync",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 76,
        .fct_name = "truncate",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 77,
        .fct_name = "ftruncate",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 78,
        .fct_name = "getdents",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 79,
        .fct_name = "getcwd",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 80,
        .fct_name = "chdir",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 81,
        .fct_name = "fchdir",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 82,
        .fct_name = "rename",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 83,
        .fct_name = "mkdir",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 84,
        .fct_name = "rmdir",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 85,
        .fct_name = "creat",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 86,
        .fct_name = "link",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 87,
        .fct_name = "unlink",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 88,
        .fct_name = "symlink",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 89,
        .fct_name = "readlink",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 90,
        .fct_name = "chmod",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 91,
        .fct_name = "fchmod",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 92,
        .fct_name = "chown",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 93,
        .fct_name = "fchown",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 94,
        .fct_name = "lchown",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 95,
        .fct_name = "umask",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 96,
        .fct_name = "gettimeofday",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 97,
        .fct_name = "getrlimit",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 98,
        .fct_name = "getrusage",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 99,
        .fct_name = "sysinfo",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 100,
        .fct_name = "times",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 101,
        .fct_name = "ptrace",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = POINTER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 102,
        .fct_name = "getuid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 103,
        .fct_name = "syslog",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 104,
        .fct_name = "getgid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 105,
        .fct_name = "setuid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 106,
        .fct_name = "setgid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 107,
        .fct_name = "geteuid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 108,
        .fct_name = "getegid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 109,
        .fct_name = "setpgid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 110,
        .fct_name = "getppid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 111,
        .fct_name = "getpgrp",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 112,
        .fct_name = "setsid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 113,
        .fct_name = "setreuid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 114,
        .fct_name = "setregid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 115,
        .fct_name = "getgroups",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 116,
        .fct_name = "setgroups",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 117,
        .fct_name = "setresuid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 118,
        .fct_name = "getresuid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 119,
        .fct_name = "setresgid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 120,
        .fct_name = "getresgid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 121,
        .fct_name = "getpgid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 122,
        .fct_name = "setfsuid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 123,
        .fct_name = "setfsgid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 124,
        .fct_name = "getsid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 125,
        .fct_name = "capget",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 126,
        .fct_name = "capset",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 127,
        .fct_name = "rt_sigpending",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 128,
        .fct_name = "rt_sigtimedwait",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 129,
        .fct_name = "rt_sigqueueinfo",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 130,
        .fct_name = "rt_sigsuspend",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 131,
        .fct_name = "sigaltstack",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 132,
        .fct_name = "utime",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 133,
        .fct_name = "mknod",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 134,
        .fct_name = "uselib",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 135,
        .fct_name = "personality",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 136,
        .fct_name = "ustat",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 137,
        .fct_name = "statfs",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 138,
        .fct_name = "fstatfs",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 139,
        .fct_name = "sysfs",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 140,
        .fct_name = "getpriority",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 141,
        .fct_name = "setpriority",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 142,
        .fct_name = "sched_setparam",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 143,
        .fct_name = "sched_getparam",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 144,
        .fct_name = "sched_setscheduler",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 145,
        .fct_name = "sched_getscheduler",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 146,
        .fct_name = "sched_get_priority_max",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 147,
        .fct_name = "sched_get_priority_min",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 148,
        .fct_name = "sched_rr_get_interval",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 149,
        .fct_name = "mlock",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = POINTER,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 150,
        .fct_name = "munlock",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = POINTER,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 151,
        .fct_name = "mlockall",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 152,
        .fct_name = "munlockall",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 153,
        .fct_name = "vhangup",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 154,
        .fct_name = "modify_ldt",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 155,
        .fct_name = "pivot_root",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 156,
        .fct_name = "_sysctl",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 157,
        .fct_name = "prctl",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 158,
        .fct_name = "arch_prctl",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = POINTER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 159,
        .fct_name = "adjtimex",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 160,
        .fct_name = "setrlimit",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 161,
        .fct_name = "chroot",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 162,
        .fct_name = "sync",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 163,
        .fct_name = "acct",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 164,
        .fct_name = "settimeofday",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 165,
        .fct_name = "mount",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 166,
        .fct_name = "umount2",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 167,
        .fct_name = "swapon",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 168,
        .fct_name = "swapoff",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 169,
        .fct_name = "reboot",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 170,
        .fct_name = "sethostname",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 171,
        .fct_name = "setdomainname",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 172,
        .fct_name = "iopl",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 173,
        .fct_name = "ioperm",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 174,
        .fct_name = "create_module",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 175,
        .fct_name = "init_module",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 176,
        .fct_name = "delete_module",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 177,
        .fct_name = "get_kernel_syms",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 178,
        .fct_name = "query_module",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 179,
        .fct_name = "quotactl",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = POINTER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 180,
        .fct_name = "nfsservctl",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 181,
        .fct_name = "getpmsg",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 182,
        .fct_name = "putpmsg",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 183,
        .fct_name = "afs_syscall",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 184,
        .fct_name = "tuxcall",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 185,
        .fct_name = "security",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 186,
        .fct_name = "gettid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 187,
        .fct_name = "readahead",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = ULONG,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 188,
        .fct_name = "setxattr",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 189,
        .fct_name = "lsetxattr",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 190,
        .fct_name = "fsetxattr",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 191,
        .fct_name = "getxattr",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 192,
        .fct_name = "lgetxattr",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 193,
        .fct_name = "fgetxattr",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 194,
        .fct_name = "listxattr",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 195,
        .fct_name = "llistxattr",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 196,
        .fct_name = "flistxattr",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 197,
        .fct_name = "removexattr",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 198,
        .fct_name = "lremovexattr",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 199,
        .fct_name = "fremovexattr",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 200,
        .fct_name = "tkill",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 201,
        .fct_name = "time",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 202,
        .fct_name = "futex",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 6,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 203,
        .fct_name = "sched_setaffinity",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 204,
        .fct_name = "sched_getaffinity",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 205,
        .fct_name = "set_thread_area",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 206,
        .fct_name = "io_setup",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 207,
        .fct_name = "io_destroy",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 208,
        .fct_name = "io_getevents",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 209,
        .fct_name = "io_submit",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 210,
        .fct_name = "io_cancel",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 211,
        .fct_name = "get_thread_area",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 212,
        .fct_name = "lookup_dcookie",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 213,
        .fct_name = "epoll_create",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 214,
        .fct_name = "epoll_ctl_old",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 215,
        .fct_name = "epoll_wait_old",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 216,
        .fct_name = "remap_file_pages",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = POINTER,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 217,
        .fct_name = "getdents64",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 218,
        .fct_name = "set_tid_address",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 219,
        .fct_name = "restart_syscall",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 220,
        .fct_name = "semtimedop",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 221,
        .fct_name = "fadvise64",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = ULONG,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 222,
        .fct_name = "timer_create",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 223,
        .fct_name = "timer_settime",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 224,
        .fct_name = "timer_gettime",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 225,
        .fct_name = "timer_getoverrun",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 226,
        .fct_name = "timer_delete",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 227,
        .fct_name = "clock_settime",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 228,
        .fct_name = "clock_gettime",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 229,
        .fct_name = "clock_getres",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 230,
        .fct_name = "clock_nanosleep",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 231,
        .fct_name = "exit_group",
        .is_not_returning_value = true,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 232,
        .fct_name = "epoll_wait",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 233,
        .fct_name = "epoll_ctl",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 234,
        .fct_name = "tgkill",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 235,
        .fct_name = "utimes",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 236,
        .fct_name = "vserver",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 237,
        .fct_name = "mbind",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 6,
        .av = {
            {
                .val_type = POINTER,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 238,
        .fct_name = "set_mempolicy",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 239,
        .fct_name = "get_mempolicy",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = POINTER,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 240,
        .fct_name = "mq_open",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 241,
        .fct_name = "mq_unlink",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 242,
        .fct_name = "mq_timedsend",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 243,
        .fct_name = "mq_timedreceive",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 244,
        .fct_name = "mq_notify",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 245,
        .fct_name = "mq_getsetattr",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 246,
        .fct_name = "kexec_load",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 247,
        .fct_name = "waitid",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 248,
        .fct_name = "add_key",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 249,
        .fct_name = "request_key",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 250,
        .fct_name = "keyctl",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 251,
        .fct_name = "ioprio_set",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 252,
        .fct_name = "ioprio_get",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 253,
        .fct_name = "inotify_init",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 0,
        .av = {
            { 0 }
        }
    },
    {
        .syscall_nb = 254,
        .fct_name = "inotify_add_watch",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 255,
        .fct_name = "inotify_rm_watch",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 256,
        .fct_name = "migrate_pages",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 257,
        .fct_name = "openat",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 258,
        .fct_name = "mkdirat",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 259,
        .fct_name = "mknodat",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 260,
        .fct_name = "fchownat",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 261,
        .fct_name = "futimesat",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 262,
        .fct_name = "newfstatat",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 263,
        .fct_name = "unlinkat",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 264,
        .fct_name = "renameat",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 265,
        .fct_name = "linkat",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 266,
        .fct_name = "symlinkat",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 267,
        .fct_name = "readlinkat",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 268,
        .fct_name = "fchmodat",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 269,
        .fct_name = "faccessat",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 270,
        .fct_name = "pselect6",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 6,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 271,
        .fct_name = "ppoll",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 272,
        .fct_name = "unshare",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 273,
        .fct_name = "set_robust_list",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 274,
        .fct_name = "get_robust_list",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 275,
        .fct_name = "splice",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 6,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 276,
        .fct_name = "tee",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 277,
        .fct_name = "sync_file_range",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = ULONG,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 278,
        .fct_name = "vmsplice",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 279,
        .fct_name = "move_pages",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 6,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 280,
        .fct_name = "utimensat",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 281,
        .fct_name = "epoll_pwait",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 6,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 282,
        .fct_name = "signalfd",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 283,
        .fct_name = "timerfd_create",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 284,
        .fct_name = "eventfd",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 285,
        .fct_name = "fallocate",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = ULONG,
                .callback = NULL
            },
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 286,
        .fct_name = "timerfd_settime",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 287,
        .fct_name = "timerfd_gettime",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 288,
        .fct_name = "accept4",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 289,
        .fct_name = "signalfd4",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 290,
        .fct_name = "eventfd2",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = SIZE_T,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 291,
        .fct_name = "epoll_create1",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 292,
        .fct_name = "dup3",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 293,
        .fct_name = "pipe2",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 294,
        .fct_name = "inotify_init1",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 295,
        .fct_name = "preadv",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 296,
        .fct_name = "pwritev",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 297,
        .fct_name = "rt_tgsigqueueinfo",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 298,
        .fct_name = "perf_event_open",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 299,
        .fct_name = "recvmmsg",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 300,
        .fct_name = "fanotify_init",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 301,
        .fct_name = "fanotify_mark",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 302,
        .fct_name = "prlimit64",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 303,
        .fct_name = "name_to_handle_at",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = STRING,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 304,
        .fct_name = "open_by_handle_at",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 305,
        .fct_name = "clock_adjtime",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 306,
        .fct_name = "syncfs",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 1,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 307,
        .fct_name = "sendmmsg",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 4,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 308,
        .fct_name = "setns",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 2,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 309,
        .fct_name = "getcpu",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 3,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 310,
        .fct_name = "process_vm_readv",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 6,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 311,
        .fct_name = "process_vm_writev",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 6,
        .av = {
            {
                .val_type = INTEGER,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = INTEGER,
                .callback = NULL
            },
        }
    },
    {
        .syscall_nb = 312,
        .fct_name = "kcmp",
        .is_not_returning_value = false,
        .ret_val_type = DEFAULT,
        .ac = 5,
        .av = {
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
            {
                .val_type = DEFAULT,
                .callback = NULL
            },
        }
    }
};
