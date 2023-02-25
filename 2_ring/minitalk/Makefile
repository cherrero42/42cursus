# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 22:14:31 by cherrero          #+#    #+#              #
#    Updated: 2023/02/16 21:23:34 by cherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
SERVER_BONUS = server_bonus
CLIENT = client
CLIENT_BONUS = client_bonus
BONUS = bonus

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

SOURCE_DIR = ./src

SERVER_FILES = $(SOURCE_DIR)/mini_server.c
SERVER_BONUS_FILES = $(SOURCE_DIR)/mini_server_bonus.c
CLIENT_FILES = $(SOURCE_DIR)/mini_client.c
CLIENT_BONUS_FILES = $(SOURCE_DIR)/mini_client_bonus.c

SERVER_OBJECTS = $(SERVER_FILES:.c=.o)
SERVER_BONUS_OBJECTS = $(SERVER_BONUS_FILES:.c=.o)
CLIENT_OBJECTS = $(CLIENT_FILES:.c=.o)
CLIENT_BONUS_OBJECTS = $(CLIENT_BONUS_FILES:.c=.o)

#LIBFT = libft

CC = gcc

#CFLAGS_DEBUGER = -g -fsanitize=address
#CFLAGS_DEBUGER = ""
CFLAGS = -Wall -Werror -Wextra
# -O3

AR = ar -src

RM = rm -f

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m


$(NAME): $(LIBFT) $(PRINTF) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "$(NAME): $(GREEN)$(NAME) created$(RESET)"

$(SERVER): $(LIBFT) $(PRINTF) $(SERVER_OBJECTS)
	$(CC) ${CFLAGS} ${CFLAGS_DEBUGER} $(SERVER_OBJECTS) $(LIBFT) $(PRINTF) -o $(SERVER) 
	@echo "$(NAME): $(GREEN)creating $(SERVER)...$(RESET)"

$(SERVER_BONUS): $(LIBFT) $(PRINTF) $(SERVER_BONUS_OBJECTS)
	$(CC) ${CFLAGS} ${CFLAGS_DEBUGER} $(SERVER_BONUS_OBJECTS) $(LIBFT) $(PRINTF) -o $(SERVER_BONUS) 
	@echo "$(NAME): $(GREEN)creating $(SERVER_BONUS)...$(RESET)"
	
$(CLIENT): $(LIBFT) $(PRINTF) $(CLIENT_OBJECTS)
	$(CC) ${CFLAGS} ${CFLAGS_DEBUGER} $(CLIENT_OBJECTS) $(LIBFT) $(PRINTF) -o $(CLIENT) 
	@echo "$(NAME): $(GREEN)creating $(CLIENT)...$(RESET)"

$(CLIENT_BONUS): $(LIBFT) $(PRINTF) $(CLIENT_BONUS_OBJECTS)
	$(CC) ${CFLAGS} ${CFLAGS_DEBUGER} $(CLIENT_BONUS_OBJECTS) $(LIBFT) $(PRINTF) -o $(CLIENT_BONUS) 
	@echo "$(NAME): $(GREEN)creating $(CLIENT_BONUS)...$(RESET)"

all: ${NAME}

bonus: $(LIBFT) $(PRINTF) $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "$(NAME): $(GREEN)$(bonus) created$(RESET)"

$(LIBFT):
	make -C $(LIBFT_DIR)
	@echo "$(NAME): $(GREEN)creating $(LIBFT)...$(RESET)"

$(PRINTF):
	make -C $(PRINTF_DIR)
	@echo "$(NAME): $(GREEN)creating $(PRINTF)...$(RESET)"

re:	fclean all

clean:
			${RM} ${SERVER_OBJECTS} ${SERVER_BONUS_OBJECTS} $(CLIENT_OBJECTS) $(CLIENT_BONUS_OBJECTS)
			make clean -C $(LIBFT_DIR)
			make clean -C $(PRINTF_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	$(RM) $(SERVER)
	$(RM) $(SERVER_BONUS)
	$(RM) $(CLIENT)
	$(RM) $(CLIENT_BONUS)
	@echo "$(NAME): $(RED)$(NAME) cleaned$(RESET)"

.PHONY: all, clean, fclean, re, bonus, server, client, server_bonus,client_bonus
