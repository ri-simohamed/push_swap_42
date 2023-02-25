# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrami <mrami@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 16:39:21 by mrami             #+#    #+#              #
#    Updated: 2023/02/25 16:59:47 by mrami            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = push_swap
HEADER = pushSwap.h
cc = cc
CFlags = -Wall -Wextra -Werror
CFiles = ft_check_alpha_max_min.c ft_get_arg.c ft_push_helper.c push_utils.c 
COFiles = $(CFiles:.c=.o)
# -----------------------------------
all: $(Name)

$(Name): $(COFiles)
		$(cc) $(CFlags) $(CFiles) -o $(Name)
%.o : %.c $(HEADER)
		$(cc) $(CFlags) -c $<
# ------------------------------------
clean:
		rm -f $(COFiles)
fclean: clean
		rm -f $(Name)
# ------------------------------------
re: fclean all
# ------------------------------------
.PHONY: all clean fclean re