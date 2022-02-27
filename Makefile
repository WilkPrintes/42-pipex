NAME = pipex

CC			:= gcc

HEADER_DIR 	:= ./

INCLUDE		:=	$(foreach directory, $(HEADER_DIR), -I $(directory))

SRC_DIR		:= ./

SRC_FILE	:=  pipex.c

SRC			:=	$(foreach file, $(SRC_FILE), $(SRC_DIR)$(file))

UTILS_DIR	:= ./utils/

UTILS_FILE	:=  ft_bzero.c ft_calloc.c ft_putstr_fd.c ft_split.c ft_strlen.c \
				ft_strdup.c  ft_strjoin.c ft_strchr.c ft_strtrim.c ft_substr.c \
				ft_strlcpy.c ft_strncmp.c

UTILS		:= $(foreach file, $(UTILS_FILE), $(UTILS_DIR)$(file))

FLAGS 		:= 

all: $(NAME)

$(NAME): $(SRC) ./pipex.h
	@$(CC) -g $(SRC) $(UTILS) -o $@ $(INCLUDE) $(FLAGS)
	@echo "\033[0;32mcompiled (>‿◠)\033[0m"

fclean:
	@rm -rf $(NAME)
	@echo "\033[0;31mpipex deleted (ㆆ_ㆆ)\033[0m"

re: fclean all

$(OBJ_DIR):
	@mkdir -p $@

test: fclean re
	rm -f outfile
	make -C ./pipex-tester

norma:
	norminette ./

.PHONY: all fclean re