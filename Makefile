# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/08 12:30:55 by ggregoir          #+#    #+#              #
#    Updated: 2019/07/19 02:12:44 by ggregoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	ft_ssl

CC				=	gcc
PATH_PROJECT	=	$(shell pwd)
CFLAGS			=	-Wall -Werror -Wextra -g -D PATH=\"$(PATH_PROJECT)\"

ifeq ($(DEBUG), yes)
	CFLAGS	+=	-g -D DEBUG -fsanitize=address
else
	CFLAGS	+=	-Ofast
endif

SRCS		=	main.c functions_str.c get_next_line.c error.c parsing.c \
				md5.c sha256.c tables.c op.c print_md5.c print_sha256.c
SRC			=	$(addprefix src/, $(SRCS))
OBJ			=	$(addprefix obj/, $(SRCS:.c=.o))
INCL_DIR	=	include
INCL		=	$(INCL_DIR)/ft_ssl.h
LIBFT_DIR	=	$(PATH_PROJECT)/libft
LIBFT		=	$(LIBFT_DIR)/libft.a


all: $(NAME)

$(NAME): obj $(LIBFT) $(OBJ)
	@$(CC) -o $@ $(OBJ) $(LIBFT) $(CFLAGS)
	@echo "\033[0;36m-----------------------------------------------"
	@echo "\033[0;32m[ ✔ ] Done compiling" $(NAME)
	@echo "\033[0;36m-----------------------------------------------\x1b[0m"

obj:
	@mkdir obj

$(LIBFT):
	make -C $(LIBFT_DIR)

obj/%.o: src/%.c $(INCL)
	@echo "\033[0;35m[ -> ] Compiling $<"
	@$(CC) -o $@ -c $< -I $(INCL_DIR) $(CFLAGS)

clean:
	@rm -f $(OBJ)
	@echo "\033[0;31m[ ✔ ] Removed project object files"
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(PATH_PROJECT)/obj
	@echo "\033[0;31m[ ✔ ] Removed executable" $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all
