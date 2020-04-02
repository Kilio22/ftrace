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

Test(error, error_06)
{
    char *opt[] = {"./strace", "-h", NULL};

    cr_assert_eq(parse_arg(2, opt), 0);
}