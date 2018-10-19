# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/19 13:25:39 by zwang             #+#    #+#              #
#    Updated: 2018/10/19 15:20:54 by zwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_md5
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/ft_md5.c
LIBS = srcs/libft/libft.a
INCS = -I incs/ -I srcs/libft/incs/

all: $(NAME)

$(NAME):
	@$(CC) -o $(NAME) $(CFLAGS) $(SRCS) $(LIBS) $(INCS)

fclean:
	@rm -rf $(NAME)

re: fclean all
