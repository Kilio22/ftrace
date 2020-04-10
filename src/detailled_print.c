/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** detailled_print
*/

#include "strace.h"

static printer_fcts_t printers[] = {
    &print_hexa_value,
    &print_pointer_value,
    &print_decimal_value,
    &print_string_value,
    &print_long_value,
    &print_size_t_value,
    &print_u_long_value,
    &print_ssize_t_value
};

int detailled_return_value_print(strace_t *strace_args,
enum ret_val_type_e val_type, unsigned long long int value)
{
    return printers[val_type](strace_args, value);
}

int detailled_print(strace_t *strace_args, my_syscall_arg_t arg,
unsigned long long int value)
{
    if (arg.callback != NULL) {
        return arg.callback(strace_args, value);
    } else {
        return printers[arg.val_type](strace_args, value);
    }
}