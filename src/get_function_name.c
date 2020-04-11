/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** get_function_name
*/

#include "ftrace.h"

static char *make_function_name(void)
{
    return strdup("G PAS DE NOM LOL");
}

char *get_function_name(struct elf_file_s *elf, unsigned long addr)
{
    GElf_Sym sym;
    size_t symbol_nb;
    
    symbol_nb = shdr.sh_size / shdr.sh_entsize;
    for (size_t i = 0; i < symbol_nb; ++i) {
        gelf_getsym(elf->sym_data, i, &sym);
        if (sym.st_value == addr && ELF64_ST_BIND(sym.st_info) != STB_LOCAL)
            printf("%s\n", elf_strptr(elf, shdr.sh_link, sym.st_name));
    }
    elf_end(elf);
    return NULL;
}
