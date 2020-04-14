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
        fprintf(stderr, "%ld: %d - %s\n", i, ftrace->list_symbole[i]->fd,
ftrace->list_symbole[i]->name);
        if (ftrace->list_symbole[i]->elf->plt_shdr->sh_type == SHT_RELA)
            printf("Ok\n");
        i++;
    }
}

static size_t get_symbols_list_len(struct symbols_s **list)
{
    size_t i = 0;

    if (list == NULL)
        return 0;
    for (; list[i]; i++);
    return i;
}

struct symbols_s *has_elf_element(ftrace_t *ftrace, char *name)
{
    for (size_t i = 0; ftrace->list_symbole[i] != NULL; i++) {
        if (strcmp(ftrace->list_symbole[i]->name, name) == 0)
            return ftrace->list_symbole[i];
    }
    return NULL;
}

void add_elf_element(ftrace_t *ftrace, struct elf_file_s *elf,
int fd, char *name)
{
    struct symbols_s *element = malloc(sizeof(struct symbols_s));
    size_t i = get_symbols_list_len(ftrace->list_symbole);
    element->fd = fd;
    element->elf = elf;

    ftrace->list_symbole = realloc(ftrace->list_symbole,
sizeof(struct symbols_s *) * (i + 2));
    while (ftrace->list_symbole[i] != NULL)
        i++;
    element->elf = elf;
    element->fd = fd;
    element->name = name;
    ftrace->list_symbole[i] = element;
    ftrace->list_symbole[i + 1] = NULL;
}

void init_list_symbols(ftrace_t *ftrace)
{
    ftrace->list_symbole = malloc(sizeof(struct symbols_s *));
    ftrace->list_symbole[0] = NULL;
}