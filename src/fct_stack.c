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

static const char ENTERING_FUNCTION[] = "%lu. Entering function %s at %#lx\n";
static const char LEAVING_FUNCTION[] = "%lu. Leaving function %s\n";

int init_fct_stack(struct fct_stack_s *const stack)
{
    stack->names = malloc(sizeof(char *) * STACK_BLOCK_SIZE);
    if (stack->names == NULL)
        return -1;
    stack->size = STACK_BLOCK_SIZE;
    stack->n = 0;
    stack->count = 0;
    return 0;
}

long enter_function(struct fct_stack_s *const stack, const char *name,
    unsigned long address, size_t *counter)
{
    ++stack->count;
    printf(ENTERING_FUNCTION, *counter, name, address);
    (*counter)++;
    if (stack->n == stack->size) {
        stack->size += STACK_BLOCK_SIZE;
        stack->names = realloc(stack->names, sizeof(char *) * stack->size);
        if (stack->names == NULL)
            return -1;
    }
    stack->names[++stack->n] = name;
    return FTRACE_OK;
}

long leave_function(struct fct_stack_s *const stack, size_t *counter)
{
    ++stack->count;
    printf(LEAVING_FUNCTION, *counter, stack->names[stack->n]);
    (*counter)++;
    free((void *)stack->names[stack->n]);
    --stack->n;
    return FTRACE_OK;
}
