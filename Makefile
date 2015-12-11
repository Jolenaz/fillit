NAME = fillit

CC = gcc
CFLAGS = -Werror -Wall -Wextra

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/
LIB_PATH = ./lib/

LIB_NAME = -lft

SRC_NAME = check_tetr.c read_file.c utils.c main.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIB = $(addprefix -L, $(LIB_PATH))
INC = $(addprefix -I, $(INC_PATH))

LDFLAGS = $(LIB) $(LIB_NAME)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "\033[38;5;47m"$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

clean:
	@rm -rf $(OBJ)
	@echo "\033[38;5;9m"rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[38;5;9m"rm -rf $(NAME)

re: fclean all

norme:
	@norminette $(SRC) $(INC_PATH) | sed "s/Norme/[0;1;47m\
	[0;38;5;47mNorme/g; s/Warning/[38;5;9m Warning/g; s/Error/\
	[38;5;9m Error/g"
