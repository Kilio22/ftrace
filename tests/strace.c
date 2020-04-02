/*
** EPITECH PROJECT, 2020
** strace tests errors
** File description:
** strace
*/

#include <criterion/criterion.h>
#include <string.h>
#include <stdio.h>
#include "strace.h"

Test(strace, ls)
{
    char *opt[] = {"./strace", "ls", NULL};

    cr_assert_eq(parse_arg(2, opt), 0);
}

Test(strace, lsos)
{
    char *opt[] = {"./strace", "-s", "ls", NULL};

    cr_assert_eq(parse_arg(3, opt), 0);
}