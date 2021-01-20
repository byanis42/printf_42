# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 19:28:48 by yanboudr          #+#    #+#              #
#    Updated: 2021/01/21 00:06:28 by yanboudr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = 	./srcs/ft_printf.c\
		./srcs/ft_parsing.c\
		./srcs/ft_precision.c\
		./srcs/ft_conv_1.c\
		./srcs/ft_conv_2.c\
		./srcs/ft_width.c\
		./srcs/utils.c
OBJS = $(SRCS:.c=.o)
LIB_OBJS = ./libft/*.o
INCLUDES = ./includes/ft_printf.h
LIB = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g3

all : $(NAME)

.c.o : $(SRCS)
	@(gcc -c $(CFLAGS) -I $(INCLUDES) $^ -o $(^:.c=.o))

$(NAME) : $(OBJS)
	@(make -C libft)
	@(ar rcs $(NAME) $(OBJS) $(LIB_OBJS))
	@(echo "ft_printf compiled")

ex : $(NAME)
	@(gcc $(CFLAGS) $(NAME) srcs/main.c -I $(INCLUDES))
	@(./a.out)

clean :
	@(rm -f $(OBJS))
	@(make clean -C libft)
	@(echo "ft_printf cleaned")

cleanlib :
	@(make fclean -C libft)

fclean : cleanlib clean
	@(rm -rf $(NAME))
	@(rm -f libft.a)
	@(rm -rf a.out.dSYM)
	@(rm -f a.out)
	@(echo "ft_printf full cleaned")

re : fclean all