# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 22:14:31 by cherrero          #+#    #+#              #
#    Updated: 2023/02/09 20:56:32 by cherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Makefile proy printf Oct.22


NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AR = ar -src

RM = rm -f

SOURCES =   ft_printf.c ft_functions_1.c ft_functions_2.c

OBJECTS = $(SOURCES:.c=.o)

OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

${NAME}: ${OBJECTS}
	${AR} ${NAME} ${OBJECTS}

all: ${NAME}

re:	fclean all

clean:
			${RM} ${OBJECTS} ${OBJECTS_BONUS}

fclean:		clean
			${RM} $(NAME)

.PHONY: all, clean, fclean, re
