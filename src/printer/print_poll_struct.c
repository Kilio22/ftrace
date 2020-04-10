/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** print_poll_struct
*/

#include <signal.h>
#include <poll.h>
#include "strace.h"

static const my_flags_t poll_flags[] = {
    {POLLIN, "POLLIN"},
    {POLLPRI, "POLLPRI"},
    {POLLOUT, "POLLOUT"},
    {POLLERR, "POLLERR"},
    {POLLHUP, "POLLHUP"},
    {POLLNVAL, "POLLNVAL"},
    {0, NULL}
};

static void print_poll_flags(int value)
{
    int printed = 0;

    for (size_t i = 0; poll_flags[i].str != NULL; i++) {
        if (((value & poll_flags[i].value) == poll_flags[i].value)
&& printed > 0) {
            fprintf(stderr, "|%s", poll_flags[i].str);
            printed++;
        } else if (((value & poll_flags[i].value) ==
poll_flags[i].value) && printed == 0) {
            fprintf(stderr, "%s", poll_flags[i].str);
            printed++;
        }
    }
}

static int fill_ptr(strace_t *strace_args, void *ptr, size_t size,
unsigned long long int addr)
{
    long value = 0;

    for (size_t i = 0; i < size; i++) {
        value = ptrace(PTRACE_PEEKDATA, strace_args->pid, addr + i, 0);
        if (value == -1)
            return -1;
        memcpy((void *)((unsigned long)ptr + i), (void *)&value, 1);
    }
    return 0;
}

int print_poll_struct(strace_t *strace_args, unsigned long long int value)
{
    struct pollfd poll = {0};

    if (fill_ptr(strace_args, &poll, sizeof(struct pollfd), value) == -1)
        return -1;
    fprintf(stderr, "{fd=%d, events=", poll.fd);
    print_poll_flags(poll.events);
    fprintf(stderr, ", revents=");
    print_poll_flags(poll.revents);
    fprintf(stderr, "}");
    return 0;
}
