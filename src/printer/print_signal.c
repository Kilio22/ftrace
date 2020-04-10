/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** print_signal
*/

#include "ftrace.h"

void print_signal(int signal_value)
{
    for (size_t count; my_signals[count].name != NULL) ; count++) {
        if (signal_value == my_signals[count].value)
            printf("Received signal %s", my_signals[count].name);
    }
}