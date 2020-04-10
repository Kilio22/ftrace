##
## EPITECH PROJECT, 2018
## Fairefichier
## File description:
## This is a fairefichier, made by HeyShafty
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
BLACK_C	=	"\e[30m"
RED_C	=	"\e[31m"
GREEN_C	=	"\e[32m"
YELLO_C	=	"\e[33m"
BLUE_C	=	"\e[34m"
MAGEN_C	=	"\e[35m"
CYAN_C	=	"\e[36m"
WHITE_C	=	"\e[97m"
DEFAULT_C	=	"\e[39m"
LIGHT_GREY	=	"\e[37m"
DARK_GREY	=	"\e[90m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	"\e[96m"
LINE_RETURN	=	$(ECHO) ""

NAME	=	ftrace
COLOR_THEME	=	$(BLUE_C)
TESTS_COLOR_THEME	=	$(RED_C)

ROOT_PATH	=	./
SRC_NAME	=	src
INCL_NAME	=	include
TESTS_NAME	=	tests
INCL_PATH	=	$(ROOT_PATH)$(INCL_NAME)
TESTS_PATH	=	$(ROOT_PATH)$(TESTS_NAME)
SRC_PATH	=	$(ROOT_PATH)$(SRC_NAME)
MODIF_ARGS_PATH = modif_args_functions
PRINTER_PATH = printer

SRC	=	const_syscall_values.c	\
		end_of_prog.c	\
		get_syscall_infos.c	\
		start_prog_to_trace.c	\
		trace_prog.c	\
		$(PRINTER_PATH)/print_hexa.c	\

SRCS	=	$(SRC:%=$(SRC_PATH)/%) $(SRC_PATH)/main.c
OBJ	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall \
			-Wextra \
			-Werror \
			-I $(INCL_PATH)

DEBUG_FLAGS	=	-g3 -gdwarf-4
MAKE_RULE	=	all
CLEAN_RULE	=	clean

all:	message $(NAME)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"  ____                      _ _       _   _"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" / ___|___  _ __ ___  _ __ (_) | __ _| |_(_) ___  _ __"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |   / _ \| '_ \` _ \| '_ \| | |/ _\` | __| |/ _ \| '_ \\\\"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |__| (_) | | | | | | |_) | | | (_| | |_| | (_) | | | |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" \____\___/|_| |_| |_| .__/|_|_|\__,_|\__|_|\___/|_| |_|"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"                     |_|"$(DEFAULT)
	@$(LINE_RETURN)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME)\n"$(DEFAULT) || \
		$(ECHO) $(RED_C)$(BOLD_T)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME)\n"$(DEFAULT)

clean:
	@$(RM) $(OBJ)
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"$(NAME)'s object files"$(DEFAULT)
	@$(RM) vgcore.*
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Valgrind files"$(DEFAULT)

fclean: CLEAN_RULE=fclean
fclean:	clean
	@$(RM) $(NAME)
	@$(ECHO) $(RED_C)$(DIM_T)"[fclean] "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Binary $(NAME)"$(DEFAULT)

re:		fclean all

debug: CFLAGS += $(DEBUG_FLAGS)
debug: COLOR_THEME = $(CYAN_C)
debug: MAKE_RULE = debug
debug: re
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"⚠ DEBUG MODE ACTIVATED ⚠\n"$(DEFAULT)

tests_run:
	@make -C $(TESTS_PATH) -s \
		SRC="$(SRC)" \
		COLOR_THEME="$(TESTS_COLOR_THEME)"
	@$(ECHO) $(TESTS_COLOR_THEME)""
	@gcovr --exclude "tests/" --sort-uncovered --branches
	@$(ECHO) $(BOLD_T)""
	@gcovr --exclude "tests/" --sort-uncovered --print-summary
	@$(ECHO) $(DEFAULT)

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $< && \
		$(ECHO) $(DIM_T) "cc $(CFLAGS) -c "$<$(COLOR_THEME)" -o "$@ $(DEFAULT) || \
		$(ECHO) "\n"$(MAGEN_C) $(UNDLN_T)$(BOLD_T)"cc $(CFLAGS) -c "$<" -o "$@$(DEFAULT)"\n"

.PHONY: all message clean fclean re debug tests_run
