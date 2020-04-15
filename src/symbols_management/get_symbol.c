/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** get_symbol
*/

#include "ftrace.h"

char *get_symbol(ftrace_t *ftrace, unsigned long symbol_address)
{
    process_library_t *lib = get_lib(ftrace, symbol_address);
    struct symbols_s *symbols = NULL;
    char *f_name = NULL;

    if (!lib)
        return make_function_name(symbol_address, ftrace->binary_name);
    symbols = has_elf_element(ftrace, lib->name);
    if (symbols == NULL)
        return make_function_name(symbol_address, lib->name);
    f_name = find_symbol(ftrace, symbols, lib->name, symbol_address);
    if (f_name)
        return f_name;
    return make_function_name(symbol_address, lib->name);
}