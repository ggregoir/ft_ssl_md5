# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    conv.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/09 19:02:32 by jafaghpo          #+#    #+#              #
#    Updated: 2019/06/09 19:02:33 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_CONVPRINTF	=	pf_a.c pf_maj_a.c pf_b.c pf_maj_b.c pf_c.c pf_maj_c.c pf_d.c pf_maj_d.c \
					pf_e.c pf_maj_e.c pf_f.c pf_maj_f.c pf_g.c pf_maj_g.c pf_i.c pf_maj_i.c \
					pf_k.c pf_o.c pf_maj_o.c pf_p.c pf_s.c pf_maj_s.c pf_u.c pf_maj_u.c \
					pf_x.c pf_maj_x.c pf_per.c
SRC_CONVPRINTF		=	$(addprefix conv/, $(SRCS_CONVPRINTF))


$(OBJ_PATH)/%.o: $(SRC_CONVPRINTF_PATH)/%.c $(INCL_PRINTF)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)
