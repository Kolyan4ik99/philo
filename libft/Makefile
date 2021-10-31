# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cclock <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 12:07:38 by cclock            #+#    #+#              #
#    Updated: 2020/11/18 15:03:46 by cclock           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)

OBJSBON = $(BONUS:.c=.o)

ARRC = ar rc

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(OBJSBON) 
		$(ARRC) $(NAME) $(OBJS) $(OBJSBON)
		$(ARRC) $(NAME) libft.h
		ranlib $(NAME)

bonus: all

.c.o:
		gcc $(FLAGS) -I. -c $< -o $(<:.c=.o)

clean:
		rm -rf $(OBJS) $(OBJSBON)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
