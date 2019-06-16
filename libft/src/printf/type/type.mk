# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    type.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/09 19:06:50 by jafaghpo          #+#    #+#              #
#    Updated: 2019/06/09 19:06:50 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_TYPEPRINTF	=	pf_int.c pf_intmax.c pf_ssize.c pf_short.c pf_long.c pf_2short.c pf_2long.c \
					pf_uint.c pf_uintmax.c pf_size.c pf_ushort.c pf_ulong.c pf_u2short.c pf_u2long.c
SRC_TYPEPRINTF	=	$(addprefix type/, $(SRCS_TYPEPRINTF))


$(OBJ_PATH)/%.o: $(SRC_TYPEPRINTF_PATH)/%.c $(INCL_PRINTF)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)
