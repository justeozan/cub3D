.DEFAULT_GOAL: $(NAME)

NAME	=	cub3D

SRC		=		\
				src/close_program/close.c\
				\
				src/debug/debug.c\
				\
				src/game_loop/frame/print_frame.c\
				src/game_loop/player/init_player.c\
				src/game_loop/player/player_modifs.c\
				src/game_loop/player/player_utils.c\
				src/game_loop/ray_casting/dda_ray_config.c\
				src/game_loop/ray_casting/dda_wall_config.c\
				src/game_loop/game_loop.c\
				\
				src/init/init_mlx.c\
				src/init/init_sprites.c\
				src/init/init_struct.c\
				\
				src/key_handler/key_handler.c\
				\
				src/parsing/parse_colors.c\
				src/parsing/parse_file_utils.c\
				src/parsing/parse_file.c\
				src/parsing/parse_map_utils.c\
				src/parsing/parse_map.c\
				src/parsing/parse_sprites.c\
				src/parsing/parsing.c\
				\
				src/main.c

BAD_MAPS	=	\
				maps/bad/color_invalid_rgb.cub\
				maps/bad/color_missing_ceiling_rgb.cub\
				maps/bad/color_missing_floor_rgb.cub\
				maps/bad/color_missing.cub\
				maps/bad/color_none.cub\
				maps/bad/empty.cub\
				maps/bad/file_letter_end.cub\
				maps/bad/filetype_missing\
				maps/bad/filetype_wrong.buc\
				maps/bad/forbidden.cub\
				maps/bad/map_first.cub\
				maps/bad/map_middle.cub\
				maps/bad/map_missing.cub\
				maps/bad/map_only.cub\
				maps/bad/map_syntax.cub\
				maps/bad/map_too_small.cub\
				maps/bad/player_multiple.cub\
				maps/bad/player_none.cub\
				maps/bad/subject_map.cub\
				maps/bad/player_on_edge.cub\
				maps/bad/textures_dir.cub\
				maps/bad/textures_duplicates.cub\
				maps/bad/textures_invalid.cub\
				maps/bad/textures_missing.cub\
				maps/bad/textures_none.cub\
				maps/bad/textures_not_xpm.cub\
				maps/bad/wall_hole_east.cub\
				maps/bad/wall_hole_north.cub\
				maps/bad/wall_hole_south.cub\
				maps/bad/wall_hole_west.cub\
				maps/bad/wall_none.cub

GOOD_MAPS	=	\
				maps/good/cheese_maze.cub\
				maps/good/creepy.cub\
				maps/good/dungeon.cub\
				maps/good/library.cub\
				maps/good/map_multiple_wall.cub\
				maps/good/matrix.cub\
				maps/good/sad_face.cub\
				maps/good/square_map.cub\
				maps/good/subject_map.cub\
				maps/good/test_pos_bottom.cub\
				maps/good/test_pos_left.cub\
				maps/good/test_pos_right.cub\
				maps/good/test_pos_top.cub\
				maps/good/test_textures.cub\
				maps/good/test_whitespace.cub\
				maps/good/wall_hole_test.cub\
				maps/good/works.cub

SUBJECT_MAP	=	maps/good/map_multiple_wall.cub
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
COLOR_YELLOW		=	\033[0;33m
COLOR_MAGENTA		=	\033[0;35m
COLOR_CYAN			=	\033[0;36m

# Colored Messages
MESSAGE_CLEAR		=	\033[0K\r\c
MESSAGE_OK			=	[\033[32mOK\033[0m]
MESSAGE_COMPILE		=	$(COLOR_BLUE)Compiling :$(COLOR_RESET)
MESSAGE_DONE		=	$(MESSAGE_OK) cub3D compiled.
MESSAGE_DONE_MLX	=	$(MESSAGE_OK) minilibx compiled.
MESSAGE_CLEAN		=	$(COLOR_PURPLE)Cub3D cleanup completed.$(COLOR_RESET)
MESSAGE_CLEAN_MLX	=	$(COLOR_PURPLE)MLX cleanup completed.$(COLOR_RESET)

$(NAME):	$(OBJ) libft/libft.a
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LDFLAGS) -o $(NAME)
	@echo "$(MESSAGE_DONE)"

all:		force $(NAME)

m:			clear $(NAME)
	@./$(NAME) $(SUBJECT_MAP) || echo "$(COLOR_RED)Makefile: Error with $(SUBJECT_MAP)$(COLOR_RESET)"

vm:			clear $(NAME)
	@valgrind --leak-check=full --suppressions=mlx.supp --show-leak-kinds=all --track-origins=yes ./$(NAME) $(SUBJECT_MAP) || echo "$(COLOR_RED)Makefile: Error with $(SUBJECT_MAP)$(COLOR_RESET)"

test_bad_maps: clear $(NAME)
	@echo "$(COLOR_YELLOW)Testing bad maps...$(COLOR_RESET)"
	@failure_count=0; \
	for map in $(BAD_MAPS); do \
		echo "\nTesting $$map:"; \
		./$(NAME) $$map; \
		if [ $$? -eq 0 ]; then \
			echo "$(COLOR_RED)Error: $$map should have failed but didn't$(COLOR_RESET)"; \
			failure_count=$$((failure_count + 1)); \
		else \
			echo "$(COLOR_GREEN)Success: $$map failed as expected$(COLOR_RESET)"; \
		fi; \
	done; \
	echo "\n$(COLOR_YELLOW)Bad maps test completed.$(COLOR_RESET)"; \
	if [ $$failure_count -eq 0 ]; then \
		echo "$(COLOR_GREEN)All bad maps were correctly handled.$(COLOR_RESET)"; \
	else \
		echo "$(COLOR_RED)$$failure_count bad map(s) were not correctly handled.$(COLOR_RESET)"; \
		echo "$(COLOR_YELLOW)Maps that unexpectedly passed:$(COLOR_RESET)"; \
		for map in $(BAD_MAPS); do \
			./$(NAME) $$map > /dev/null 2>&1; \
			if [ $$? -eq 0 ]; then \
				echo "$(COLOR_RED)- $$map$(COLOR_RESET)"; \
			fi; \
		done; \
	fi

test_good_maps: clear $(NAME)
	@echo "$(COLOR_YELLOW)Testing good maps...$(COLOR_RESET)"
	@failure_count=0; \
	for map in $(GOOD_MAPS); do \
		echo "\nTesting $$map:"; \
		./$(NAME) $$map; \
		if [ $$? -eq 0 ]; then \
			echo "$(COLOR_GREEN)Success: $$map passed as expected$(COLOR_RESET)"; \
		else \
			echo "$(COLOR_RED)Error: $$map should have passed but failed$(COLOR_RESET)"; \
			failure_count=$$((failure_count + 1)); \
		fi; \
	done; \
	echo "\n$(COLOR_YELLOW)Good maps test completed.$(COLOR_RESET)"; \
	if [ $$failure_count -eq 0 ]; then \
		echo "$(COLOR_GREEN)All good maps passed successfully.$(COLOR_RESET)"; \
	else \
		echo "$(COLOR_RED)$$failure_count good map(s) failed unexpectedly.$(COLOR_RESET)"; \
		echo "$(COLOR_YELLOW)Maps that unexpectedly failed:$(COLOR_RESET)"; \
		for map in $(GOOD_MAPS); do \
			./$(NAME) $$map > /dev/null 2>&1; \
			if [ $$? -ne 0 ]; then \
				echo "$(COLOR_RED)- $$map$(COLOR_RESET)"; \
			fi; \
		done; \
	fi

test_all_maps: test_good_maps test_bad_maps
	@echo "\n$(COLOR_PURPLE)All maps have been tested.$(COLOR_RESET)"

obj/%.o:	src/%.c includes/cub3D.h Makefile libft/libft.h libft/libft.a
	@echo "[...] libft... $(MESSAGE_COMPILE) $*.c\r\c"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(MESSAGE_CLEAR)"

force:
	@make -C libft/ -s
	@make -C minilibx-linux/ -s
	@echo "$(MESSAGE_DONE_MLX)"

clean:
	@$(RM) obj
	@echo "$(MESSAGE_CLEAN)"
	@make clean -C libft -s
	@make clean -C minilibx-linux -s
	@echo "$(MESSAGE_CLEAN_MLX)"

fclean:		clean
	@$(RM) $(NAME)
	@$(RM) libft/libft.a

re:			fclean all

clear:
	clear

ARG := $(shell norminette src libft includes | grep Error: | wc -l)

norm:	clear
	@if norminette src libft includes | grep -v OK; then \
		echo "$(COLOR_RED)$(ARG) norm violations found$(COLOR_RESET)"; \
	else \
		echo "$(COLOR_GREEN)All OK!"; \
	fi

.PHONY:		all clean fclean re m test_bad_maps test_good_maps test_all_maps clear norm