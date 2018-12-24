/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 11:26:01 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/20 13:33:51 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# define MODIFIERS "hljz"
# define ACCEPTABLE "0123456789.hljz#0-+ "
# define CONVERSIONS "sSpdDioOuUxXcC%"
# define ERR -1
# define FLAG_ALTERNATE (1 << 0)
# define FLAG_SPACE (1 << 1)
# define FLAG_ZERO (1 << 2)
# define FLAG_MINUS (1 << 3)
# define FLAG_PLUS (1 << 4)
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define C_RESET "\033[00m"
# define C_BOLD "\033[1m"
# define CF_BLA "\033[30m"
# define CF_RED "\033[31m"
# define CF_GRE "\033[32m"
# define CF_YEL "\033[33m"
# define CF_BLU "\033[34m"
# define CF_MAG "\033[35m"
# define CF_CYA "\033[36m"
# define CF_WHI "\033[37m"
# define CB_BLA "\033[40m"
# define CB_RED "\033[41m"
# define CB_GRE "\033[42m"
# define CB_YEL "\033[43m"
# define CB_BLU "\033[44m"
# define CB_MAG "\033[45m"
# define CB_CYA "\033[46m"
# define CB_WHI "\033[47m"

enum					e_modif
{
	none,
	l,
	ll,
	hh,
	h,
	j,
	z
};

typedef union			u_types
{
	void				*generic;
	int					c;
	wint_t				lc;
	char				*s;
	wchar_t				*ls;
	signed char			hhd;
	unsigned char		hhu;
	short				hd;
	unsigned short		hu;
	int					d;
	unsigned int		u;
	long				ld;
	unsigned long		lu;
	long long			lld;
	unsigned long long	llu;
	intmax_t			jd;
	uintmax_t			ju;
	size_t				zd;
	ssize_t				zu;
}						t_types;

typedef struct			s_conv
{
	int					flags;
	int					width;
	int					precision;
	enum e_modif		modifier;
	char				conversion;
}						t_conv;

typedef char			*t_handler(t_conv *conv, void *v);

int						ft_printf(const char *format, ...);
int						ft_vprintf(const char *format, va_list ap);
int						ft_asprintf(char **ret, const char *format, ...);
int						ft_sprintf(char *str, const char *format, ...);
int						ft_vsprintf(char *str, const char *format, va_list ap);
int						ft_vasprintf(char **ret, const char *format,
										va_list ap);
int						ft_dprintf(int fd, const char *format, ...);
int						ft_vdprintf(int fd, const char *format, va_list ap);
int						find_next_conversion(char *format, char **start,
						char **end);
t_conv					*new_conversion(char *start, int len);
int						get_modifier(char *s);
int						get_flags(char *s);
int						get_precision(char *s);
int						get_width(char *s);
t_handler				*get_handler(t_conv *conv);
char					*handler_integers(t_conv *conv, void *arg);
char					*handler_string(t_conv *conv, void *arg);
char					*handler_percent(t_conv *conv, void *arg);
char					*handler_char(t_conv *conv, void *arg);
char					*handler_pointer(t_conv *conv, void *arg);
char					*ft_itoa_base_max_unsigned(uintmax_t value, int base);
char					*ft_itoa_base_max_signed(intmax_t value, int base);

#endif
