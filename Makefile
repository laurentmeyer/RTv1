# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 11:39:09 by jpriou            #+#    #+#              #
#    Updated: 2019/01/18 12:04:12 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_RED=$(shell tput setaf 1 2> /dev/null || echo "")
_GREEN=$(shell tput setaf 2 2> /dev/null || echo "")
_YELLOW=$(shell tput setaf 3 2> /dev/null || echo "")
_BLUE=$(shell tput setaf 4 2> /dev/null || echo "")
_PURPLE=$(shell tput setaf 5 2> /dev/null || echo "")
_CYAN=$(shell tput setaf 6 2> /dev/null || echo "")
_WHITE=$(shell tput setaf 7 2> /dev/null || echo "")
_END=$(shell tput sgr0 2> /dev/null || echo "")

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = rtv1
BUILDDIR = builds/
SOURCEDIR = srcs/
HEADERDIR = includes/

SRCFILES = ""

include files.mk

LIBS = \
		ft \
		mlx \

LIBFT = 		./libft/

MINILIB = 		./mlx/

CCHEADERS = -I./$(HEADERDIR) \
			-I$(LIBFT)/libft/includes \
			-I$(LIBFT)/ft_printf/includes \
			-I$(MINILIB)

CCLIBS = -L$(LIBFT) -lft \
		 -L$(MINILIB) -lmlx

CCFRAMEWORKS = -framework AppKit -framework OpenGL

OBJ = $(SRC:%.c=%.o)

.PHONY: all
all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT)
	make -C $(MINILIB)
	@$(CC) $(CCHEADERS) $(CCLIBS) $(OBJ) $(CCFRAMEWORKS) -o $(NAME)

%.o : %.c
	@printf "%smaking $@%s\\n" "$(_YELLOW)" "$(_END)"
	@$(CC) $(CFLAGS) $(CCHEADERS) -c $< -o $@

.PHONY: clean
clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(MINILIB) clean
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: norme
norme:
	@norminette $(SRC) $(HEADERDIR) $(LIBFT)
