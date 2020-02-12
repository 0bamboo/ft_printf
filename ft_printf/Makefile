# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/19 02:40:50 by abdait-m          #+#    #+#              #
#    Updated: 2020/01/24 15:40:23 by abdait-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror
 
SRC =		ft_printf.c ./srcs/ft_char.c ./srcs/ft_hex.c ./srcs/ft_integer.c \
			./srcs/ft_addr.c ./srcs/ft_string.c ./srcs/ft_u_integer.c \
			./srcs/ft_putchar_plus.c ./srcs/ft_convert_to_hex.c ./srcs/ft_atoi.c\
		
OBJ =		ft_printf.o ft_char.o ft_hex.o ft_integer.o ft_addr.o \
			ft_string.o ft_u_integer.o ft_putchar_plus.o ft_atoi.o ft_convert_to_hex.o \

all : $(NAME)

$(NAME):$(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o:./srcs/%.c
	gcc -c $(FLAGS) $<

%.o:%.c
	gcc -c $(FLAGS) $<
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
