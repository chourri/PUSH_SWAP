# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chourri <chourri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 17:07:34 by chourri           #+#    #+#              #
#    Updated: 2024/04/21 15:44:28 by chourri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = libft_tools1.c \
 libft_tools2.c \
 libft_tools3.c \
 libft_tools4.c \
 push_swap.c \
 Handle_errors.c \
 push.c \
 swap.c \
 rotate.c \
 rev_rotate.c \
 stack_tools.c \
 initialize_stack_a.c \
 simple_sorting.c \
 sort_algorithm.c \
 main.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
