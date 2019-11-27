# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/09 19:06:55 by ggregoir          #+#    #+#              #
#    Updated: 2019/11/27 23:15:24 by ggregoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

OBJ_PATH		=	obj
SRC_PATH		=	src
INCL_PATH		=	include

SRC_CHAR_PATH	=	$(SRC_PATH)/char
SRC_CONV_PATH	=	$(SRC_PATH)/conv
SRC_FILE_PATH	=	$(SRC_PATH)/file
SRC_PRINTF_PATH	=	$(SRC_PATH)/ft_printf
SRC_LIST_PATH	=	$(SRC_PATH)/list
SRC_MEM_PATH	=	$(SRC_PATH)/mem
SRC_PUT_PATH	=	$(SRC_PATH)/put
SRC_STR_PATH	=	$(SRC_PATH)/str
SRC_PRINTF_PATH	=	$(SRC_PATH)/printf

include $(SRC_CHAR_PATH)/char.mk
include $(SRC_CONV_PATH)/conv.mk
include $(SRC_FILE_PATH)/file.mk
include $(SRC_LIST_PATH)/list.mk
include $(SRC_MEM_PATH)/mem.mk
include $(SRC_PUT_PATH)/put.mk
include $(SRC_STR_PATH)/str.mk
include $(SRC_PRINTF_PATH)/printf.mk

OBJS			=	$(OBJS_CONV) $(OBJS_FILE) $(OBJS_CHAR) \
					$(OBJS_MEM) $(OBJS_PUT) $(OBJS_STR) \
					$(OBJS_PRINTF) $(OBJS_LIST)
OBJ				=	$(addprefix $(OBJ_PATH)/, $(OBJS))

all: $(NAME)

$(NAME): obj $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

obj:
	mkdir -p $(OBJ_PATH)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
