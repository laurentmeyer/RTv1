/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 11:39:14 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/14 11:39:17 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

char		*g_optarg;
int			g_optind = 1;
int			g_optopt;
int			g_opterr = 1;
int			g_optreset;

static int	restart_or_start_next(int argc, char **argv, char **curarg_ptr)
{
	g_optreset = 0;
	if (g_optind >= argc || (*curarg_ptr = (argv[g_optind]))[0] != '-')
	{
		*curarg_ptr = "";
		return (-1);
	}
	if ((*curarg_ptr)[1] && (++(*curarg_ptr))[0] == '-')
	{
		g_optind++;
		*curarg_ptr = "";
		return (-1);
	}
	return (0);
}

static int	arg_not_in_optstr(char **curarg_ptr, const char *optstring)
{
	if (g_optopt == (int)'-')
		return (-1);
	if ((*curarg_ptr)[0] == '\0')
		g_optind++;
	if (g_opterr && optstring[0] != ':')
		ft_dprintf(STDERR, "illegal option -- %c\n", g_optopt);
	return ((int)'?');
}

static void	no_argument_needed(char **curarg_ptr)
{
	g_optarg = NULL;
	if ((*curarg_ptr)[0] == '\0')
		g_optind++;
}

static int	argument_needed(int argc, char **argv,
							char **curarg_ptr, const char *optstring)
{
	if ((*curarg_ptr)[0] != '\0')
		g_optarg = *curarg_ptr;
	else if (++g_optind >= argc)
	{
		*curarg_ptr = "";
		if (optstring[0] == ':')
			return ((int)':');
		if (g_opterr)
			ft_dprintf(STDERR, "option requires an argument -- %c\n",
					g_optopt);
		return ((int)'?');
	}
	else
		g_optarg = argv[g_optind];
	*curarg_ptr = "";
	++g_optind;
	return (0);
}

int			ft_getopt(int argc, char **argv, const char *optstring)
{
	static char	*curarg_ptr = "";
	char		*optstr_ptr;
	int			ret;

	if (g_optreset || curarg_ptr[0] == '\0')
		if (restart_or_start_next(argc, argv, &curarg_ptr) == -1)
			return (-1);
	if ((g_optopt = (int)(*curarg_ptr++)) == (int)':' ||
			(optstr_ptr = ft_strchr(optstring, g_optopt)) == NULL)
		return (arg_not_in_optstr(&curarg_ptr, optstring));
	if ((++optstr_ptr)[0] != ':')
		no_argument_needed(&curarg_ptr);
	else if ((ret = argument_needed(argc, argv, &curarg_ptr, optstring)))
		return (ret);
	return (g_optopt);
}
