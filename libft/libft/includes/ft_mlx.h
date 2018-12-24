/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:50:20 by lmeyer            #+#    #+#             */
/*   Updated: 2018/09/28 19:56:44 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H
# include "mlx.h"

typedef struct		s_image
{
	void			*img_ptr;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				chars_per_pixel;
	int				pixels_per_line;
	int				w;
	int				h;
}					t_image;

typedef struct		s_window
{
	void			*win_ptr;
	int				w;
	int				h;
	char			*name;
}					t_window;

t_image				*init_image(void *mlx_ptr, int w, int h);
void				mlx_free_image(void *mlx_ptr, t_image *img);
t_window			*init_window(void *mlx_ptr, int w, int h, char *name);
void				mlx_free_window(void *mlx_ptr, t_window *win);

#endif
