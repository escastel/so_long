NAME = solong

NAME_BONUS = solongbonus

SOLONG = so_long.a

SOLONGBONUS = so_long_bonus.a

FILES = slong/check_map.c \
slong/draw_map.c \
slong/hooks.c \
slong/save_map.c \
slong/so_long.c 

FILES_BONUS = slong_bonus/check_content.c \
slong_bonus/check_map_bonus.c \
slong_bonus/draw_map_bonus.c \
slong_bonus/hooks_bonus.c \
slong_bonus/save_map_bonus.c \
slong_bonus/so_long_bonus.c 

OBJECTS = $(FILES:.c=.o)

OBJECTS_BONUS = $(FILES_BONUS:.c=.o)

FLAGS = -Werror -Wall -Wextra

LIBFT = ./libft/libft.a

MLX42 = ./MLX42/libmlx42.a

LIB_SYS = -Iinclude -lglfw -L"/Users/escastel/.brew/opt/glfw/lib/"

$(NAME):		$(OBJECTS) $(LIBFT) $(MLX42)
					ar rcs $(SOLONG) $(OBJECTS)
					gcc $(FLAGS) $(SOLONG) $(MLX42) $(LIBFT) $(LIB_SYS) -o $(NAME)

$(OBJECTS_BONUS):	slong_bonus/%.o : slong_bonus/%.c 
						gcc $(FLAGS) -c $< -o $@

$(LIBFT):
				make -s -C ./libft

$(MLX42):
				make -s -C ./MLX42

all: 			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME_BONUS): 	$(OBJECTS_BONUS) $(LIBFT) $(MLX)
					ar rcs $(SOLONGBONUS) $(OBJECTS_BONUS)
					gcc $(FLAGS) $(SOLONGBONUS) $(MLX42) $(LIBFT) $(LIB_SYS) -o $(NAME_BONUS)

clean:
				rm -f $(OBJECTS) $(OBJECTS_BONUS)
				make clean -s -C ./MLX42
				make clean -s -C ./libft

fclean:
				rm -f $(NAME_BONUS) $(NAME) $(OBJECTS) $(OBJECTS_BONUS) $(SOLONG) $(SOLONGBONUS) $(LIBFT) $(MLX42)
				make fclean -s -C ./MLX42
				make fclean -s -C ./libft

re: 			fclean all

.PHONY: all re clean fclean bonus
