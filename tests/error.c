/*
** EPITECH PROJECT, 2020
** strace tests errors
** File description:
** error
*/

#include <criterion/criterion.h>
#include <string.h>
#include <stdio.h>
#include "strace.h"

Test(error, error_01)
{
    char *opt[] = {"./strace", NULL};

    cr_assert_eq(parse_arg(1, opt), 84);
}

Test(error, error_02)
{
    char *opt[] = {"./strace", "-p", NULL};

    cr_assert_eq(parse_arg(2, opt), 84);
}

Test(error, error_03)
{
    char *opt[] = {"./strace", "123", "AZE", NULL};

    cr_assert_eq(parse_arg(3, opt), 84);
}

Test(error, error_04)
{
    char *opt[] = {"./strace", "-p", "123", NULL};

    cr_assert_eq(parse_arg(3, opt), 84);
}

Test(error, error_05)
{
    char *opt[] = {"./strace", "-p", "123", "-s", NULL};

    cr_assert_eq(parse_arg(4, opt), 84);
}