/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:04:56 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:04:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parsing.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void		free_parsing(t_parsing *parsing)
{
	if (parsing->fd > 2)
		close(parsing->fd);
	if (NULL != parsing->line)
		free(parsing->line);
	if (NULL != parsing->split)
		ft_free_strsplit(&(parsing->split));
}
