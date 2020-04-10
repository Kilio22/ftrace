/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** end_elf
*/

#include "ftrace.h"

void end_elf(ftrace_t *ftrace, int fd)
{
    elf_end(ftrace->elf_file);
    free(ftrace->symbol_header);
    close(fd);
}
