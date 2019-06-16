# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    flags.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/09 19:04:35 by jafaghpo          #+#    #+#              #
#    Updated: 2019/06/09 19:04:35 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FLAGSPRINTF	=	pf_hashtag.c pf_zero.c pf_minus.c pf_plus.c pf_space.c \
					pf_l.c pf_h.c pf_star.c pf_blank.c pf_z.c pf_j.c
SRC_FLAGSPRINTF		=	$(addprefix flags/, $(SRCS_FLAGSPRINTF))


$(OBJ_PATH)/%.o: $(SRC_FLAGSPRINTF_PATH)/%.c $(INCL_PRINTF)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)
