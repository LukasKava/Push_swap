# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 00:27:50 by lkavalia          #+#    #+#              #
#    Updated: 2022/06/06 16:51:41 by lkavalia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		check.c \
		create_stack.c \
		helper_f.c \
		operations.c \
		operations_second.c \
		operations_third.c \
		radix.c \
		small_sort.c \
		solve_up_to_three.c \


OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

