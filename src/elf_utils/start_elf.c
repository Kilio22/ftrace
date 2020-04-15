/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** elf_utils
*/

#include "ftrace.h"

int get_elf_libs(ftrace_t *ftrace)
{
    for (size_t i = 0; ftrace->library_list[i] != NULL; i++) {
        if (has_elf_element(ftrace, ftrace->library_list[i]->name) == NULL
&& get_elf_values(ftrace, ftrace->library_list[i]->name) == -1) {
            return -1;
        }
    }
    return 0;
}

int start_elf(ftrace_t *ftrace)
{
    if (elf_version(EV_CURRENT) == EV_NONE) {
        fprintf(stderr, "Cannot load libelf\n");
        return -1;
    }
    set_list_library(ftrace);
    if (get_elf_libs(ftrace) == -1)
        return -1;
    return 0;
}