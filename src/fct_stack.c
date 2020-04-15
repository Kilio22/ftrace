/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** fct_stack
*/

#include "ftrace.h"
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
    return 0;
}

void destroy_fct_stack(struct fct_stack_s *stack)
{
    for (size_t i = 0; i < stack->n; ++i)
        free((void *)stack->names[i]);
    free(stack->names);
}

long enter_function(ftrace_t *ftrace, const char *name, unsigned long address)
{
    struct fct_stack_s *stack = &ftrace->stack;

    ++ftrace->counter;
    fprintf(stderr, ENTERING_FUNCTION, ftrace->counter, name, address);
    if (stack->n == stack->size) {
        stack->size += STACK_BLOCK_SIZE;
        stack->names = realloc(stack->names, sizeof(char *) * stack->size);
        if (stack->names == NULL)
            return -1;
    }
    stack->names[stack->n] = name;
    ++stack->n;
    return FTRACE_OK;
}

long leave_function(ftrace_t *ftrace)
{
    struct fct_stack_s *stack = &ftrace->stack;

    ++ftrace->counter;
    if (stack->n == 0)
        return FTRACE_OK;
    --stack->n;
    fprintf(stderr, LEAVING_FUNCTION, ftrace->counter, stack->names[stack->n]);
    free((void *)stack->names[stack->n]);
    return FTRACE_OK;
}
