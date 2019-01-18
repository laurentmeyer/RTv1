/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:06:17 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:06:34 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "ft_mlx.h"

# define WIN_H		480
# define WIN_W		640
# define WIN_NAME	"RTv1"

typedef struct		s_display
{
	void			*mlx_ptr;
	t_window		*mlx_win;
	t_image			*mlx_img;
}					t_display;

#endif
