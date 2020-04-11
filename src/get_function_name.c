/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** get_function_name
*/

#include "ftrace.h"
#include "parser.h"

static char *make_function_name(unsigned long addr, char *lib_name)
{
    char fct_name[50] = {'\0'};

    sprintf(fct_name, "func_%#lx@%s", addr, lib_name);
    return strdup(fct_name);
}

int get_usefull_values(ftrace_t *ftrace, unsigned long call_addr,
long *jmpoffset, unsigned long *offset)
{
    long value = ptrace(PTRACE_PEEKTEXT, ftrace->pid, call_addr + 2);

    if (value == -1)
        return -1;
    *jmpoffset = value & 0xFFFFFFFF;
    *offset = call_addr + 6 + *jmpoffset;
    return 0;
}

char *find_dynamic_lib_function(ftrace_t *ftrace, unsigned long call_addr)
{
    long jmpoffset = 0;
    unsigned long offset = 0;
    process_library_t *library = find_library(ftrace, call_addr);
    GElf_Rela rela;
    GElf_Sym sym;
    size_t symbol_nb = 0;

    if (CANNOT_GET_DYN_FUNCTIONS || get_usefull_values(ftrace, call_addr,
&jmpoffset, &offset) == -1 || library == NULL)
        return NULL;
    symbol_nb = ftrace->elf.plt_shdr->sh_size / ftrace->elf.plt_shdr->sh_entsize;
    for (size_t i = 0; i < symbol_nb; i++) {
        if (gelf_getrela(ftrace->elf.plt_data, i, &rela) == NULL)
            return NULL;
        if (rela.r_offset == offset) {
            if (gelf_getsym(ftrace->elf.dyn_data, GELF_R_SYM(rela.r_info), &sym) == NULL)
                return NULL;
            else
                return strdup(elf_strptr(ftrace->elf.elf, ftrace->elf.dyn_shdr->sh_link, sym.st_name));
        }
    }
    return NULL;
}

char *find_local_function(ftrace_t *ftrace, unsigned long addr)
{
    GElf_Sym sym;
    size_t symbol_nb = 0;

    if (ftrace->elf.sym_shdr == NULL || ftrace->elf.sym_data == NULL)
        return NULL;
    symbol_nb = ftrace->elf.sym_shdr->sh_size /
ftrace->elf.sym_shdr->sh_entsize;
    for (size_t i = 0; i < symbol_nb; ++i) {
        gelf_getsym(ftrace->elf.sym_data, i, &sym);
        if (sym.st_value == addr && ELF64_ST_BIND(sym.st_info) != STB_LOCAL)
            return strdup(elf_strptr(ftrace->elf.elf,
ftrace->elf.sym_shdr->sh_link, sym.st_name));
    }
    return NULL;
}

char *get_function_name(ftrace_t *ftrace, unsigned long addr)
{
    char *symbol_name = NULL;

    symbol_name = find_local_function(ftrace, addr);
    if (symbol_name != NULL)
        return symbol_name;
    if (ftrace->library_list == NULL)
        set_list_library(ftrace);
    if (ftrace->library_list == NULL)
        return make_function_name(addr, "toto");
    symbol_name = find_dynamic_lib_function(ftrace, addr);
    if (symbol_name != NULL)
        return symbol_name;
    return make_function_name(addr, "toto");
}