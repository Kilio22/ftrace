/*
** EPITECH PROJECT, 2019
** Repo_starter
** File description:
** main
*/

#include "ftrace.h"

int start_elf(ftrace_t *ftrace, char *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return -1;
    if (elf_version(EV_CURRENT) == EV_NONE) {
        fprintf(stderr, "Cannot load libelf.\n");
        close(fd);
        return -1;
    }
    ftrace->elf_file = elf_begin(fd, ELF_C_READ, NULL);
    if (ftrace->elf_file == NULL) {
        close(fd);
        return -1;
    }
    return fd;
}

int main(int ac, char **av)
{
    ftrace_t ftrace = {0};
    int fd = 0;

    if (ac < 2)
        return FTRACE_EXIT_FAILURE;
    if (start_prog_to_trace(&ftrace, av) == -1)
        return FTRACE_EXIT_FAILURE;
    fd = start_elf(&ftrace, av[1]);
    if (fd == -1)
        return FTRACE_EXIT_FAILURE;
    close(fd);
    return trace_prog(&ftrace);
}
