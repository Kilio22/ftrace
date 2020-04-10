/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** print_mmap_flags
*/

#include <sys/mman.h>
#include "strace.h"

static const my_flags_t mmap_flags[] = {
    {MAP_SHARED, "MAP_SHARED"},
    {MAP_PRIVATE, "MAP_PRIVATE"},
    {MAP_FIXED, "MAP_FIXED"},
    {MAP_SHARED_VALIDATE, "MAP_SHARED_VALIDATE"},
    {MAP_32BIT, "MAP_32BIT"},
    {MAP_ANONYMOUS, "MAP_ANONYMOUS"},
    {MAP_DENYWRITE, "MAP_DENYWRITE"},
    {MAP_EXECUTABLE, "MAP_EXECUTABLE"},
    {MAP_FILE, "MAP_FILE"},
    {MAP_FIXED_NOREPLACE, "MAP_FIXED_NOREPLACE"},
    {MAP_GROWSDOWN, "MAP_GROWSDOWN"},
    {MAP_HUGETLB, "MAP_HUGETLB"},
    {MAP_LOCKED, "MAP_LOCKED"},
    {MAP_NONBLOCK, "MAP_NONBLOCK"},
    {MAP_NORESERVE, "MAP_NORESERVE"},
    {MAP_POPULATE, "MAP_POPULATE"},
    {MAP_STACK, "MAP_STACK"},
    {MAP_SYNC, "MAP_SYNC"},
    {0, NULL}
};

static const my_flags_t mmap_prot[] = {
    {PROT_EXEC, "PROT_EXEC"},
    {PROT_READ, "PROT_READ"},
    {PROT_WRITE, "PROT_WRITE"},
    {PROT_NONE, "PROT_NONE"},
    {0, NULL}
};

int print_mmap_prot(strace_t *strace_args __attribute__((unused)),
unsigned long long int value)
{
    int printed = 0;

    for (size_t i = 0; mmap_prot[i].str != NULL; i++) {
        if ((value & mmap_prot[i].value) == mmap_prot[i].value
&& printed > 0 && mmap_prot[i].value != PROT_NONE) {
            fprintf(stderr, "|%s", mmap_prot[i].str);
            printed++;
        } else if ((value & mmap_prot[i].value) == mmap_prot[i].value
&& printed == 0) {
            fprintf(stderr, "%s", mmap_prot[i].str);
            printed++;
        }
    }
    return 0;
}

int print_mmap_flags(strace_t *strace_args __attribute__((unused)),
unsigned long long int value)
{
    int printed = 0;

    for (size_t i = 0; mmap_flags[i].str != NULL; i++) {
        if ((value & mmap_flags[i].value) == mmap_flags[i].value
&& printed > 0) {
            fprintf(stderr, "|%s", mmap_flags[i].str);
            printed++;
        } else if ((value & mmap_flags[i].value) == mmap_flags[i].value
&& printed == 0) {
            fprintf(stderr, "%s", mmap_flags[i].str);
            printed++;
        }
    }
    return 0;
}