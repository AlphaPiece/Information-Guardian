# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/19 13:25:39 by zwang             #+#    #+#              #
#    Updated: 2018/11/05 15:21:02 by zwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/ft_ssl.c srcs/md5/md5_base.c srcs/md5/md5_mode.c
LIBS = libs/libft.a
INCS = -I incs/ -I libs/libft_incs/

all: $(NAME)

$(NAME):
	@$(CC) -o $(NAME) $(CFLAGS) $(SRCS) $(LIBS) $(INCS)

fclean:
	@rm -rf $(NAME)

re: fclean all
