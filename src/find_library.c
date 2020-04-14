/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** find_library
*/

#include "ftrace.h"
#include "parser.h"

void set_list_library(ftrace_t *ftrace)
{
    process_library_t **array = NULL;

    if ((array = parse_maps(ftrace->pid)) != NULL)
        ftrace->library_list = array;
}

process_library_t *find_library_by_address(ftrace_t *ftrace, unsigned long addr)
{
    if (ftrace->library_list == NULL)
        return NULL;
    for (size_t i = 0; ftrace->library_list[i] != NULL; i++) {
        if (addr >= ftrace->library_list[i]->start_adr &&
        addr <= ftrace->library_list[i]->end_adr) {
            return ftrace->library_list[i];
        }
    }
    return NULL;
}

process_library_t *find_library_by_name(ftrace_t *ftrace, char *name)
{
    if (ftrace->library_list == NULL)
        return NULL;
    for (size_t i = 0; ftrace->library_list[i] != NULL; i++) {
        if (strcmp(ftrace->library_list[i]->name, name) == 0) {
            return ftrace->library_list[i];
        }
    }
    return NULL;
}