/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** find_library
*/

#include "ftrace.h"
#include "parser.h"

// Find the corresponding library name in the /proc/id/maps
char *find_library(unsigned long addr, int pid)
{
    process_library_t **array = parse_maps(pid)

    if (array == NULL)
        return NULL;
    for (size_t i = 0; array[i] != NULL; i++) {
        if (array[i]->start_adrr >= addr && array[i]->end_adrr < addr) {
            free_maps(array);
            return array[i]->name;
        }
    }
    free_maps(array)
    return NULL;
}