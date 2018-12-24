CC = 		gcc
CFLAGS =	-Wall -Wextra -Werror
NAME =		libft_int_array.a
BUILDDIR =	builds
SOURCEDIR =	srcs
HEADERDIR = includes

CCHEADERS = -I./$(HEADERDIR)		\
			-I../libft/includes

SRCFILES =	sort.c					\
			percentile.c			\
			basics.c				\
			constructor.c			\
			insertions.c			\
			min_max.c				\
			stack.c					\
			rank.c					\
			exclusions.c


SOURCES =	$(SRCFILES:%.c=$(SOURCEDIR)/%.c)
OBJECTS =	$(SOURCES:$(SOURCEDIR)/%.c=$(BUILDDIR)/%.o)

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(BUILDDIR)/%.o : $(SOURCEDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CCHEADERS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR)
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all