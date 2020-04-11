/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** utils_parser
*/

#include "parser.h"
#include "ftrace.h"

void free_maps(process_library_t **array)
{
    for (size_t i = 0; array[i] != NULL; i++) {
        free(array[i]->start_adr);
        free(array[i]->end_adr);
        free(array[i]->name);
        free(array[i]);
    }
    free(array);
}

void display_maps(process_library_t **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        printf("%s %s %s\n", array[i]->start_adr,
        array[i]->end_adr, array[i]->name);
    }
}
