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

    while (ftrace->list_symbole[i] != NULL) {
        elf_end(ftrace->list_symbole[i]->elf->elf);
        free(ftrace->list_symbole[i]->elf->sym_shdr);
        free(ftrace->list_symbole[i]->elf->dyn_shdr);
        free(ftrace->list_symbole[i]->elf->plt_shdr);
        free(ftrace->list_symbole[i]->elf);
        close(ftrace->list_symbole[i]->fd);
        free(ftrace->list_symbole[i]);
        i++;
    }
    free(ftrace->list_symbole);
}
