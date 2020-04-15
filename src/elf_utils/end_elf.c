/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** end_elf
*/

#include "ftrace.h"

void end_elf(ftrace_t *ftrace)
{
    size_t i = 0;

    while (ftrace->symbols_list[i] != NULL) {
        elf_end(ftrace->symbols_list[i]->elf->elf);
        free(ftrace->symbols_list[i]->elf->sym_shdr);
        free(ftrace->symbols_list[i]->elf->dyn_shdr);
        free(ftrace->symbols_list[i]->elf->plt_shdr);
        free(ftrace->symbols_list[i]->elf);
        close(ftrace->symbols_list[i]->fd);
        free(ftrace->symbols_list[i]);
        i++;
    }
    free(ftrace->symbols_list);
}
