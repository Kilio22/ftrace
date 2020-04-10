/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** elf_utils
*/

#include "ftrace.h"

static int get_symbol_table_hdr(ftrace_t *ftrace)
{
    Elf_Scn *scn = NULL;
    GElf_Shdr *shhdr = malloc(sizeof(GElf_Shdr));

    if (shhdr == NULL) {
        return -1;
    }
    while ((scn = elf_nextscn(ftrace->elf_file, scn)) != NULL) {
        gelf_getshdr(scn, shhdr);
        if (shhdr->sh_type == SHT_SYMTAB) {
            break;
        }
    }
    if (scn == NULL) {
        return 0;
    }
    ftrace->symbol_header = shhdr;
    return 0;
}

int start_elf(ftrace_t *ftrace, char *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return -1;
    if (elf_version(EV_CURRENT) == EV_NONE) {
        fprintf(stderr, "Cannot load libelf.\n");
        close(fd);
        return -1;
    }
    ftrace->elf_file = elf_begin(fd, ELF_C_READ, NULL);
    if (ftrace->elf_file == NULL) {
        close(fd);
        return -1;
    }
    if (get_symbol_table_hdr(ftrace) == -1) {
        close(fd);
        return -1;
    }
    return fd;
}