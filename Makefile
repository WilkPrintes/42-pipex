NAME = pipex

CC			:= gcc

HEADER_DIR 	:= ./

INCLUDE		:=	$(foreach directory, $(HEADER_DIR), -I $(directory))

SRC_DIR		:= ./

SRC_FILE	:=  pipex.c pipex_utils.c

SRC			:=	$(foreach file, $(SRC_FILE), $(SRC_DIR)$(file))

UTILS_DIR	:= ./utils/

UTILS_FILE	:=  ft_bzero.c ft_calloc.c ft_putstr_fd.c ft_split.c ft_strlen.c \
				ft_strdup.c  ft_strjoin.c ft_strchr.c ft_strtrim.c ft_substr.c \
				ft_strlcpy.c ft_strncmp.c ft_strnstr.c

UTILS		:= $(foreach file, $(UTILS_FILE), $(UTILS_DIR)$(file))

FLAGS 		:= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC) ./pipex.h
	@$(CC) -g $(SRC) $(UTILS) -o $@ $(INCLUDE) $(FLAGS)
	@echo "\033[0;32mcompiled (>‿◠)\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;31mpipex deleted (ㆆ_ㆆ)\033[0m"

clean:
	@rm -rf *.o

re: fclean all

$(OBJ_DIR):
	@mkdir -p $@

norma:
	norminette ./

.PHONY: all fclean re