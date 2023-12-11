# Sample Makefile
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(MINILIBX_DIR) -I/usr/include -Imlx_linux -O3
#CFLAGS_MAC = -Wall -Wextra -Werror -I$(MINILIBX_MAC_DIR) -I$(INCLUDE_DIR)
LIBFT = -L$(LIBFT_DIR) -lft
MINILIBX = -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MINILIBX_ARQ = libmlx_Linux.a
#MINILIBX_MAC = -L$(MINILIBX_MAC_DIR) -lmlx -framework OpenGL -framework AppKit
NAME = fdf

INCLUDE_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
LIBFT_DIR = ./libft
MINILIBX_DIR = ./minilibx-linux
#MINILIBX_MAC_DIR = ./minilibx

SRC_FILES =  $(SRC_DIR)/main.c \
			 $(SRC_DIR)/utils.c \
			 $(SRC_DIR)/errors.c \
			 $(SRC_DIR)/errors_utils.c \
			 $(SRC_DIR)/matrix_info.c \
			 $(SRC_DIR)/drawing_utils.c \
			 $(SRC_DIR)/drawing.c \
			 $(SRC_DIR)/events.c

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: libft minilibx $(NAME)

libft:
	make -C $(LIBFT_DIR)

minilibx:
#	make -C $(MINILIBX_MAC_DIR)
	make -C $(MINILIBX_DIR)

$(NAME): $(OBJ_FILES)
#	$(CC) $^ -o $@ $(LIBFT) $(MINILIBX_MAC)
	$(CC) $^ -o $@ $(LIBFT) $(MINILIBX)


# Make sure dir exists
$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Create object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
#	$(CC) $(CFLAGS_MAC) -c $< -o $@
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(MINILIBX_DIR) clean
#	@make -C $(MINILIBX_MAC_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
	@if [ -d "$(OBJ_DIR)" ]; then 		rm -rf $(OBJ_DIR); 	fi

fclean: clean
	@cd $(MINILIBX_DIR) && rm -f $(MINILIBX_ARQ)
	@rm -f $(NAME)
	@rm -f $(LIBFT_DIR)/libft.a

re: fclean all

.PHONY: all clean fclean re libft minilibx

