/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** get_function_name
*/

#include "ftrace.h"
#include "parser.h"

char *make_function_name(unsigned long addr, char *lib_name)
{
    char fct_name[1024] = {'\0'};

    sprintf(fct_name, "func_%#lx@%s", addr, lib_name);
    return strdup(fct_name);
}