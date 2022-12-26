NAME = so_long

SRCS = check_map_2.c check_map.c check_path.c ft_itoa.c prcs_map.c \
		main.c utils.c minilibx/libmlx.a ft_printf/libftprintf.a \
		get_next_line/get_next_line.a

OBJS = $(SRCS:.c=.o)

GNL = make -C ./get_next_line

PF = make -C ./ft_printf

MLX = make -C ./minilibx

LFALGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx

$(NAME):
		@$(GNL)
		@$(PF)
		@$(MLX)
		@gcc $(FLAGS) $(LFALGS) *.c minilibx/libmlx.a ft_printf/libftprintf.a get_next_line/get_next_line.a -o so_long

all: $(NAME)

clean:
		@make fclean -C ./get_next_line
		@make fclean -C ./ft_printf
		@make clean -C ./minilibx

fclean: clean
		@rm -rf so_long
		
re: fclean all

.PHONY: all clean fclean re
