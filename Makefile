# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/30 18:29:49 by mbriffau          #+#    #+#              #
#    Updated: 2018/03/06 15:55:45 by mbriffau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

# Compilation
CC = clang

# FLAGGGS
FLAGS =	-Wall -Wextra -Werror

# Directories	
SRCS_PATH = srcs/
OBJ_PATH  = obj/
LIBFT_PATH = lib/

# Sources
SRCS_NAME = \
		main.c \
		input_analysis.c \
		parse_command.c \
		parse_room.c \
		parse_pipe.c \
		parse_error.c \
		solve.c \
		mark_the_map.c \
		print_ant.c

# Paths foreach
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	$(CC) $(FLAGS) $(OBJ) $(INC) -L $(LIBFT_PATH) lib/libftprintf.a -o $(NAME)
	@echo "$(NAME)\033[1;0m\033[32m created.\033[0m"

# Compilation rules

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
		@echo "$(notdir $<)\033[1m\033[32m compiled.\033[0m"
		@mkdir -p `dirname $@`
		@gcc -c $(FLAGS) $(INC) $< -o $@

clean:
		@make -C $(LIBFT_PATH) clean
		-/bin/rm -rf $(OBJ_PATH)
		@echo "All files .o have been \033[1;31mdeleted\033[0m."

fclean: clean
		-/bin/rm -rf $(NAME)
		make -C $(LIBFT_PATH) fclean
		@echo "$(NAME) has been \033[1;31mdeleted\033[0m."

re: fclean all

.PHONY: all, clean, fclean, re
