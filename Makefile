##
## EPITECH PROJECT, 2020
## PSU_strace_2019
## File description:
## Makefile
##

INC_DIR		= include/

NAME	= ftrace

SRC	=	src/strace.c

SRC_TESTS	=

SRCS	=	$(SRC)	src/main.c

SRC_TEST	=	$(SRC)
	
OBJ	=	$(SRCS:.c=.o)

OBJ_SRC_TEST =	$(SRC_TEST:.c=.o)
	
OBJ_TESTS =	$(SRC_TESTS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I $(INC_DIR)

LDFLAGS	=	-lcriterion

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_SRC_TEST)
	@$(RM) $(OBJ_TESTS)
	@$(RM) *.gcno
	@$(RM) *.gcda
	@$(RM) $(SRC:.c=.gcda)
	@$(RM) $(SRC:.c=.gcno)
	@$(RM) $(SRC_TESTS:.c=.gcda)
	@$(RM) $(SRC_TESTS:.c=.gcno)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) unit_tests
	@$(RM) vgcore*

re:	fclean all

tests_run: CFLAGS += --coverage
tests_run : fclean $(OBJ_SRC_TEST) $(OBJ_TESTS)
		$(CC) -o unit_tests $(OBJ_SRC_TEST) $(OBJ_TESTS) $(CFLAGS) $(LDFLAGS)
		./unit_tests
		gcovr --exclude tests/

.PHONY: all clean fclean re tests_run