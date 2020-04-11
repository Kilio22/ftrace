/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** get_function_name
*/

#include "ftrace.h"

static char *make_function_name()
{
    return strdup("G PAS DE NOM LOL");
}

char *get_function_name(struct elf_file_s *elf, unsigned long addr)
{
    // uint64_t base_offset = elf_getbase(elf->elf);
    // GElf_Sym sym;
    // char *strings;
    // size_t count;

    // if (elf->sym_shdr == NULL)
    //     return make_function_name();
    // count = elf->sym_shdr->sh_size / elf->sym_shdr->sh_entsize;
    // strings = base_offset + (shd[shd[i].sh_link]).sh_offset;
    // for (size_t i = 0; i < count; ++i) {
    //     gelf_getsym(elf->sym_data, i, &sym);
    //     if (sym.st_value == addr) {
    //         printf("Found symbol\n");
    //     }
    // }
    return NULL;
}
