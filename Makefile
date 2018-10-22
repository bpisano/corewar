# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/15 18:40:16 by bpisano      #+#   ##    ##    #+#        #
#    Updated: 2018/10/22 14:59:17 by bpisano     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

ASM = asm
VM = corewar

SRC_COMP = compiler/sources/main.c					\
	  	   compiler/sources/free_split.c			\
		   compiler/sources/error.c					\
		   compiler/sources/binary_manager.c		\
		   compiler/sources/binary_manager_2.c		\
		   compiler/sources/file_manager.c			\
		   compiler/sources/read_file.c				\
		   compiler/sources/file_verification.c		\
		   compiler/sources/file_verification_2.c	\
		   compiler/sources/str_cleaner.c			\
		   compiler/sources/header.c				\
		   compiler/sources/header_manager.c		\
		   compiler/sources/core_text.c				\
		   compiler/sources/cmd_manager.c			\
		   compiler/sources/op_type.c				\
		   compiler/sources/fnct.c					\
		   compiler/sources/handle_op.c				\
		   compiler/sources/initialisation.c		\

SRC_VM = vm/sources/main.c							\
		 vm/sources/checker.c						\
		 vm/sources/check_champ.c					\
		 vm/sources/vm_exec.c						\
		 vm/sources/win_checker.c					\
		 vm/sources/process_init.c					\
		 vm/sources/process_manager.c				\

HEADS = -I ./compiler/includes						\
		-I ./vm/includes							\
		-I ./libft/includes							\
		-I ./global									\

OBJ_ASM = $(SRC_COMP:.c=.o)
OBJ_VM = $(SRC_VM:.c=.o)

LIB = libft.a

FLAGS = -Wall -Werror -Wextra

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
END = \033[0m

all: $(ASM) $(VM)

$(LIB):
	@make -C libft

$(ASM): $(LIB) $(OBJ_ASM)
	@gcc -o $(ASM) $(OBJ_ASM) libft/$(LIB)
	@echo "$(BLUE)$(ASM)\033[500D\033[42C$(GREEN)[DONE]$(END)"

$(VM): $(OBJ_VM)
	@gcc -o $(VM) $(OBJ_VM) libft/$(LIB)
	@echo "$(BLUE)$(VM)\033[500D\033[42C$(GREEN)[DONE]$(END)"

%.o : %.c
	@echo "Compiling $(notdir $@)\033[500D\033[42C$(RED)[KO]$(END)"
	@gcc $(HEADS) -o $@ -c $?
	@echo "\033[1A\033[500D\033[42C$(GREEN)[DONE]$(END)"

clean:
	@rm -f $(OBJ_ASM) $(OBJ_VM)
	@make clean -C libft

fclean: clean
	@rm -f $(ASM) $(VM)
	@make fclean -C libft

re: fclean all
