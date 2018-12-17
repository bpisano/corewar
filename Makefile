# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/15 18:40:16 by bpisano      #+#   ##    ##    #+#        #
#    Updated: 2018/12/13 18:42:34 by anamsell    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

ASM = asm
VM = corewar

SRC_GLOB = global/operations.c						\

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
		   compiler/sources/param_bin.c				\
		   compiler/sources/usage.c					\

SRC_VM = vm/sources/main.c							\
		 vm/sources/checker.c						\
		 vm/sources/check_champ.c					\
		 vm/sources/swap_reg.c						\
		 vm/sources/vm_exec.c						\
		 vm/sources/win_checker.c					\
		 vm/sources/process_init.c					\
		 vm/sources/process_manager.c				\
		 vm/sources/process_exec.c					\
		 vm/sources/reg_manager.c					\
		 vm/sources/operations_manager.c			\
		 vm/sources/operation_checker.c				\
		 vm/sources/ui_init.c						\
		 vm/sources/ui_display.c					\
		 vm/sources/ui_display_2.c					\
		 vm/sources/ui_update.c						\
		 vm/sources/ui_setter.c						\
		 vm/sources/ui_print.c						\
		 vm/sources/ui_key_event.c					\
		 vm/sources/ui_reg_manager.c				\
		 vm/sources/fnc.c							\
		 vm/sources/functions/ft_add.c				\
		 vm/sources/functions/ft_aff.c				\
		 vm/sources/functions/ft_and.c				\
		 vm/sources/functions/ft_fork.c				\
		 vm/sources/functions/ft_ld.c				\
		 vm/sources/functions/ft_ldi.c				\
		 vm/sources/functions/ft_lfork.c			\
		 vm/sources/functions/ft_live.c				\
		 vm/sources/functions/ft_lld.c				\
		 vm/sources/functions/ft_lldi.c				\
		 vm/sources/functions/ft_or.c				\
		 vm/sources/functions/ft_st.c				\
		 vm/sources/functions/ft_sti.c				\
		 vm/sources/functions/ft_sub.c				\
		 vm/sources/functions/ft_xor.c				\
		 vm/sources/functions/ft_zjmp.c				\
		 vm/sources/ft_mod.c						\
		 vm/sources/usage.c							\


HEADS = -I ./compiler/includes						\
		-I ./vm/includes							\
		-I ./libft/includes							\
		-I ./global									\

OBJ_GLOB = $(SRC_GLOB:.c=.o)
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

$(ASM): $(LIB) $(OBJ_GLOB) $(OBJ_ASM)
	@gcc $(FLAGS) -o $(ASM) $(OBJ_GLOB) $(OBJ_ASM) libft/$(LIB)
	@echo "$(BLUE)$(ASM)\033[500D\033[42C$(GREEN)[DONE]$(END)"

$(VM): $(OBJ_GLOB) $(OBJ_VM)
	@gcc $(FLAGS) -o $(VM) $(OBJ_GLOB) $(OBJ_VM) libft/$(LIB) -lncurses
	@echo "$(BLUE)$(VM)\033[500D\033[42C$(GREEN)[DONE]$(END)"

%.o : %.c global/op.h global/corewar.h vm/includes/vm.h compiler/includes/compiler.h
	@echo "$(YELLOW)Compiling$(END) $(notdir $@)\033[500D\033[42C$(RED)[KO]$(END)"
	@gcc $(HEADS) -o $@ -c $<
	@echo "\033[1A\033[500D\033[42C$(GREEN)[DONE]$(END)"

clean:
	@rm -f $(OBJ_ASM) $(OBJ_VM) $(OBJ_GLOB)
	@make clean -C libft

fclean: clean
	@rm -f $(ASM) $(VM)
	@make fclean -C libft

re: fclean all
