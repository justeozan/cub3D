# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sei <sei@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 11:56:01 by ozasahin          #+#    #+#              #
#    Updated: 2024/07/24 22:51:29 by sei              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL: $(NAME)

NAME	=	cub3D

SRC		=		\
				src/main.c\
				src/parsing/parsing.c\
				src/error.c

OBJ		=	$(patsubst src/%.c, obj/%.o, $(SRC))

# Controls
CC			=	cc
CFLAGS		=	-Werror -Wall -Wextra -g3
LDFLAGS		=	-Llibft -lft -Lminilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
INCLUDES	=	-Iincludes -Ilibft
RM			=	rm -rf

# Colors
COLOR_RESET			=	\033[0m
COLOR_RED			=	\033[0;31m
COLOR_GREEN			=	\033[0;32m
COLOR_PURPLE		=	\033[0;95m
COLOR_BLUE			=	\033[0;34m

# Colored Messages
MESSAGE_CLEAR		=	\033[0K\r\c
MESSAGE_OK			=	[\033[32mOK\033[0m]
MESSAGE_COMPILE		=	$(COLOR_BLUE)Compiling :$(COLOR_RESET)
MESSAGE_DONE		=	$(COLOR_GREEN)Compilation completed.$(COLOR_RESET)
MESSAGE_DONE2		=	$(MESSAGE_OK) cub3D compiled.
MESSAGE_CLEAN		=	$(COLOR_PURPLE)Cleaning up...$(COLOR_RESET)
MESSAGE_CLEAN_DONE	=	$(COLOR_PURPLE)Cleanup completed.$(COLOR_RESET)

all:		force $(NAME)

m:			clear $(NAME)

$(NAME):	$(OBJ) libft/libft.a
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LDFLAGS) -o $(NAME)
	@echo "$(MESSAGE_DONE2)"

obj/%.o:	src/%.c includes/cub3D.h Makefile libft/libft.h libft/libft.a
	@echo "[...] libft... $(MESSAGE_COMPILE) $*.c\r\c"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -c $< -o $@
	@echo "$(MESSAGE_CLEAR)"

force:
		@make -C libft/ -s
		@make -C minilibx-linux/ -s

clean:
	@echo "$(MESSAGE_CLEAN)\c"
	@$(RM) obj
	@make clean -C libft -s
	@make clean -C minilibx-linux -s
	@echo "$(MESSAGE_CLEAN_DONE)"

fclean:		clean
	@$(RM) $(NAME)
	@make fclean -C libft -s
	@make clean -C minilibx-linux -s

re:		fclean all

clear:
	clear

ARG := $(shell norminette src libft | grep Error: | wc -l)

norm:
	@if norminette src libft | grep -v OK; then \
		echo "$(COLOR_RED)$(ARG) norm violations found$(COLOR_RESET)"; \
	else \
		echo "$(COLOR_GREEN)All OK!"; \
	fi

.PHONY: all clean fclean re