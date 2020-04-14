/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** list_symbol
*/

#include "ftrace.h"

void display_list(ftrace_t *ftrace)
{
    size_t i = 0;

    while (ftrace->list_symbole[i] != NULL) {
        printf("%ld: %d - ", i, ftrace->list_symbole[i]->fd);
        if (ftrace->list_symbole[i]->elf->plt_shdr->sh_type == SHT_RELA)
            printf("Ok\n");
        i++;
    }
    
}

void add_elf_element(ftrace_t *ftrace, struct elf_file_s *elf, int fd)
{
    struct list_symbole_s *element = malloc(sizeof(struct list_symbole_s));
    size_t i = 0;
    element->fd = fd;
    element->elf = elf;

    ftrace->list_symbole = realloc(ftrace->list_symbole, sizeof(struct list_symbole_s *) * (i + 2));
    while (ftrace->list_symbole[i] != NULL)
        i++;
    ftrace->list_symbole[i] = element;
    ftrace->list_symbole[i + 1] = NULL;
}

void init_list_symbols(ftrace_t *ftrace)
{
    ftrace->list_symbole = malloc(sizeof(struct list_symbole_s *));
    ftrace->list_symbole[0] = NULL;
}