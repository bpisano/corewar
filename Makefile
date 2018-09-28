# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/15 18:40:16 by bpisano      #+#   ##    ##    #+#        #
#    Updated: 2018/09/28 14:21:07 by bpisano     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = asm

SRC = compiler/sources/main.c				\
	  compiler/sources/error.c				\
	  compiler/sources/binary_gestion.c		\
	  compiler/sources/file_manager.c		\
	  compiler/sources/read_file.c			\
	  compiler/sources/str_cleaner.c		\
	  compiler/sources/header.c				\
	  compiler/sources/header_manager.c		\
	  compiler/sources/core_text.c			\
	  compiler/sources/cmd_manager.c		\

OBJECTS = $(SRC:.c=.o)

LIB = libft.a

HEADS = -I ./compiler/includes			\
		-I ./libft/includes				\

FLAGS = -Wall -Werror -Wextra

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
END = \033[0m

all: $(NAME)

$(LIB):
	@make -C libft

$(NAME): $(LIB) $(OBJECTS)
	@gcc -o $(NAME) $(OBJECTS) libft/$(LIB)
	@echo "$(BLUE)$(NAME)\033[500D\033[42C$(GREEN)[DONE]$(END)"

%.o : %.c
	@echo "Compiling $(notdir $@)\033[500D\033[42C$(RED)[KO]$(END)"
	@gcc $(HEADS) -o $@ -c $?
	@echo "\033[1A\033[500D\033[42C$(GREEN)[DONE]$(END)"

clean:
	@rm -f $(OBJECTS)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all
