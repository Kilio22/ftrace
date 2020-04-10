/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** fct_stack
*/

#include "fct_stack.h"
#include "codes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int init_fct_stack(struct fct_stack_s * const stack)
{
    stack->names = malloc(sizeof(char *) * STACK_BLOCK_SIZE);
    if (stack->names == NULL)
        return -1;
    stack->size = STACK_BLOCK_SIZE;
    stack->n = 0;
    stack->count = 0;
    return 0;
}

long enter_function(struct fct_stack_s * const stack, const char *name,
    unsigned long address)
{
    ++stack->count;
    printf("%lu. Entering function %s at %#lx\n", stack->count, name, address);
    if (stack->n == stack->size) {
        stack->size += STACK_BLOCK_SIZE;
        stack->names = realloc(stack->names, sizeof(char *) * stack->size);
        if (stack->names == NULL)
            return -1;
    }
    stack->names[++stack->n] = name;
    return FTRACE_OK;
}

long leave_function(struct fct_stack_s * const stack)
{
    ++stack->count;
    printf("%lu. Leaving function %s\n", stack->count, stack->names[stack->n]);
    free((void *)stack->names[stack->n]);
    --stack->n;
    return FTRACE_OK;
}
