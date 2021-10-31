
SRC_FILES = main.c args_handling.c thread_create.c

SRC_DIR = srcs/

HEAD_DIR = header

SRCS = ${addprefix ${SRC_DIR}, ${SRC_FILES}}
OBJS = ${SRCS:.c=.o}

ARRC = ranlib

NAME = philo

LIBFT = libft

HEADER = $(HEAD_DIR)/philo.h

FLAGS = -Wall -Wextra -Werror

all: compile_lib $(NAME) $(HEADER)

$(NAME): $(OBJS) $(HEADER)
		gcc $(FLAGS) -lpthread $(OBJS) $(LIBFT)/$(LIBFT).a -o $(NAME)

compile_lib:
	make -C $(LIBFT)

.c.o:
		gcc $(FLAGS) -c -I $(HEADER) $< -o $(<:.c=.o)

clean:
		rm -rf $(OBJS)
		make clean -C $(LIBFT)

fclean: clean
		rm -rf $(NAME)
		make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re