# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 14:34:05 by thgermai          #+#    #+#              #
#    Updated: 2020/01/03 09:00:27 by thgermai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ./get_next_line.c\
	./ft_find_in.c\
	./ft_atoi.c\
   	./ft_memchr.c\
	./ft_strlen.c\
	./ft_bzero.c\
	./ft_memcmp.c\
	./ft_strncmp.c\
	./ft_isalnum.c\
	./ft_memcpy.c\
	./ft_strnstr.c\
	./ft_isalpha.c\
	./ft_memmove.c\
	./ft_strrchr.c\
	./ft_isascii.c\
	./ft_memset.c\
	./ft_tolower.c\
	./ft_isdigit.c\
	./ft_strchr.c\
	./ft_toupper.c\
	./ft_isprint.c\
	./ft_strlcat.c\
	./ft_memccpy.c\
	./ft_strlcpy.c\
	./ft_calloc.c\
	./ft_strdup.c\
	./ft_substr.c\
	./ft_strjoin.c\
	./ft_strjoin_f1.c\
	./ft_strjoin_f2.c\
	./ft_strjoin_f12.c\
	./ft_strtrim.c\
	./ft_putchar_fd.c\
	./ft_putendl_fd.c\
	./ft_putnbr_base.c\
	./ft_putnbr_fd.c\
	./ft_putstr_fd.c\
	./ft_split.c\
	./ft_itoa.c\
	./ft_itoa_unsigned.c\
	./ft_strmapi.c\
	./ft_memdel.c\
	./ft_lstnew.c\
	./ft_lstadd_front.c\
	./ft_lstsize.c\
	./ft_lstlast.c\
	./ft_lstadd_back.c\
	./ft_lstdelone.c\
	./ft_lstclear.c\
	./ft_lstiter.c\
	./ft_lstmap.c\
	./ft_exit.c\
	./ft_itoa_base.c\
	./ft_itoa_address.c\
	./ft_str_toupper.c\
	./ft_str_tolower.c
OBJS = $(SRCS:.c=.o)
INCLUDES = ./libft.h
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

.c.o : $(SRCS)
	@(gcc -c $(CFLAGS) -I $(INCLUDES) $^ -o $(^:.c=.o))

$(NAME) : $(OBJS)
	@(ar rcs $(NAME) $(OBJS))
	@(echo "libft compiled")

clean :
	@(rm -f $(OBJS) $(INCLUDES:.h=.h.gch))
	@(echo "libft cleaned")

fclean : clean
	@(rm -f $(NAME))
	@(echo "libft full cleaned")

re : fclean all
