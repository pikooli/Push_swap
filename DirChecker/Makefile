NAME = checker

CC = gcc

HEADER_LIST = main.h

OBJECTS_DIRECTORY = objects/

INCLUDES_DIRECTORY = ./includes/

SOURCE_DIRECTORY = ./SRCS/

SRC = check.c\
instruction.c\
malloc.c\
print.c\
copy_entry.c\
main.c\
one_argument.c\
split.c\
free.c\
principal_checker.c\
utility.c\
ft_move_a.c\
ft_move_b.c\
ft_print_utility.c\
ft_message.c

SRCS = $(addprefix $(SOURCE_DIRECTORY), $(SRC))

INCLUDES = -I $(INCLUDES_DIRECTORY)

OBJS = $(patsubst %.c, %.o, $(SRC))

OBJECTS = $(addprefix objects/, $(OBJS))

FLAGS = -Wall -Wextra -Werror


all : $(NAME)

$(NAME) : $(OBJECTS_DIRECTORY) $(OBJECTS)
	@echo "$(GREEN)]$(RESET)"
	@$(CC) $(FLAG) $(OBJECTS) -o $(NAME)
	@echo "$(NAME) :$(GREEN)Compilation done.$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME) : $(GREEN)Object directory create.$(RESET)"
	@echo "$(GREEN)[$(RESET)\c"

$(OBJECTS_DIRECTORY)%.o : $(SOURCE_DIRECTORY)%.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean: 
	@rm -rf $(OBJECTS) $(OBJECTS_DIRECTORY)
	@echo "$(NAME) : $(RED)Clean done.$(RESET)"

fclean: clean
	@rm -rf Checker
	@echo "$(NAME) : $(RED)Fclean done.$(RESET)"

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
