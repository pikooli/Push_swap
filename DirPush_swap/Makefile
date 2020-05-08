SRC = copy_entry.c\
principal.c\
algo.c\
free.c\
instruction.c\
malloc.c\
print.c\
utility.c\
test_algo.c\
check.c\
main.c\
one_argument.c\
split.c\
list_utilily.c\
ft_entry_mode.c

ALGO = ft_algo_1/ft_algo_1.c\
ft_algo_2/ft_algo_2.c\
ft_algo_3/ft_algo_3.c\
ft_algo_4/ft_algo_4.c\
ft_algo_5/ft_algo_5.c\
ft_algo_one_hundred/ft_algo_one_hundred.c\
ft_algo_one_hundred/ft_one_hundred_util.c






SRCS = $(addprefix srcs/, $(SRC))

FLAG = -Wall -Wextra -Werror

CFLAGS = $(FLAG) -I include

OBJS = $(SRCS:.c=.o) $(ALGO:.c=.o)

%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $<

all : $(OBJS)
	@gcc $(FLAG) $(OBJS) -o push_swap

clean: 
	@rm -rf $(OBJS)
fclean: clean
	@rm -rf push_swap
