# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    put.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/09 18:59:26 by jafaghpo          #+#    #+#              #
#    Updated: 2019/06/09 18:59:26 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCL_PUT		=	$(INCL_PATH)/put.h

SRCS_PUT		=	ft_error.c
SRC_PUT			=	$(addprefix $(SRC_PUT_PATH)/, $(SRCS_PUT))
OBJS_PUT		=	$(SRCS_PUT:.c=.o)


$(OBJ_PATH)/%.o: $(SRC_PUT_PATH)/%.c $(INCL_PUT)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)