NAME := so_long
SRC_DIR := ./src/
OBJ_DIR := ./obj/
HEADER_DIR := ./inc/
SRCS :=	enemy.c \
		exit.c \
		game.c \
		initialize.c \
		main.c \
		map_check_input.c \
		map_check_setup.c \
		map_display.c \
		map_get_images.c \
		map_put.c \
		map_read.c \
		random.c
OBJS := $(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))
HEADERS := $(HEADER_DIR)*.h
CC := gcc
ifeq ($(DEBUG),1)
CFLAGS := -g -Wall -Wextra -Werror -D DEBUGGING=1 -I$(HEADER_DIR)
else
CFLAGS := -g -Wall -Wextra -Werror -D DEBUGGING=0 -I$(HEADER_DIR)
endif
AR := ar
ARFLAGS := rcs
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
NC := \033[0m
LIBFT_DIR := ./libft/
LIBFT := $(LIBFT_DIR)libft.a
LIBFT_OBJS := $(LIBFT_DIR)obj/*.o
MLX_DIR := ./mlx/
MLX := $(MLX_DIR)libmlx_Linux.a
MLX_FLAGS := -lXext -lX11 -lm -lz
DEPS := $(HEADERS) $(LIBFT) $(MLX)
MAKE += --no-print-directory

all: link $(NAME)

link:
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)

$(NAME): $(OBJ_DIR) $(OBJS) $(DEPS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $@
	@echo "\n$(GREEN)creating: $(NAME)$(NC)"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEPS) ofilemessage
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo ".\c"

ofilemessage:
	@echo "compiling $(NAME)-object-files: \c"

clean:
	@rm -f $(OBJ_DIR)*.o
	@echo "$(RED)$(NAME)-object-files deleted$(NC)"
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) deleted$(NC)"
	@make fclean -C $(LIBFT_DIR)

re: fclean all

peace:
	@echo "\n"
	@echo "     .''.    .',"
	@echo "     |  |   /  /"
	@echo "     |  |  /  /"
	@echo "     |  | /  /"
	@echo "     |  |/  ;-._"
	@echo "     }  \` _/  / ;"
	@echo "     |  /\` ) /  /"
	@echo "     | /  /_/\_/\ "
	@echo "     |/  /      |"
	@echo "     (  ' \ '-  |"
	@echo "      \    \`.  /"
	@echo "       |      |"
	@echo "       |      |\n"

.INTERMEDIATE: ofilemessage

.PHONY: clean fclean all re link