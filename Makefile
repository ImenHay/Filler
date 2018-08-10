CC	= gcc
FLAGS =		 -Wall -Werror -Wextra

FLAGS_ASAN = -g 	-fsanitize=address	\
				-fno-omit-frame-pointer		\
				-fsanitize-address-use-after-scope \
				-Wall -Werror -Wextra

CPP_FLAGS = -Iinclude
LDFLAGS = -Llibft
LDLIBS = -lft

NAME = imhaimou.filler

NAME_PROJECT = filler

SRC_PATH = src/
LIB_PATH = libft
SRCLIB_PATH = $(LIB_PATH)/src
INC_PATH = include/

SRC_NAME =	main.c      \
			get_next_line.c \
			get.c		\
			tools.c		\
			map_tools.c \
			piece.c		\
			place.c		\
			init.c		\
			enemy.c     \
			copy.c


LIB_NAME = libft.a

LIBFT_A_P = $(LIB_PATH)/$(LIB_NAME)

INC_NAME = filler.h

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))


all : $(NAME) $(LIBFT_A_P)

$(NAME): $(SRC) $(INC) $(LIBFT_A_P)
		$(CC) $(FLAGS) -I./include $(SRC) $(LIB) -o $(NAME)
	@echo "\033[1;34m$(NAME_PROJECT)\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

clean:
	@make clean -C $(LIB_PATH)
	@echo "\033[1;34m$(NAME_PROJECT)\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

$(LIBFT_A_P):
	@make -C $(LIB_PATH)


fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "\033[1;34m$(NAME_PROJECT)\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all
