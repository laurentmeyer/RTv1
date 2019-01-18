/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ram.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:04:59 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:05:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdlib.h>

t_ram	*init_ram_pre_parsing(void)
{
	t_ram *ram;

	if (NULL == (ram = (t_ram *)malloc(sizeof(t_ram))))
		exit_message(ram, ERROR, "Could not initialize RAM\n");
	ft_bzero(ram, sizeof(t_ram));
	init_scene(ram);
	return (ram);
}

void	init_ram_post_parsing(t_ram *ram)
{
	init_display(ram);
	init_hooks(ram);
}

void	free_ram(t_ram *ram)
{
	free_parsing(&(ram->parsing));
	if (NULL != ram->scene)
		free_scene(ram->scene);
	if (NULL != ram->display)
		free_display(ram->display);
	free(ram);
}
