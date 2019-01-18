CC = 		gcc
CFLAGS =	-Wall -Wextra -Werror
NAME = 		libft_original.a
BUILDDIR =	builds
SOURCEDIR =	srcs
HEADERDIR = includes

SRCFILES =	ft_memset.c			\
			ft_bzero.c			\
			ft_memcpy.c			\
			ft_memccpy.c		\
			ft_memmove.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_strlen.c			\
			ft_strdup.c			\
			ft_strcpy.c			\
			ft_strncpy.c		\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_strcat.c			\
			ft_strncat.c		\
			ft_strlcat.c		\
			ft_strstr.c			\
			ft_strnstr.c		\
			ft_strcmp.c			\
			ft_strncmp.c		\
			ft_atoi.c			\
			ft_intlen.c			\
			ft_isalpha.c		\
			ft_isdigit.c		\
			ft_isalnum.c		\
			ft_isascii.c		\
			ft_isprint.c		\
			ft_toupper.c		\
			ft_tolower.c		\
			ft_memalloc.c		\
			ft_memdel.c			\
			ft_strnew.c			\
			ft_strdel.c			\
			ft_strclr.c			\
			ft_striter.c		\
			ft_striteri.c		\
			ft_strmap.c			\
			ft_strmapi.c		\
			ft_strequ.c			\
			ft_strnequ.c		\
			ft_strsub.c			\
			ft_strjoin.c		\
			ft_strtrim.c		\
			ft_strsplit.c		\
			ft_free_strsplit.c	\
			ft_itoa.c			\
			ft_putchar.c		\
			ft_putstr.c			\
			ft_putendl.c		\
			ft_putnbr.c			\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_lstnew.c			\
			ft_lstdelone.c		\
			ft_lstdel.c			\
			ft_lstadd.c			\
			ft_lstiter.c		\
			ft_lstmap.c			\
			get_next_line.c		\
			ft_countwords.c		\
			ft_atoi_hex.c		\
			ft_atof.c			\
			ft_bound.c			\
			ft_is_hex_str.c		\
			ft_strndup.c		\
			ft_insert_str.c		\
			ft_strrev.c			\
			ft_itoa_base.c		\
			ft_strtolower.c		\
			ft_strlast.c		\
			ft_valid_int_str.c	\
			ft_wcrtoutf.c		\
			gnlite.c			\
			ft_index.c			\
			ft_getopt.c			\
			ft_lstpop.c			\
			ft_lstsort.c		\
			ft_lstlen.c			\
			ft_lstappend.c		\
			ft_lstrev.c			\
			ft_basename.c		\
			ft_argsplit.c		\
			btree_create_node.c	\
			btree_insert_node.c	\
			ft_swap_int.c		\
			ft_mlx_window.c		\
			ft_mlx_image.c

CCHEADERS = -I./$(HEADERDIR)		\
			-I../libft/includes		\
			-I../ft_printf/includes

SOURCES = $(SRCFILES:%.c=$(SOURCEDIR)/%.c)
OBJECTS = $(SOURCES:$(SOURCEDIR)/%.c=$(BUILDDIR)/%.o)

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
