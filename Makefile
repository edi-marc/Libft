# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 18:02:01 by edi-marc          #+#    #+#              #
#    Updated: 2021/01/17 12:47:31 by edi-marc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
	  ft_memmove.c ft_memchr.c ft_strlen.c \
	  ft_strrchr.c ft_strncmp.c ft_atoi.c

OBJS = $(SRCS:.c=.o)

INCLUDE = libft.h

LIB = ar rc

PLIB = ranlib

CC = gcc
	
RM = /bin/rm -f

CFLAGS = -Wall -Wextra -Werror	

all: $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(INCLUDE)
	@$(LIB) $(NAME) $(OBJS)
	@$(PLIB) $(NAME)
	@make clean	

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
