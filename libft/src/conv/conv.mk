# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    conv.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/09 18:57:40 by ggregoir          #+#    #+#              #
#    Updated: 2019/06/09 18:57:40 by ggregoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCL_CONV		=	$(INCL_PATH)/conv.h

SRCS_CONV		=	ft_atoi.c ft_atoi_split.c ft_itoa.c ft_tolower.c ft_toupper.c
SRC_CONV		=	$(addprefix $(SRC_CONV_PATH)/, $(SRCS_CONV))
OBJS_CONV		=	$(SRCS_CONV:.c=.o)


$(OBJ_PATH)/%.o: $(SRC_CONV_PATH)/%.c $(INCL_CONV)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)