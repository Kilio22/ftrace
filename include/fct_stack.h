/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** fct_stack
*/

#ifndef FCT_STACK_H_
#define FCT_STACK_H_

#include <stddef.h>

typedef struct ftrace_s ftrace_t;

#define ENTERING_FUNCTION "%lu. Entering function %s at %#lx\n"
#define LEAVING_FUNCTION "%lu. Leaving function %s\n"

struct fct_stack_s {
    const char **names;
    size_t size;
    size_t n;
};

#define STACK_BLOCK_SIZE 100

int init_fct_stack(struct fct_stack_s *const stack);
void destroy_fct_stack(struct fct_stack_s *stack);
long enter_function(ftrace_t *ftrace, const char *name, unsigned long address);
long leave_function(ftrace_t *ftrace);

#endif /* !FCT_STACK_H_ */
