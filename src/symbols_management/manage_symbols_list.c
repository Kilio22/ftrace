/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** list_symbol
*/

#include "ftrace.h"

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
    for (size_t i = 0; ftrace->symbols_list[i] != NULL; i++) {
        if (strcmp(ftrace->symbols_list[i]->name, name) == 0)
            return ftrace->symbols_list[i];
    }
    return NULL;
}

void add_elf_element(ftrace_t *ftrace, struct elf_file_s *elf,
int fd, char *name)
{
    struct symbols_s *element = malloc(sizeof(struct symbols_s));
    size_t i = get_symbols_list_len(ftrace->symbols_list);
    element->fd = fd;
    element->elf = elf;

    ftrace->symbols_list = realloc(ftrace->symbols_list,
sizeof(struct symbols_s *) * (i + 2));
    while (ftrace->symbols_list[i] != NULL)
        i++;
    element->elf = elf;
    element->fd = fd;
    element->name = name;
    ftrace->symbols_list[i] = element;
    ftrace->symbols_list[i + 1] = NULL;
}

void init_symbols_list(ftrace_t *ftrace)
{
    ftrace->symbols_list = malloc(sizeof(struct symbols_s *));
    ftrace->symbols_list[0] = NULL;
}