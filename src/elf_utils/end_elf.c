/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** end_elf
*/

#include "ftrace.h"

void end_elf(ftrace_t *ftrace, int fd)
{
    elf_end(ftrace->elf.elf);
    free(ftrace->elf.sym_shdr);
    close(fd);
}
