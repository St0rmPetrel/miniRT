# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: serma <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 20:00:38 by serma             #+#    #+#              #
#    Updated: 2021/02/03 19:14:08 by serma            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := $(wildcard source/*.c vectormath/*.c)
OBJS := $(SRCS:.c=.o)
LIBFT := libft/libft.a
MLX_LIB := libmlx.dylib

HEADER = includes

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror
LFLAGS = -L . -lmlx -lpthread

NAME = miniRT

all: $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

.c.o:
	${CC} ${CFLAGS} -I $(HEADER) -c $< -o ${<:.c=.o}

$(MLX_LIB):
	make -C mlx
	mv mlx/$(MLX_LIB) $(MLX_LIB)

$(LIBFT):
	make -C libft bonus

clean:
	rm -f ${OBJS}
	make -C mlx clean
	make -C libft fclean

fclean: clean
	rm -f $(MLX_LIB)
	rm -f $(NAME)

re:	fclean all

.PHONY:	all fclean clean re
