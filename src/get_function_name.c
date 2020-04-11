/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** get_function_name
*/

#include "ftrace.h"

static char *make_function_name(unsigned long addr, char *lib_name)
{
    char fct_name[50] = {'\0'};

    sprintf(fct_name, "func_%#lx@%s\n", addr, lib_name);
    return strdup(fct_name);
}

char *get_function_name(struct elf_file_s *elf, unsigned long addr)
{
    GElf_Sym sym;
    size_t symbol_nb;

    if (elf->sym_shdr == NULL || elf->sym_data == NULL)
        return make_function_name(addr, "toto");
    symbol_nb = elf->sym_shdr->sh_size / elf->sym_shdr->sh_entsize;
    for (size_t i = 0; i < symbol_nb; ++i) {
        gelf_getsym(elf->sym_data, i, &sym);
        if (sym.st_value == addr && ELF64_ST_BIND(sym.st_info) != STB_LOCAL)
            return elf_strptr(elf->elf, elf->sym_shdr->sh_link, sym.st_name);
    }
    return make_function_name(addr, "toto");
}
