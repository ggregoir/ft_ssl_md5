# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    char.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/09 18:57:04 by jafaghpo          #+#    #+#              #
#    Updated: 2019/06/09 18:57:05 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCL_CHAR		=	$(INCL_PATH)/char.h

SRCS_CHAR		=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c \
					ft_isdigit.c ft_islower.c ft_isprint.c ft_ispunct.c \
					ft_isspace.c ft_isupper.c
SRC_CHAR		=	$(addprefix $(SRC_CHAR_PATH)/, $(SRCS_CHAR))
OBJS_CHAR		=	$(SRCS_CHAR:.c=.o)


$(OBJ_PATH)/%.o: $(SRC_CHAR_PATH)/%.c $(INCL_CHAR)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)