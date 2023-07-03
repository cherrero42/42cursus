# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 22:14:31 by cherrero          #+#    #+#              #
#    Updated: 2023/04/01 21:53:55 by cherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

#BONUS = checker

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

GNL_DIR = ./gnl
GNL = $(GNL_DIR)/gnl.a

SOURCE_DIR = ./src
MASTER_DIR = .

MINILIBX_DIR = ./mlx
MINILIBX = $(MINILIBX_DIR)/libmlx.a

MEMORYLEAKS_DIR = ./memory_leaks
MEMORYLEAKS = $(MEMORYLEAKS_DIR)/memory_leaks.a

MAPS_DIR = ./maps
MAPS = $(MAPS_DIR)/basictest.fdf
MAPS = $(MAPS_DIR)/pylone.fdf  // comprobar errores quitando un 0 en una fila
MAPS = $(MAPS_DIR)/empty.fdf
MAPS = $(MAPS_DIR)/10-70.fdf
MAPS = $(MAPS_DIR)/elem.fdf
MAPS = $(MAPS_DIR)/50-4.fdf
MAPS = $(MAPS_DIR)/t2.fdf
MAPS = $(MAPS_DIR)/42.fdf

CC = gcc

CFLAGS_DEBUGER = -g -fsanitize=address
#CFLAGS_DEBUGER = ""
CFLAGS = -Wall -Werror -Wextra -g

ARGS = $(MAPS)
 
AR = ar -src

RM = rm -f

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

SOURCES_FILES = fdf_1.c \
				fdf_2.c \
				fdf_3.c \
				fdf_4.c \
				fdf_5.c \
				fdf_6.c \
				fdf_7.c \
				fdf_9.c

#HEADER = libft.h

#OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) ${CFLAGS} -I$(MINILIBX_DIR) -c $< -o $@

SOURCES = $(addprefix $(SOURCE_DIR)/,$(SOURCES_FILES))
OBJECTS = $(addprefix $(SOURCE_DIR)/,$(SOURCES_FILES:.c=.o))


$(NAME): $(LIBFT) $(PRINTF) $(GNL) $(MEMORYLEAKS) $(OBJECTS) $(MINILIBX)
	$(CC) ${CFLAGS} ${CFLAGS_DEBUGER} ${OBJECTS} $(LIBFT) $(PRINTF) $(GNL) $(MEMORYLEAKS) -L$(MINILIBX_DIR) -l mlx -framework OpenGL -framework AppKit -o $(NAME) $(CFLAGS)
#	//illas 	$(CC) ${CFLAGS} ${CFLAGS_DEBUGER} ${OBJECTS} $(LIBFT) $(PRINTF) $(GNL) -o $(NAME)
	@echo "$(NAME): $(GREEN)$(NAME) created$(RESET)"
	
all: ${NAME}
	@echo "$(NAME): $(GREEN)$(NAME) created$(RESET)"

$(LIBFT):
	make -C $(LIBFT_DIR)
	@echo "$(NAME): $(GREEN)creating $(LIBFT)...$(RESET)"

$(PRINTF):
	make -C $(PRINTF_DIR)
	@echo "$(NAME): $(GREEN)creating $(PRINTF)...$(RESET)"

$(GNL):
	make -C $(GNL_DIR)
	@echo "$(NAME): $(GREEN)creating $(GNL)...$(RESET)"

$(MEMORYLEAKS):
	make -C $(MEMORYLEAKS_DIR)
	@echo "$(NAME): $(GREEN)creating $(MEMORYLEAKS)...$(RESET)"
	
re:	fclean all

clean:
			${RM} ${OBJECTS}
			make clean -C $(LIBFT_DIR)
			make clean -C $(PRINTF_DIR)
			make clean -C $(GNL_DIR)

fclean:		clean
			${RM} $(NAME)
#			@$(RM) -f $(LIBFT)/libft.a
			make -C $(LIBFT_DIR) fclean
			make -C $(PRINTF_DIR) fclean
			make -C $(GNL_DIR) fclean
			@echo "$(NAME): $(RED)$(NAME) cleaned$(RESET)"

test: $(NAME)
	clear
	$(MASTER_DIR)/$(NAME) $(ARGS)

lldb: $(NAME)
	clear
	lldb $(MASTER_DIR)/$(NAME) $(ARGS)
	
push:
	make fclean
	git status
	@if $(MAKE) -s confirm ; then \
			 git add . ; git status ; git commit -m "update from make" ; git push; \
	fi

.PHONY: push

# echo "Do you wish to commit this files?"
# select yn in "Yes" "No"; do
# case $yn in
#     Yes ) git add . ; git status ; git commit -m "update from make" ; git push;;
#     No ) exit;;
# esac
# 	done

# push2:
# 	make fclean
# 	git status
# 	@echo "Do you wish to commit this files?"
# 	select yn in "Yes" "No"; do
#     case $yn in
#          Yes ) git add . ; git status ; git commit -m "update from make" ; git push;;
#          No ) exit;;
#     esac
# 	done


confirm:
	@if [[ -z "$(CI)" ]]; then \
		REPLY="" ; \
		read -p "⚠ Are you sure? [y/n] > " -r ; \
		if [[ ! $$REPLY =~ ^[Yy]$$ ]]; then \
			printf $(_ERROR) "KO" "Stopping" ; \
			exit 1 ; \
		else \
			printf $(_TITLE) "OK" "Continuing" ; \
			exit 0; \
		fi \
	fi
.PHONY: confirm
_WARN := "\033[33m[%s]\033[0m %s\n"  # Yellow text for "printf"
_TITLE := "\033[32m[%s]\033[0m %s\n" # Green text for "printf"
_ERROR := "\033[31m[%s]\033[0m %s\n" # Red text for "printf"

# sure:
#     @echo -n "Are you sure? [Y/n] " && read ans && if [ $${ans:-'Y'} = 'n' ]; then \
#         printf $(_ERROR) "KO" "Stopping" ; \
#         exit 1 ; \
#     else \
#         printf $(_SUCCESS) "OK" "Continuing" ; \
#         exit 0; \
#     fi

# clean2:
#     @read -p "Are you sure? [y/N] " ans && ans=$${ans:-N} ; \
#     if [ $${ans} = y ] || [ $${ans} = Y ]; then \
#         printf $(_SUCCESS) "YES" ; \
#     else \
#         printf $(_DANGER) "NO" ; \
#     fi
#     @echo 'Next steps...'

#  check_clean:
#      @echo -n "Are you sure? [y/N] " && read ans && [ $${ans:-N} = y ]


# _SUCCESS := "\033[32m[%s]\033[0m %s\n" # Green text for "printf"
# _ERROR := "\033[31m[%s]\033[0m %s\n" # Red text for "printf"


.PHONY: all, clean, fclean, re, push, test
