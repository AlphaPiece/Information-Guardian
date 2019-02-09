# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/19 13:25:39 by zwang             #+#    #+#              #
#    Updated: 2019/02/09 12:59:05 by Zexi Wang        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/ft_ssl.c \
	   srcs/md5/md5_base.c srcs/md5/md5_mode.c \
	   srcs/sha256/sha256_base.c srcs/sha256/sha256_mode.c
LIBS = libs/libft/libft.a
INCS = -I incs/ -I libs/libft/incs/

all: $(NAME)

$(NAME):
#	@$(CC) -o $(NAME) $(CFLAGS) $(SRCS) $(LIBS) $(INCS)
	@$(CC) -o $(NAME) $(SRCS) $(LIBS) $(INCS)

fclean:
	@rm -rf $(NAME)

re: fclean all
