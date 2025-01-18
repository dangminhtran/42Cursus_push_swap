# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 20:49:35 by dangtran          #+#    #+#              #
#    Updated: 2025/01/18 19:25:54 by dangtran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

CC=cc

CFLAGS= -Wall -Wextra -Werror -I${HEADER_DIR} -g

SRCS_DIR = 	$(addprefix sources/, operations.c parsing.c logic.c push_swap.c main.c) $(LIBFT)

SRCS_OBJ = ${SRCS_DIR:.c=.o}

LIBFT = $(addprefix libft/, ft_atoi.c)

HEADER_DIR=./includes/

all: $(NAME)

$(NAME): $(SRCS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS_OBJ) $(LIBF) -o $(NAME)


clean :
	rm -f ${SRCS_OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all
