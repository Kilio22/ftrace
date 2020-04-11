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

char *find_dynamic_lib_function(ftrace_t *ftrace, unsigned long call_addr)
{
    long value = ptrace(PTRACE_PEEKTEXT, ftrace->pid, call_addr + 2);
    long offset = 0;
    unsigned long long addr = 0;
    process_library_t *library = find_library(ftrace, call_addr);

    (void)addr; // Error not used
    if (value == -1 || library == NULL)
        return NULL;
    offset = value & 0xFFFFFFFF;
    addr = call_addr + 6 + offset;
    // GElf_Rela *rela = gelf_getrela();

    // gelf_getrela(Elf_Data *ed, int ndx, GElf_Rela *dst)
    return NULL;
}

char *get_function_name(ftrace_t *ftrace, unsigned long addr)
{
    GElf_Sym sym;
    size_t symbol_nb;

    if (ftrace->elf.sym_shdr == NULL || ftrace->elf.sym_data == NULL)
        return make_function_name(addr, "toto");
    symbol_nb = ftrace->elf.sym_shdr->sh_size /
    ftrace->elf.sym_shdr->sh_entsize;
    for (size_t i = 0; i < symbol_nb; ++i) {
        gelf_getsym(ftrace->elf.sym_data, i, &sym);
        if (sym.st_value == addr && ELF64_ST_BIND(sym.st_info) != STB_LOCAL)
            return strdup(elf_strptr(ftrace->elf.elf,
                ftrace->elf.sym_shdr->sh_link, sym.st_name));
    }
    if (ftrace->library_list == NULL)
        set_list_library(ftrace);
    find_dynamic_lib_function(ftrace, addr);
    return make_function_name(addr, "toto");
}