/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** find_symbols
*/

#include "ftrace.h"

char *find_dynamic_symbol(struct symbols_s *symbols, unsigned long offset)
{
    GElf_Rela rela;
    GElf_Sym sym;
    size_t symbol_nb = 0;

    if (CANNOT_GET_DYN_FUNCTIONS)
        return NULL;
    symbol_nb = symbols->elf->plt_shdr->sh_size /
symbols->elf->plt_shdr->sh_entsize;
    for (size_t i = 0; i < symbol_nb; i++) {
        if (gelf_getrela(symbols->elf->plt_data, i, &rela) == NULL)
            return NULL;
        if (rela.r_offset != offset)
            continue;
        if (GETSYM(symbols->elf->dyn_data,
GELF_R_SYM(rela.r_info), &sym) == NULL)
            return NULL;
        else
            return GET_SYM_NAME(symbols->elf->elf,
symbols->elf->dyn_shdr->sh_link, sym.st_name);
    }
    return NULL;
}

char *find_local_symbol(struct symbols_s *symbols, unsigned long addr)
{
    GElf_Sym sym;
    size_t symbol_nb = 0;

    if (symbols->elf->sym_shdr == NULL || symbols->elf->sym_data == NULL) {
        return NULL;
    }
    symbol_nb = symbols->elf->sym_shdr->sh_size /
symbols->elf->sym_shdr->sh_entsize;
    for (size_t i = 0; i < symbol_nb; ++i) {
        gelf_getsym(symbols->elf->sym_data, i, &sym);
        if (sym.st_value == addr && strlen(elf_strptr(symbols->elf->elf,
symbols->elf->sym_shdr->sh_link, sym.st_name)) != 0)
            return GET_SYM_NAME(symbols->elf->elf,
symbols->elf->sym_shdr->sh_link, sym.st_name);
    }
    return NULL;
}