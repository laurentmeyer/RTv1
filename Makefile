CC = 		gcc
CFLAGS =	-g -Wall -Wextra -Werror
BINARY =	rtv1
BUILDDIR =	builds
SOURCEDIR =	srcs
HEADERDIR = includes

SRCFILES =						\
			display.c			\
			exit.c				\
			init_display.c		\
			init_scene.c		\
			init_ram.c			\
			hooks.c				\
			main.c				\
			math.c				\
			object.c			\
			collisions.c		\
			transformations.c	\
			shape_sphere.c		\
			geometry.c			\
			render.c		

LIBS =		ft						\
			mlx

LIBFT = 		./libft/

MINILIB = 		./mlx/

CCHEADERS = -I./$(HEADERDIR)				\
			-I$(LIBFT)/libft/includes		\
			-I$(LIBFT)/ft_printf/includes	\
			-I$(MINILIB)

CCLIBS = -L$(LIBFT) -lft			\
		 -L$(MINILIB) -lmlx

CCFRAMEWORKS = -framework AppKit -framework OpenGL

SOURCES = $(SRCFILES:%.c=$(SOURCEDIR)/%.c)
OBJECTS = $(SOURCES:$(SOURCEDIR)/%.c=$(BUILDDIR)/%.o)

.PHONY: clean fclean all re norme newline $(LIBFT)/libft.a

all : $(BINARY)

newline:
		@echo "\033[38;5;166m\033[0m\n"

$(BINARY) : $(OBJECTS)
	make -C $(LIBFT)
	make -C $(MINILIB)
	@$(CC) $(CCHEADERS) $(CCLIBS) $(OBJECTS) $(CCFRAMEWORKS) -o $(BINARY)

$(BUILDDIR)/%.o : $(SOURCEDIR)/%.c
	echo "\033[1A\033[K\033[38;5;226mmaking $@\033[0m"
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CCHEADERS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(MINILIB) clean
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(BINARY)

re: fclean all

norme: newline
		norminette $(SOURCES) includes
