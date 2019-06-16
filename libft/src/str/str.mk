# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    str.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/09 19:02:01 by jafaghpo          #+#    #+#              #
#    Updated: 2019/06/12 19:51:32 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCL_STR		=	$(INCL_PATH)/str.h

SRCS_STR		=	ft_strcat.c ft_strcmp.c ft_strdup.c ft_striteri.c \
					ft_strlcat.c ft_strmapi.c ft_strncpy.c ft_strnstr.c \
					ft_strstr.c ft_strupper.c ft_strchr.c ft_strcpy.c \
					ft_strequ.c ft_strjoin.c ft_strlen.c ft_strncat.c \
					ft_strnequ.c ft_strrchr.c ft_strsub.c ft_wstrcpy.c \
					ft_strclr.c ft_strdel.c ft_striter.c ft_strjoin_free.c \
					ft_strmap.c ft_strncmp.c ft_strnew.c ft_strsplit.c \
					ft_strtrim.c ft_wstrlen.c ft_delspace.c ft_strcmp_space.c \
					ft_sizestr.c tab_total_size.c tab_size.c implode.c
SRC_STR			=	$(addprefix $(SRC_STR_PATH)/, $(SRCS_STR))
OBJS_STR		=	$(SRCS_STR:.c=.o)


$(OBJ_PATH)/%.o: $(SRC_STR_PATH)/%.c $(INCL_STR)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)