/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:18:54 by lmeyer            #+#    #+#             */
/*   Updated: 2016/11/08 15:51:36 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"
#define ERR -1

t_buf			*ft_newbuf(t_buf **buffers, int fd)
{
	t_buf		*new;
	t_buf		*tmp;
	int			r;

	if (!(new = (t_buf *)malloc(sizeof(t_buf))))
		return (NULL);
	if ((r = read(fd, new->buf, BUFF_SIZE)) == ERR)
	{
		free(new);
		return (NULL);
	}
	new->fd = fd;
	new->iter = 0;
	new->end = (r == BUFF_SIZE ? -1 : r);
	tmp = *buffers;
	*buffers = new;
	new->next = tmp;
	return (new);
}

int				ft_refill(t_buf *b, int bytes)
{
	int		r;

	ft_memmove(b->buf, b->buf + bytes, BUFF_SIZE - bytes);
	if ((r = read(b->fd, b->buf + BUFF_SIZE - bytes, bytes)) == ERR)
		return (ERR);
	else if (r != bytes && b->end == -1)
		b->end = BUFF_SIZE - bytes + r;
	else if (r != bytes && b->end != -1)
		b->end -= bytes + r;
	return (0);
}

int				ft_append(char **adest, t_buf *b, int n, int reinit)
{
	char	*res;

	if (!(res = ft_strnew(b->iter * BUFF_SIZE + n)))
		return (ERR);
	else if (!(ft_memcpy(res, *adest, b->iter * BUFF_SIZE))
			|| !(ft_memcpy(res + b->iter * BUFF_SIZE, b->buf, n)))
	{
		free(res);
		return (ERR);
	}
	else
	{
		if (*adest)
			free(*adest);
		*adest = res;
		if (reinit)
			b->iter = 0;
		return (1);
	}
}

int				find_end(t_buf *b, char **line)
{
	char	*pos;

	if (b->end != -1)
	{
		pos = ft_memchr(b->buf, '\n', b->end);
		if (ft_append(line, b, pos == NULL ? b->end : pos - b->buf, 0) == ERR
				|| ft_refill(b, pos == NULL ? b->end : pos - b->buf + 1) == ERR)
			return (ERR);
		return (1);
	}
	else if (b->end == -1 && (pos = ft_memchr(b->buf, '\n', BUFF_SIZE)))
		return (ft_append(line, b, pos - b->buf, 1) == ERR
				|| ft_refill(b, pos - b->buf + 1) == ERR ? ERR : 1);
	else
	{
		if (ft_append(line, b, BUFF_SIZE, 0) == ERR
				|| ft_refill(b, BUFF_SIZE) == ERR)
			return (ERR);
		(b->iter)++;
		return (find_end(b, line));
	}
}

int				get_next_line(const int fd, char **line)
{
	static	t_buf	*fdlist[1] = { NULL };
	t_buf			*buf;
	t_buf			**tmp;
	t_buf			*nxt;

	if (!line || fd <= ERR)
		return (ERR);
	buf = *fdlist;
	while (buf && buf->fd != fd)
		buf = buf->next;
	if (!buf && !(buf = ft_newbuf(fdlist, fd)))
		return (ERR);
	*line = ft_strdup("");
	if (buf->end == 0)
	{
		tmp = fdlist;
		while ((*tmp)->fd != fd)
			(*tmp) = (*tmp)->next;
		nxt = (*tmp)->next;
		free(*tmp);
		*tmp = nxt;
		return (0);
	}
	return (find_end(buf, line));
}
