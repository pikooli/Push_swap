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

SRCS = $(addprefix srcs/, $(SRC))
OBJS = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror

CFLAGS = $(FLAG) -I include

all : $(OBJS)
	gcc $(FLAG) $(OBJS) -o Checker

clean: 
	rm -rf $(OBJS)
fclean: clean
	rm -rf Checker