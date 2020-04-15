/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** utils_parser
*/

#include "parser.h"
#include "ftrace.h"

void free_maps(process_library_t **array)
{
    for (size_t i = 0; array[i] != NULL; i++) {
        free(array[i]->name);
        free(array[i]);
    }
    free(array);
}

process_library_t *get_lib(ftrace_t *ftrace, unsigned long symbol_address)
{
    process_library_t *lib = NULL;

    lib = find_library_by_address(ftrace, symbol_address);
    if (!lib) {
        set_list_library(ftrace);
        if (get_elf_libs(ftrace) == -1)
            return NULL;
    }
    lib = find_library_by_address(ftrace, symbol_address);
    return lib;
}