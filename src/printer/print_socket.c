/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** print_socket
*/

#include <sys/socket.h>
#include "strace.h"

static const my_flags_t socket_domains[] = {
    {AF_UNIX, "AF_UNIX"},
    {AF_LOCAL, "AF_LOCAL"},
    {AF_INET, "AF_INET"},
    {AF_INET6, "AF_INET6"},
    {AF_IPX, "AF_IPX"},
    {AF_NETLINK, "AF_NETLINK"},
    {AF_X25, "AF_X25"},
    {AF_AX25, "AF_AX25"},
    {AF_ATMPVC, "AF_ATMPVC"},
    {AF_APPLETALK, "AF_APPLETALK"},
    {AF_PACKET, "AF_PACKET"},
    {AF_ALG, "AF_ALG"},
    {0, NULL}
};

static const my_flags_t socket_types[] = {
    {SOCK_STREAM, "SOCK_STREAM"},
    {SOCK_DGRAM, "SOCK_DGRAM"},
    {SOCK_SEQPACKET, "SOCK_SEQPACKET"},
    {SOCK_RAW, "SOCK_RAW"},
    {SOCK_RDM, "SOCK_RDM"},
    {SOCK_PACKET, "SOCK_PACKET"},
    {SOCK_NONBLOCK, "SOCK_NONBLOCK"},
    {SOCK_CLOEXEC, "SOCK_CLOEXEC"},
    {0, NULL}
};


int print_socket_type(strace_t *strace_args __attribute__((unused)),
unsigned long long int value)
{
    for (size_t i = 0; i < 6; i++) {
        if (value == socket_types[i].value) {
            fprintf(stderr, "%s", socket_types[i].str);
            break;
        }
    }
    for (size_t i = 6; socket_types[i].str != NULL; i++) {
        if (value == socket_types[i].value) {
            fprintf(stderr, "|%s", socket_types[i].str);
        }
    }
    return 0;
}


int print_socket_domain(strace_t *strace_args __attribute__((unused)),
unsigned long long int value)
{
    for (size_t i = 0; socket_domains[i].str != NULL; i++) {
        if (value == socket_domains[i].value) {
            fprintf(stderr, "%s", socket_domains[i].str);
            break;
        }
    }
    return 0;
}
