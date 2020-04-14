/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** end_elf
*/

#include "ftrace.h"

void end_elf(ftrace_t *ftrace, int fd)
{
    elf_end(ftrace->list_symbole[0]->elf->elf);
    free(ftrace->list_symbole[0]->elf->sym_shdr);
    free(ftrace->list_symbole[0]->elf->dyn_shdr);
    free(ftrace->list_symbole[0]->elf->plt_shdr);
    close(fd);
}
