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
    GElf_Shdr *shdr = malloc(sizeof(GElf_Shdr));

    if (shdr == NULL)
        return -1;
    while ((scn = elf_nextscn(ftrace->elf.elf, scn)) != NULL) {
        gelf_getshdr(scn, shdr);
        if (shdr->sh_type == SHT_SYMTAB)
            break;
    }
    if (scn == NULL)
        return 0;
    ftrace->elf.sym_shdr = shdr;
    ftrace->elf.sym_data = elf_getdata(scn, NULL);
    return 0;
}

static int get_rela_plt_hdr(ftrace_t *ftrace)
{
    Elf_Scn *scn = NULL;
    GElf_Shdr *shdr = malloc(sizeof(GElf_Shdr));
    size_t ndxptr = 0;

    if (shdr == NULL || elf_getshdrstrndx(ftrace->elf.elf, &ndxptr) == -1)
        return -1;
    while ((scn = elf_nextscn(ftrace->elf.elf, scn)) != NULL) {
        gelf_getshdr(scn, shdr);
        if (shdr->sh_type == SHT_RELA && strcmp(".rela.plt",
            elf_strptr(ftrace->elf.elf, ndxptr, shdr->sh_name)) == 0)
            break;
    }
    if (scn == NULL)
        return 0;
    ftrace->elf.plt_shdr = shdr;
    ftrace->elf.plt_data = elf_getdata(scn, NULL);
    return 0;
}

static int get_dyn_sym_hdr(ftrace_t *ftrace)
{
    Elf_Scn *scn = NULL;
    GElf_Shdr *shdr = malloc(sizeof(GElf_Shdr));

    if (shdr == NULL)
        return -1;
    while ((scn = elf_nextscn(ftrace->elf.elf, scn)) != NULL) {
        gelf_getshdr(scn, shdr);
        if (shdr->sh_type == SHT_DYNSYM) {
            break;
        }
    }
    if (scn == NULL)
        return 0;
    ftrace->elf.dyn_shdr = shdr;
    ftrace->elf.dyn_data = elf_getdata(scn, NULL);
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
    ftrace->elf.elf = elf_begin(fd, ELF_C_READ, NULL);
    if (ftrace->elf.elf == NULL) {
        close(fd);
        return -1;
    }
    if (get_symbol_table_hdr(ftrace) == -1 || get_rela_plt_hdr(ftrace) == -1
        || get_dyn_sym_hdr(ftrace) == -1) {
        close(fd);
        return -1;
    }
    return fd;
}