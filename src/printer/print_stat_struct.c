/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** print_stat_struct
*/

#include <sys/stat.h>
#include "strace.h"

static const my_flags_t stat_flags[] = {
    {S_IFMT, "S_IFMT"},
    {S_IFSOCK, "S_IFSOCK"},
    {S_IFLNK, "S_IFLNK"},
    {S_IFREG, "S_IFREG"},
    {S_IFBLK, "S_IFBLK"},
    {S_IFDIR, "S_IFDIR"},
    {S_IFCHR, "S_IFCHR"},
    {S_IFIFO, "S_IFIFO"},
    {S_ISUID, "S_ISUID"},
    {S_ISGID, "S_ISGID"},
    {S_ISVTX, "S_ISVTX"},
    {S_IRWXU, "S_IRWXU"},
    {S_IRUSR, "S_IRUSR"},
    {S_IWUSR, "S_IWUSR"},
    {S_IXUSR, "S_IXUSR"},
    {S_IRWXG, "S_IRWXG"},
    {S_IRGRP, "S_IRGRP"},
    {S_IWGRP, "S_IWGRP"},
    {S_IXGRP, "S_IXGRP"},
    {S_IRWXO, "S_IRWXO"},
    {S_IROTH, "S_IROTH"},
    {S_IWOTH, "S_IWOTH"},
    {S_IXOTH, "S_IXOTH"},
    {0, NULL}
};

static void print_stat_flags(struct stat *stats)
{
    int printed = 0;

    for (size_t i = 0; stat_flags[i].str != NULL; i++) {
        if (((stats->st_mode & stat_flags[i].value) == stat_flags[i].value)
&& printed > 0) {
            fprintf(stderr, "|%s", stat_flags[i].str);
            printed++;
        } else if (((stats->st_mode & stat_flags[i].value) ==
stat_flags[i].value) && printed == 0) {
            fprintf(stderr, "%s", stat_flags[i].str);
            printed++;
        }
    }
}

static int fill_ptr(strace_t *strace_args, void *ptr, size_t size,
unsigned long long int addr)
{
    long value = 0;

    for (size_t i = 0; i < size; i++) {
        value = ptrace(PTRACE_PEEKDATA, strace_args->pid, addr + i, 0);
        if (value == -1)
            return -1;
        memcpy((void *)((unsigned long)ptr + i), (void *)&value, 1);
    }
    return 0;
}

int print_stat_struct(strace_t *strace_args, unsigned long long int value)
{
    struct stat stats = {0};

    if (fill_ptr(strace_args, &stats, sizeof(struct stat), value) == -1)
        return -1;
    fprintf(stderr, "{st_mode=");
    print_stat_flags(&stats);
    fprintf(stderr, "|%u, st_size=%ld, ...}", stats.st_mode, stats.st_size);
    return 0;
}
