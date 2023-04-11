# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrami <mrami@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 16:39:21 by mrami             #+#    #+#              #
#    Updated: 2023/04/11 00:47:00 by mrami            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = push_swap
BName = checker
HEADER = pushSwap.h
cc = cc
CFlags = -Wall -Wextra -Werror # -g -fsanitize=address
CFiles = push_swap.c ft_check_alpha_max_min.c ft_get_arg.c ft_push_helper.c push_utils.c  ft_movement.c ft_movement1.c ft_movement2.c ft_sorting.c sort_big.c sort_big1.c
BFiles = ft_check_alpha_max_min.c ft_get_arg.c ft_push_helper.c push_utils.c ft_cheker.c get_next_line.c get_next_line_utils.c ft_checker_help.c ft_checker_help1.c ft_movement2.c
BOFiles = $(BFiles:.c=.o)
COFiles = $(CFiles:.c=.o)
# -----------------------------------
all: $(Name)
	@echo "-> Making Succssful."
# -----------------------------------
$(Name): $(COFiles)
		@$(cc) $(CFlags) $(CFiles) -o $(Name)
%.o : %.c $(HEADER)
		@$(cc) $(CFlags) -c $<
# ------------------------------------
bonus: $(BName)
	@echo "-> Bonus Making Succssful."
# -------------------------------------
$(BName): $(BOFiles)
		@$(cc) $(CFlags) $(BFiles) -o $(BName)
%.o : %.c $(HEADER)
		@$(cc) $(CFlags) -c $<
# -----------------------------------
clean:
		@rm -f $(COFiles) $(BOFiles)
		@echo "-> Cleaning Succssful."
# --------------------------------------
fclean: clean
		@rm -f $(Name) $(BName)
		@echo "-> FClean Well Be Succssful."
# ------------------------------------
re: fclean all
# ------------------------------------
.PHONY: all clean fclean re