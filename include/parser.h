/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** parser
*/

#ifndef PARSER_H_
#define PARSER_H_

typedef struct process_library_s {
    unsigned long start_adr;
    unsigned long end_adr;
    char *name;
} process_library_t;

void free_maps(process_library_t **array);
void display_maps(process_library_t **array);

process_library_t *create_data(char *name, char *start, char *end);
process_library_t *get_data(char *line);
process_library_t **parse_maps(int pid);


#endif /* !PARSER_H_ */
