# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 18:02:01 by edi-marc          #+#    #+#              #
#    Updated: 2021/01/24 20:40:17 by edi-marc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
	   ft_memmove.c ft_memchr.c ft_strlen.c ft_strchr.c \
	   ft_strrchr.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	   ft_isascii.c ft_isprint.c ft_toupper.c ft_strncmp.c \
	   ft_tolower.c ft_strlcpy.c ft_strlcat.c ft_memcmp.c ft_atoi.c \
	   ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	   ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c

OBJS = $(SRCS:.c=.o)

INCLUDE = libft.h

LIB = ar rc

PLIB = ranlib

LIB2 = ar rcs

CC = gcc
	
RM = /bin/rm -f

CFLAGS = -Wall -Wextra -Werror	

all: $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(INCLUDE)
	@$(LIB2) $(NAME) $(OBJS)
	@make clean	

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
