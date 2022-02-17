NAME = pipex

CC 			:= gcc

HEADER_DIR 	:= ./

INCLUDE		:=	$(foreach directory, $(HEADER_DIR), -I $(directory))

SRC_DIR		:= ./

SRC_FILE	:=  pipex.c

SRC			:=	$(foreach file, $(SRC_FILE), $(SRC_DIR)$(file))

FLAGS 		:= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	$(CC) -g $(SRC) -o $@ $(INCLUDE) $(FLAGS)

fclean:
	rm -rf $(NAME)

re: fclean all

$(OBJ_DIR):
	mkdir -p $@

.PHONY: all fclean re