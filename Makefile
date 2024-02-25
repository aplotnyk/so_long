NAME	= so_long
CC		= gcc
CFLAGS	= -Wextra -Wall -Werror 

LIBFT_PATH =	libs/libft/
LIBFT_NAME =	libft.a
LIBFT =			$(LIBFT_PATH)$(LIBFT_NAME)

LIBMLX_PATH = libs/MLX42
LIBMLX_NAME = /build/libmlx42.a
LIBMLX = $(LIBMLX_PATH)$(LIBMLX_NAME) -ldl -lglfw -pthread -lm

INC_LIBMLX =	-I ./include -I $(LIBMLX_PATH)/include
INC_LIBFT =		-I ./libft

SRC_PATH = src/
SRC	= so_long.c map.c map_chars_check.c map_path_check.c images.c \
		hooks.c	utils.c moves.c close_game.c errors.c
SRCS =	$(addprefix $(SRC_PATH), $(SRC))


OBJ_PATH =	obj/
OBJ =		$(SRC:.c=.o)
OBJS =		$(addprefix $(OBJ_PATH), $(OBJ))

all: libft libmlx $(NAME)

$(OBJ_PATH)%.o :$(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC_LIBMLX) $(INC_LIBFT)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

libft:
	@make -sC $(LIBFT_PATH)

libmlx:
	@cmake $(LIBMLX_PATH) -B $(LIBMLX_PATH)/build && make -C $(LIBMLX_PATH)/build -j4

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBMLX) $(INC_LIBMLX) $(LIBFT) -o $(NAME)

bonus: all

clean:
	@rm -Rf $(OBJ_PATH)
	@make clean -sC $(LIBFT_PATH)
	@rm -Rf $(LIBMLX_PATH)/build
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx