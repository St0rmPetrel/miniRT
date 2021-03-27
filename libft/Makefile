# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: serma <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 18:01:28 by serma             #+#    #+#              #
#    Updated: 2020/11/06 18:14:59 by serma            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all clean fclean re bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS := $(wildcard ft_*.c)
SRCS_B := $(wildcard ft_lst*.c)
SRCS := $(filter-out $(SRCS_B),$(SRCS))
OBJS := $(SRCS:.c=.o)
OBJS_B := $(SRCS_B:.c=.o)
NAME := libft.a

all: $(NAME)

$(NAME): ${OBJS}
	@ar rcs ${NAME} ${OBJS} 

bonus: $(NAME) ${OBJS_B}
	@ar rcs ${NAME} ${OBJS_B} 

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	@rm -f ${OBJS} ${OBJS_B}

fclean: clean
	@rm -f $(NAME)

re: fclean all
