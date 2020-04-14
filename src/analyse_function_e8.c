/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** get_function_name
*/

#include "ftrace.h"

static long calculate_dynamic_offset(ftrace_t *ftrace,
unsigned long call_addr)
{
    long jmpoffset = 0;
    unsigned long offset = 0;
    long value = ptrace(PTRACE_PEEKTEXT, ftrace->pid, call_addr + 2);

    if (value == -1)
        return -1;
    jmpoffset = value & 0xFFFFFFFF;
    offset = call_addr + 6 + jmpoffset;
    return offset;
}

static long get_offset(ftrace_t *ftrace, long rip_value)
{
    long ret_val = ptrace(PTRACE_PEEKTEXT, ftrace->pid, rip_value + 1);
    int offset = 0;

    if (ret_val == -1)
        return -1;
    offset = ret_val & 0xFFFFFFFF;
    return offset;
}

static process_library_t *get_lib(ftrace_t *ftrace,
unsigned long symbol_address)
{
    process_library_t *lib = NULL;

    lib = find_library_by_address(ftrace, symbol_address);
    if (!lib) {
        set_list_library(ftrace);
        get_elf_libs(ftrace);
    }
    lib = find_library_by_address(ftrace, symbol_address);
    return lib;
}

static char *find_symbol(ftrace_t *ftrace, struct symbols_s *symbols,
char *lib_name, unsigned long symbol_address)
{
    char *f_name = NULL;
    long dynamic_offset = 0;
    unsigned long starting_addr =
find_library_by_name(ftrace, lib_name)->start_adr;

    f_name = find_local_symbol(symbols, symbol_address);
    if (f_name)
        return f_name;
    dynamic_offset = calculate_dynamic_offset(ftrace, symbol_address);
    if (dynamic_offset == -1)
        return NULL;
    f_name = find_dynamic_symbol(symbols, dynamic_offset);
    if (f_name)
        return f_name;
    f_name = find_local_symbol(symbols, symbol_address - starting_addr);
    if (f_name)
        return f_name;
    return NULL;
}

long analyse_function_e8(ftrace_t *ftrace, unsigned long long rip)
{
    long offset = get_offset(ftrace, rip);
    unsigned long symbol_address = 0;
    char *f_name;
    process_library_t *lib = NULL;
    struct symbols_s *symbols = NULL;

    if (offset == -1)
        return -1;
    symbol_address = rip + 5 + offset;
    lib = get_lib(ftrace, symbol_address);
    if (!lib)
        return enter_function(ftrace,
make_function_name(symbol_address, ftrace->binary_name), symbol_address);
    symbols = has_elf_element(ftrace, lib->name);
    f_name = find_symbol(ftrace, symbols, lib->name, symbol_address);
    if (f_name)
        return enter_function(ftrace, f_name, symbol_address);
    return enter_function(ftrace,
make_function_name(symbol_address, lib->name), symbol_address);
}
