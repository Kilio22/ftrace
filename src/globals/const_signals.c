/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** const_signals
*/

#include "ftrace.h"

const my_signal_t my_signals[SIGNALS_NB] = {
    {"SIGHUP", SIGHUP},
    {"SIGINT", SIGINT},
    {"SIGQUIT", SIGQUIT},
    {"SIGILL", SIGILL},
    {"SIGTRAP", SIGTRAP},
    {"SIGABRT", SIGABRT},
    {"SIGBUS", SIGBUS},
    {"SIGFPE", SIGFPE},
    {"SIGKILL", SIGKILL},
    {"SIGUSR1", SIGUSR1},
    {"SIGPIPE", SIGPIPE},
    {"SIGALRM", SIGALRM},
    {"SIGTERM", SIGTERM},
    {"SIGSTKFLT", SIGSTKFLT},
    {"SIGCHLD", SIGCHLD},
    {"SIGCONT", SIGCONT},
    {"SIGSTOP", SIGSTOP},
    {"SIGTSTP", SIGTSTP},
    {"SIGTTIN", SIGTTIN},
    {"SIGTTOU", SIGTTOU},
    {"SIGURG", SIGURG},
    {"SIGXCPU", SIGXCPU},
    {"SIGXFSZ", SIGXFSZ},
    {"SIGVTALRM", SIGVTALRM},
    {"SIGPROF", SIGPROF},
    {"SIGWINCH", SIGWINCH},
    {"SIGIO", SIGIO},
    {"SIGPWR", SIGPWR},
    {"SIGSYS", SIGSYS},
    {NULL, 0},
};