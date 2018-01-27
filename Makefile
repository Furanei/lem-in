# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/30 18:29:49 by mbriffau          #+#    #+#              #
#    Updated: 2018/01/27 01:30:21 by mbriffau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
CC =		clang
CFLAGS =	-Wall -Wextra -Werror
ADDFLAGS = 

# Default rule
DEFRULE =	all

NAME =		lem-in

# Directories	
SRCDIR =	srcs
OBJDIR =	objs
INCDIR =	includes\

# Sources
SRC = \
		main.c \
		parse.c \
		parse_ant.c \
		parse_command.c \
		parse_room.c \
		parse_pipe.c \
		parse_error.c \
		tools.c \
		lem_test.c

OBJ =		$(SRC:.c=.o)

# Prefixes
LIBFT =		-Llibft/ -lft

# Paths foreach
LIBP =		$(addprefix -L, $(LIBNAME)/)
OBJP =		$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCP =		$(foreach dir, $(INCDIR), -I$(dir))

# **************************************************************************** #
# SPECIAL CHARS

LOG_CLEAR		= \033[2K
LOG_UP			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_UNDERLINE	= \033[4m
LOG_BLINKING	= \033[5m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m

# **************************************************************************** #
# RULES

# Main rules
default:
	@make $(DEFRULE)

all: $(OBJDIR) $(NAME)

re: fclean all

# Compilation rules

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(ADDFLAGS) -c -o $@ $^ $(INCP)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJP)
	@$(CC) $(CFLAGS) $(ADDFLAGS) -o $@ $^ $(INCP) libft/libft.a

.PHONY: fclean clean re

clean:
	@rm -rf $(OBJDIR)

fclean:
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)
