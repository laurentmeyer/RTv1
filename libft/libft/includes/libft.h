/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <lmeyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:47:56 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/18 12:37:25 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <wchar.h>
# define MININT -2147483648
# define MININTSIZE 11
# define MININTSTR "-2147483648"

typedef	struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef int				(t_listcmp)(t_list *l1, t_list *l2);
typedef void			(t_listdisplay)(t_list *l);

void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src,
									int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strstr(const char *big, const char *little);
char					*ft_strnstr(const char *big,
									const char *little, size_t len);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
int						ft_isascii(int c);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
									char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s,
									unsigned int start, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
void					ft_free_strsplit(char ***to_free);
char					*ft_itoa(int n);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst,
										void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int						ft_countwords(char const *s, char c);
int						ft_atoi_hex(char *s);
int						ft_is_hex_str(char *s);
char					*ft_strndup(const char *s1, size_t n);
char					*ft_insert_str(char *dst, char *start,
										char *end, char *src);
char					*ft_strrev(char *s);
char					*ft_itoa_base(int value, int base);
void					ft_strtolower(char *s);
char					*ft_strlast(char *s);
char					*ft_wcrtoutf(wchar_t w);
int						ft_valid_int_str(char *s, int strict);
int						gnlite(const int fd, char **line);
int						ft_getopt(int argc, char **argv,
										const char *optstring);
t_list					*ft_lstpop(t_list **elem);
size_t					ft_lstlen(t_list *start);
void					ft_lstsort(t_list **alst, t_listcmp *f);
void					ft_lstappend(t_list **alst, t_list *to_append);
void					ft_lstrev(t_list **alst);
char					*ft_basename(char *path);
char					**ft_argsplit(int *aac, char **av);
int						ft_intlen(int n);
void					ft_swap_int(int *a, int *b);
double					ft_atof(char const *s);
double					ft_bound(double min, double max, double cand);
size_t					ft_index(char **haystack, char *needle);

#endif
