# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/15 18:40:16 by bpisano      #+#   ##    ##    #+#        #
#    Updated: 2018/06/25 17:41:12 by bpisano     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = lem-in

SRC = sources/main.c			\
	  sources/display.c			\
	  sources/parse.c			\
	  sources/parse_type.c		\
	  sources/cmd_manager.c		\
	  sources/room_manager.c	\
	  sources/data_manager.c	\

OBJECTS = $(SRC:.c=.o)

LIB = libft.a

LIBAR = libarray.a

HEADS = -I ./includes			\
		-I ./libft/includes		\
		-I ./ft_array			\

FLAGS = -Wall -Werror -Wextra

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
END = \033[0m

all: $(NAME)

$(LIB):
	@make -C libft

$(LIBAR):
	@make -C ft_array

$(NAME): $(LIB) $(LIBAR) $(OBJECTS)
	@gcc -o $(NAME) $(OBJECTS) libft/$(LIB) ft_array/$(LIBAR)
	@echo "$(BLUE)$(NAME)\033[500D\033[42C$(GREEN)[DONE]$(END)"

%.o : %.c
	@echo "Compiling $(notdir $@)\033[500D\033[42C$(RED)[KO]$(END)"
	@gcc $(FLAGS) $(HEADS) -o $@ -c $?
	@echo "\033[1A\033[500D\033[42C$(GREEN)[DONE]$(END)"

clean:
	@rm -f $(OBJECTS)
	@make clean -C libft
	@make clean -C ft_array

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@make fclean -C ft_array

re: fclean all
