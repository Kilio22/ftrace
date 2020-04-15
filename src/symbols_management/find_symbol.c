/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** find_symbols
*/

#include "ftrace.h"

static char *find_dynamic_symbol(struct symbols_s *symbols,
unsigned long offset)
{
    GElf_Rela rela;
    GElf_Sym sym;
    size_t symbol_nb = 0;

    if (CANNOT_GET_DYN_SYMBOL)
        return NULL;
    symbol_nb = symbols->elf->plt_shdr->sh_size /
symbols->elf->plt_shdr->sh_entsize;
    for (size_t i = 0; i < symbol_nb; i++) {
        if (gelf_getrela(symbols->elf->plt_data, i, &rela) == NULL)
            return NULL;
        if (rela.r_offset != offset)
            continue;
        if (!GETSYM(symbols->elf->dyn_data, GELF_R_SYM(rela.r_info), &sym))
            return NULL;
        else
            return GET_SYM_NAME(symbols->elf->elf,
symbols->elf->dyn_shdr->sh_link, sym.st_name);
    }
    return NULL;
}

static char *find_local_symbol(struct symbols_s *symbols, unsigned long addr)
{
    GElf_Sym sym;
    size_t symbol_nb = 0;

    if (CANNOT_GET_LOCAL_SYMBOL)
        return NULL;
    symbol_nb = symbols->elf->sym_shdr->sh_size /
symbols->elf->sym_shdr->sh_entsize;
    for (size_t i = 0; i < symbol_nb; ++i) {
        gelf_getsym(symbols->elf->sym_data, i, &sym);
        if (IS_LOCAL_SYMBOL)
            return GET_SYM_NAME(symbols->elf->elf,
    symbols->elf->sym_shdr->sh_link, sym.st_name);
    }
    return NULL;
}

static long calculate_dynamic_offset(ftrace_t *ftrace,
unsigned long call_addr)
{
    long jmpoffset = 0;
    unsigned long offset = 0;
    long value = ptrace(PTRACE_PEEKTEXT, ftrace->pid, call_addr + 2);

    if (value == -1)
        return -1;
    jmpoffset = value & 0xFFFFFFFF;
    offset = call_addr + 6 + jmpoffset;
    return offset;
}

char *find_symbol(ftrace_t *ftrace, struct symbols_s *symbols,
char *lib_name, unsigned long symbol_address)
{
    char *f_name = NULL;
    long dynamic_offset = 0;
    unsigned long starting_addr =
find_library_by_name(ftrace, lib_name)->start_adr;

    f_name = find_local_symbol(symbols, symbol_address);
    if (f_name)
        return f_name;
    dynamic_offset = calculate_dynamic_offset(ftrace, symbol_address);
    if (dynamic_offset == -1)
        return NULL;
    f_name = find_dynamic_symbol(symbols, dynamic_offset);
    if (f_name)
        return f_name;
    f_name = find_local_symbol(symbols, symbol_address - starting_addr);
    if (f_name)
        return f_name;
    return NULL;
}
