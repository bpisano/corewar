# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpisano <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 19:19:47 by bpisano           #+#    #+#              #
#    Updated: 2018/10/04 19:04:37 by bpisano     ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PART1 = ft_memset.c				\
	  	ft_bzero.c				\
	  	ft_memcpy.c				\
		ft_memccpy.c			\
	  	ft_memmove.c			\
	  	ft_memchr.c				\
	  	ft_memcmp.c				\
	  	ft_strlen.c				\
	  	ft_strdup.c				\
	  	ft_strcpy.c				\
		ft_strncpy.c			\
	  	ft_strcat.c				\
	  	ft_strncat.c			\
		ft_strlcat.c			\
	  	ft_strchr.c				\
	  	ft_strrchr.c			\
	  	ft_strstr.c				\
	  	ft_strnstr.c			\
	  	ft_strcmp.c				\
	  	ft_strncmp.c			\
	  	ft_atoi.c				\
	  	ft_isalpha.c			\
	  	ft_isdigit.c			\
	  	ft_isalnum.c			\
		ft_isascii.c			\
		ft_isprint.c			\
		ft_toupper.c			\
		ft_tolower.c			\

PART2 = ft_memalloc.c			\
		ft_realloc.c			\
		ft_memdel.c				\
		ft_strnew.c				\
		ft_strrealloc.c			\
		ft_strdel.c				\
		ft_strclr.c				\
		ft_striter.c			\
		ft_striteri.c			\
		ft_strmap.c				\
		ft_strmapi.c			\
		ft_strequ.c				\
		ft_strnequ.c			\
		ft_strsub.c				\
		ft_strjoin.c			\
		ft_strtrim.c			\
		ft_strsplit.c			\
		ft_itoa.c				\
		ft_putchar.c			\
		ft_putstr.c				\
		ft_putendl.c			\
		ft_putnbr.c				\
		ft_putchar_fd.c			\
		ft_putstr_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c			\

BONUS = ft_lstnew.c				\
		ft_lstdelone.c			\
		ft_lstdel.c				\
		ft_lstadd.c				\
		ft_lstiter.c			\
		ft_lstmap.c

EXTRA = ft_abs.c				\
		ft_sqrt.c				\
		ft_str_is_empty.c		\
		ft_isblank.c			\
		ft_iscntrl.c			\
		ft_isgraph.c			\
		ft_islower.c			\
		ft_isspace.c			\
		ft_isupper.c			\
		ft_isxdigit.c			\
		ft_str_is_alpha.c		\
		ft_str_is_lowercase.c	\
		ft_str_is_numeric.c		\
		ft_str_is_printable.c	\
		ft_str_is_uppercase.c	\
		ft_strcapitalize.c		\
		ft_strlowcase.c			\
		ft_strcasestr.c			\
		ft_strlcpy.c			\
		ft_strcasecmp.c			\
		ft_strncasecmp.c		\
		ft_strndup.c			\
		ft_strupcase.c			\
		ft_itoa_base.c			\
		ft_lst_push_back.c 		\
		ft_lstpopi.c			\
		ft_lstat.c				\
		ft_lstlen.c				\
		ft_strset.c				\
		ft_ctos.c				\
		ft_putwchar.c			\
		ft_putwchar_fd.c		\
		ft_putwstr.c			\
		ft_putwstr_fd.c			\
		ft_wcharlen.c			\
		ft_wstrlen.c			\
		ft_wstrnew.c			\
		ft_wstrset.c			\
		ft_wctos.c				\
		ft_wstrjoin.c			\
		ft_wstrcat.c			\
		ft_wstrcpy.c			\
		ft_wstrdup.c			\
		ft_wstrsub.c			\
		ft_wstrncpy.c			\
		ft_wstrdel.c			\
		ft_strtowchr.c			\
		get_next_line.c			\
		skip_next_line.c		\
		ft_tablen.c				\
		ft_printf/alpha_type_manager.c	\
		ft_printf/arg_manager.c			\
		ft_printf/arg_setter.c			\
		ft_printf/buffer_manager.c		\
		ft_printf/buffer_properties.c	\
		ft_printf/flag_manager.c		\
		ft_printf/ft_itoa_base_arg.c	\
		ft_printf/ft_printf.c			\
		ft_printf/num_type_manager.c	\
		ft_printf/percent_buffer.c		\
		ft_printf/string_manager.c		\
		ft_printf/value_manager.c		\

OBJECTS = $(PART1:.c=.o) $(PART2:.c=.o) $(BONUS:.c=.o) $(EXTRA:.c=.o)

HEADS = ./includes

FLAGS = -Wall -Werror -Wextra

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
END = \033[0m

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@echo "$(BLUE)$(NAME)\033[500D\033[42C$(GREEN)[DONE]$(END)"

%.o : %.c
	@echo "$(YELLOW)Compiling$(END) $(notdir $@) \033[500D\033[42C$(RED)[KO]$(END)"
	@gcc -I $(HEADS) $(FLAGS) -o $@ -c $<
	@echo "\033[1A\033[500D\033[42C$(GREEN)[DONE]$(END)"

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
