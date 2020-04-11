/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** print_signal
*/

#include "ftrace.h"

void print_signal(int signal_value, ftrace_t *ftrace)
{
    for (size_t count = 0; my_signals[count].name != NULL; count++) {
        if (my_signals[count].value == signal_value) {
            fprintf(stderr, "%ld. Received signal %s\n",
            ftrace->counter, my_signals[count].name);
            ftrace->counter++;
        }
    }
}