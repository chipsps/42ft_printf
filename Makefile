# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchi <pchi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 21:41:38 by pchi              #+#    #+#              #
#    Updated: 2023/12/12 13:49:22 by pchi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
AR = ar -rcs
CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -rf

# --- FILES ---

SRC =	ft_printf.c ft_printf_utils.c
OBJS = 		$(SRC:.c=.o)

# --- COMPILATION ---

all: 		$(NAME)

$(NAME): 	$(OBJS)
		$(AR) $(NAME) ${OBJS}

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

# --- CLEANING ---

clean: 
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re