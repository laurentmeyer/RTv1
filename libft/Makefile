CC = 		gcc
CFLAGS =	-Wall -Wextra -Werror
NAME =		libft.a

LFTPATH =		./libft
LIBFT = 		$(LFTPATH)/libft_original.a
PRINTFPATH =	./ft_printf
PRINTF =		$(PRINTFPATH)/libftprintf.a
INTARRPATH =	./int_array
INTARR =		$(INTARRPATH)/libft_int_array.a


.PHONY: all clean fclean re

all : $(NAME)

$(NAME) :
	$(MAKE) -C $(LFTPATH)
	$(MAKE) -C $(PRINTFPATH)
	$(MAKE) -C $(INTARRPATH)
	libtool -static -o $(NAME) $(LIBFT) $(PRINTF) $(INTARR)

clean:
	$(MAKE) -C $(LFTPATH) clean
	$(MAKE) -C $(PRINTFPATH) clean
	$(MAKE) -C $(INTARRPATH) clean

fclean: clean
	$(MAKE) -C $(LFTPATH) fclean
	$(MAKE) -C $(PRINTFPATH) fclean
	$(MAKE) -C $(INTARRPATH) fclean
	rm -f $(NAME)

re: fclean all
