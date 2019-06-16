# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mem.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/09 18:59:05 by jafaghpo          #+#    #+#              #
#    Updated: 2019/06/11 19:44:47 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCL_MEM		=	$(INCL_PATH)/mem.h

SRCS_MEM		=	ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
					ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_nbbits.c \
					ft_realloc.c ft_memdup.c
SRC_MEM			=	$(addprefix $(SRC_MEM_PATH)/, $(SRCS_MEM))
OBJS_MEM		=	$(SRCS_MEM:.c=.o)


$(OBJ_PATH)/%.o: $(SRC_MEM_PATH)/%.c $(INCL_MEM)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)