/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:19:08 by lmeyer            #+#    #+#             */
/*   Updated: 2016/11/08 08:51:54 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 4096

typedef	struct		s_buf
{
	int				fd;
	int				end;
	int				iter;
	char			buf[BUFF_SIZE];
	struct s_buf	*next;
}					t_buf;

int					get_next_line(const int fd, char **line);

#endif
