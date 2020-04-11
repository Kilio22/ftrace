/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** parse_maps
*/

#include "parser.h"
#include "ftrace.h"

process_library_t *create_data(char *name, char *start, char *end)
{
    process_library_t *new = malloc(sizeof(process_library_t));

    new->name = strdup(name);
    new->start_adr = strdup(start);
    new->end_adr = strdup(end);
    return new;
}

process_library_t *get_data(char *line)
{
    char *name;
    char *start;
    char *end;

    start = strsep(&line, " -");
    end = strsep(&line, " -");
    if (strstr(line, "/") != NULL) {
        name = strstr(line, "/");
        name[strlen(name) - 1] = '\0';
        return create_data(name, start, end);
    }
    return NULL;
}

process_library_t **parse_maps(int pid)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    char path[64];
    int i = 0;
    process_library_t **array = malloc(sizeof(process_library_t *));
    process_library_t *new;

    sprintf(path, "/proc/%d/maps", pid);
    if ((fp = fopen(path, "r")) == NULL)
        exit(EXIT_FAILURE);
    while (getline(&line, &len, fp) != -1) {
        if ((new = get_data(line)) != NULL) {
            array = realloc(array, sizeof(process_library_t *) * (i + 2));
            array[i] = new;
            array[i + 1] = NULL;
            i++;
        }
    } fclose(fp);
    free(line);
    return array;
}