/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:04:44 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:04:44 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <unistd.h>
#include <stdlib.h>

void	exit_message(t_ram *ram, int exit_code, char *message)
{
	if (NULL != message)
		ft_putstr_fd(message, STDERR_FILENO);
	if (NULL != ram)
		free_ram(ram);
	exit(exit_code);
}
