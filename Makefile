NAME = pipex

CC			:= gcc

HEADER_DIR 	:= ./

INCLUDE		:=	$(foreach directory, $(HEADER_DIR), -I $(directory))

SRC_DIR		:= ./

SRC_FILE	:=  pipex.c pipex_utils.c ft_split.c ft_strdup.c

SRC			:=	$(foreach file, $(SRC_FILE), $(SRC_DIR)$(file))

FLAGS 		:= 

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) -g $(SRC) -o $@ $(INCLUDE) $(FLAGS)
	@echo "\033[0;32mcompiled (>‿◠)\033[0m"

fclean:
	@rm -rf $(NAME)
	@echo "\033[0;31mpipex deleted (ㆆ_ㆆ)\033[0m"

re: fclean all

$(OBJ_DIR):
	@mkdir -p $@

test: fclean re
	make -C ./pipex-tester

norma:
	norminette ./

.PHONY: all fclean re