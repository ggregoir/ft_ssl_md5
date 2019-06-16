# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    list.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/10 00:07:04 by jafaghpo          #+#    #+#              #
#    Updated: 2019/06/11 00:18:16 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCL_LIST		=	$(INCL_PATH)/list.h

SRCS_LIST		=	list_new.c list_delete.c list_push.c list_pop.c list_map.c \
					list_iter.c list_filter.c list_get.c list_insert.c \
					list_remove.c
SRC_LIST		=	$(addprefix $(SRC_LIST_PATH)/, $(SRCS_LIST))
OBJS_LIST		=	$(SRCS_LIST:.c=.o)


$(OBJ_PATH)/%.o: $(SRC_LIST_PATH)/%.c $(INCL_LIST)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)