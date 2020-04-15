/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** get_elf_values
*/

#include "ftrace.h"

static int get_symbol_table_hdr(struct elf_file_s *elf)
{
    Elf_Scn *scn = NULL;
    GElf_Shdr *shdr = malloc(sizeof(GElf_Shdr));

    if (shdr == NULL)
        return -1;
    while ((scn = elf_nextscn(elf->elf, scn)) != NULL) {
        gelf_getshdr(scn, shdr);
        if (shdr->sh_type == SHT_SYMTAB)
            break;
    }
    if (scn == NULL)
        return 0;
    elf->sym_shdr = shdr;
    elf->sym_data = elf_getdata(scn, NULL);
    return 0;
}

static int get_rela_plt_hdr(struct elf_file_s *elf)
{
    Elf_Scn *scn = NULL;
    GElf_Shdr *shdr = malloc(sizeof(GElf_Shdr));
    size_t ndxptr = 0;

    if (shdr == NULL || elf_getshdrstrndx(elf->elf, &ndxptr) == -1)
        return -1;
    while ((scn = elf_nextscn(elf->elf, scn)) != NULL) {
        gelf_getshdr(scn, shdr);
        if (shdr->sh_type == SHT_RELA && strcmp(".rela.plt",
            elf_strptr(elf->elf, ndxptr, shdr->sh_name)) == 0)
            break;
    }
    if (scn == NULL)
        return 0;
    elf->plt_shdr = shdr;
    elf->plt_data = elf_getdata(scn, NULL);
    return 0;
}

static int get_dyn_sym_hdr(struct elf_file_s *elf)
{
    Elf_Scn *scn = NULL;
    GElf_Shdr *shdr = malloc(sizeof(GElf_Shdr));

    if (shdr == NULL)
        return -1;
    while ((scn = elf_nextscn(elf->elf, scn)) != NULL) {
        gelf_getshdr(scn, shdr);
        if (shdr->sh_type == SHT_DYNSYM) {
            break;
        }
    }
    if (scn == NULL)
        return 0;
    elf->dyn_shdr = shdr;
    elf->dyn_data = elf_getdata(scn, NULL);
    return 0;
}

int get_elf_values(ftrace_t *ftrace, char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct elf_file_s *elf = malloc(sizeof(struct elf_file_s));

    if (fd == -1 || elf == NULL)
        return -1;
    memset(elf, 0, sizeof(struct elf_file_s));
    elf->elf = elf_begin(fd, ELF_C_READ, NULL);
    if (elf->elf == NULL) {
        close(fd);
        return -1;
    }
    if (get_symbol_table_hdr(elf) == -1 || get_rela_plt_hdr(elf) == -1
        || get_dyn_sym_hdr(elf) == -1) {
        close(fd);
        return -1;
    }
    add_elf_element(ftrace, elf, fd, filepath);
    return 0;
}