# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 14:04:46 by cherrero          #+#    #+#              #
#    Updated: 2022/12/22 14:05:59 by cherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AR = ar -src

RM = rm -f

SOURCES =   get_next_line.c \
			get_next_line_utils.c \

SOURCES_BONUS =  get_next_line_bonus.c \
			get_next_line_utils_bonus.c \

#HEADER = libft.h

OBJECTS = $(SOURCES:.c=.o)

OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

${NAME}: ${OBJECTS}
	${AR} ${NAME} ${OBJECTS}

all: ${NAME}

bonus: ${OBJECTS} ${OBJECTS_BONUS}
	${AR} ${NAME} ${OBJECTS} ${OBJECTS_BONUS}

re:	fclean all

clean:
			${RM} ${OBJECTS} ${OBJECTS_BONUS}

fclean:		clean
			${RM} $(NAME)

.PHONY: all, clean, fclean, re, bonus
