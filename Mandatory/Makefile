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


SRCS		=	main.c \
				err.msg.c \
				destroy_mlx.c \
				free.c \
				gnl.c \
				gnl_utils.c \
				i_mlx.c \
				i_to_null.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_strlen.c \
				map_utils_2.c \
				map_utils.c \
				minimap_moves.c \
				player_moves.c \

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
