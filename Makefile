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

NAME =

HEADER =

FLAGS = -Wall -Wextra -Werror

SRCS =

OBJS =

all: $(NAME)

$(NAME): 
	gcc $(FLAGS) -c $(SRCS) -I $(HEADER)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	
clean:
	rm -rf $(OBJS)

fclean: clean 
	rm -rf $(NAME)

re: fclean all