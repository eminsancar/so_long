NAME    = so_long
CC      = cc -g
CFLAGS  = -Wall -Wextra -Werror

INCS_MLX   = -Iinclude -Iminilibx-linux
INCS_LIBFT    = -Ilibft -Ilibft/includes
INCS_PRINTF   = -Ift_printf
INCS          = $(INCS_MLX) $(INCS_LIBFT) $(INCS_PRINTF)

SRC     =  src/check_in.c \
           src/render_map.c \
           src/get_next_line.c \
           src/images.c \
           src/main.c \
           src/init.c \
		   src/investigation.c \
		   src/check_map_accsess.c \
		   src/general_control.c \
		   src/creat_mlx.c

OBJ_DIR = obj
OBJ     = $(SRC:%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF     = $(FT_PRINTF_DIR)/libftprintf.a

MLX_DIR   = minilibx-linux
MLX_AR    = $(MLX_DIR)/libmlx_Linux.a
MLX_LIBS  = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX_AR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX_LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(MLX_AR):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
