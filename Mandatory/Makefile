NAME = cub3d

GREEN		=	\033[1;32m
RED			=	\033[1;31m
DEFAULT		=	\033[0m

OBJ_DIR		=	objs
INC_DIR		=	Includes
SRC_DIR		=	$(shell find Sources -type d)
LIB_DIR		=	-L -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_LIB		=	./mlx/libmlx_Linux.a
MLX			=	./mlx

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)
vpath %.h $(INC_DIR):


SRCS		=	msg_error.c \
				destroy_mlx.c \
				free.c \
				gnl_utils.c \
				gnl.c \
				i_map.c \
				i_map2.c \
				i_mlx.c \
				i_player.c \
				i_rgb.c \
				i_to_null.c \
				raycast.c \
				render.c \
				ft_lst.c \
				ft_split.c \
				ft_str.c \
				ft_utils.c \
				map_utils_2.c \
				map_utils.c \
				minimap_moves.c \
				player_moves.c \
				check_map.c \
				check_player.c \
				check_textures.c \
				data_on_map.c \
				main.c

OBJS		=	$(SRCS:%.c=${OBJ_DIR}/%.o)

.c.o:
	@echo "$(GREEN)Compiling $<...$(DEFAULT)"
	@${CC} ${CFLAGS} -I${MLX} -c $< -o ${<:.c=.o}

RM			= rm -rf

CC			=	clang
CFLAGS		=	-Werror -Wall -Wextra -g3

all:	${NAME}

${MLX_LIB}:
	@echo "$(GREEN)Compiling MLX library...$(DEFAULT)"
	@make -C ${MLX} -j > /dev/null 2>&1

$(NAME):	${MLX_LIB} ${OBJS} $(INC_DIR)/cub.h
	@echo "$(GREEN)Linking and building $@...$(DEFAULT)"
	@${CC} ${CFLAGS} ${OBJS} -I ${INC_DIR} -o ${NAME} ${MLX_LIB} ${LIB_DIR}
	@echo "$(GREEN)Cub3d compiled$(DEFAULT)"

$(OBJ_DIR)/%.o: %.c $(INC_DIR)/cub.h | $(OBJ_DIR)
	@${CC} ${CFLAGS} -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR) :
	@mkdir -p $@

clean:
	@echo "$(RED)Cleaning objects...$(DEFAULT)"
	@${RM} $(OBJ_DIR)
	@make clean -C ${MLX} > /dev/null

fclean:		clean
	@echo "$(RED)Removing executables and libraries...$(DEFAULT)"
	@${RM} ${NAME}
	@${RM} ${MLX_LIB}
	@echo "$(GREEN)Everything cleaned$(DEFAULT)"

re:			fclean
	@echo "$(GREEN)Rebuilding...$(DEFAULT)"
	@$(MAKE) all -j > /dev/null

.PHONY:		all clean fclean re norm
