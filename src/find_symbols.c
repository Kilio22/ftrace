/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** find_symbols
*/

#include "ftrace.h"

char *find_dynamic_symbol(ftrace_t *ftrace, unsigned long offset)
{
    GElf_Rela rela;
    GElf_Sym sym;
    size_t symbol_nb = 0;

    if (CANNOT_GET_DYN_FUNCTIONS)
        return NULL;
    symbol_nb = ftrace->elf.plt_shdr->sh_size /
ftrace->elf.plt_shdr->sh_entsize;
    for (size_t i = 0; i < symbol_nb; i++) {
        if (gelf_getrela(ftrace->elf.plt_data, i, &rela) == NULL)
            return NULL;
        if (rela.r_offset != offset)
            continue;
        if (GETSYM(ftrace->elf.dyn_data, GELF_R_SYM(rela.r_info), &sym) == NULL)
            return NULL;
        else
            return GET_SYM_NAME(ftrace->elf.elf,
ftrace->elf.dyn_shdr->sh_link, sym.st_name);
    }
    return NULL;
}

char *find_local_symbol(ftrace_t *ftrace, unsigned long addr)
{
    GElf_Sym sym;
    size_t symbol_nb = 0;

    if (ftrace->elf.sym_shdr == NULL || ftrace->elf.sym_data == NULL)
        return NULL;
    symbol_nb = ftrace->elf.sym_shdr->sh_size /
ftrace->elf.sym_shdr->sh_entsize;
    for (size_t i = 0; i < symbol_nb; ++i) {
        gelf_getsym(ftrace->elf.sym_data, i, &sym);
        if (sym.st_value == addr)
            return GET_SYM_NAME(ftrace->elf.elf,
ftrace->elf.sym_shdr->sh_link, sym.st_name);
    }
    return NULL;
}