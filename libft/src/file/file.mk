# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    file.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/09 18:57:57 by jafaghpo          #+#    #+#              #
#    Updated: 2019/06/09 18:57:57 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCL_FILE		=	$(INCL_PATH)/file.h

SRCS_FILE		= 	ft_filetostr.c get_next_line.c ft_fopen.c ft_getline.c
SRC_FILE		=	$(addprefix $(SRC_FILE_PATH)/, $(SRCS_FILE))
OBJS_FILE		= 	$(SRCS_FILE:.c=.o)


$(OBJ_PATH)/%.o: $(SRC_FILE_PATH)/%.c $(INCL_FILE)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)