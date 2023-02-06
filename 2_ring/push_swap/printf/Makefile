# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 22:14:31 by cherrero          #+#    #+#              #
#    Updated: 2022/10/19 18:45:04 by cherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Makefile proy printf Oct.22


#//make -C ./libft

#//borrar los .o del make antiguo


NAME = libftprintf.a

#LIBFT = libft

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AR = ar -src

RM = rm -f

SOURCES =   ft_printf.c ft_functions_1.c ft_functions_2.c

#SOURCES_BONUS = 

#HEADER = libft.h

OBJECTS = $(SOURCES:.c=.o)

OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

${NAME}: ${OBJECTS}
#    ${CC} -c ${CFLAGS} ${SOURCES}
#	@make -C $(LIBFT)
#	@cp libft/libft.a .
#	@mv libft.a $(NAME)
	${AR} ${NAME} ${OBJECTS}

all: ${NAME}

#bonus: ${OBJECTS} ${OBJECTS_BONUS}
#	${AR} ${NAME} ${OBJECTS} ${OBJECTS_BONUS}

re:	fclean all

clean:
			${RM} ${OBJECTS} ${OBJECTS_BONUS}
#			@make clean -C $(LIBFT)

fclean:		clean
			${RM} $(NAME)
#			@$(RM) -f $(LIBFT)/libft.a

.PHONY: all, clean, fclean, re, bonus
