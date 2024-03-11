NAME		=	Cub3d

GREEN		=	\033[1;32m
RED			=	\033[1;31m
DEFAULT		=	\033[0m

OBJ_DIR		=	objs
SRC_DIR		=	$(shell find . -type d)

vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)

SRCS		 =	main.cpp \
				
OBJS		=	$(SRCS:%.cpp=${OBJ_DIR}/%.o)

RM			=	rm -rf

CC			=	cc

CFLAGS		=	-Werror -Wall -Wextra -g3

all:	${NAME}

$(NAME): ${OBJS}
		@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
		@echo "$(GREEN)Compiled$(DEFAULT)"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) :
		@mkdir -p $@

clean:
		@${RM} $(OBJ_DIR)

fclean: clean
	@printf "${GREEN}Clean${DEFAULT}\n"
	@${RM} ${NAME}

re:		    fclean
	@$(MAKE) all -j > /dev/null 2>&1 || true
	@echo "$(GREEN)Compiled$(DEFAULT)"

.PHONY:		all clean fclean re