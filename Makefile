# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/18 11:50:03 by mosborne          #+#    #+#              #
#    Updated: 2017/11/03 15:09:06 by mosborne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

HEADER = fillit.h

FLAGS = -Wall -Wextra -Werror

SRCS = ft_check.c main.c ft_maker.c ft_solve.c ft_split.c main.c

LIB = libft/libft.a

all: $(NAME)

$(LIB):
	@make -C libft

$(NAME): $(LIB)
	@gcc $(FLAGS) $(SRCS) $(LIB) -I $(HEADER) -o $(NAME)

clean:
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
