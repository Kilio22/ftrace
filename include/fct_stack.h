/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** fct_stack
*/

#ifndef FCT_STACK_H_
#define FCT_STACK_H_

#include <stddef.h>

struct fct_stack_s {
    const char **names;
    size_t size;
    size_t n;
    size_t count;
};

#define STACK_BLOCK_SIZE 100

int init_fct_stack(struct fct_stack_s * const stack);
long enter_function(struct fct_stack_s * const stack, const char *name,
    unsigned long address);
long leave_function(struct fct_stack_s * const stack);

#endif /* !FCT_STACK_H_ */
