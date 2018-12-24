/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 20:27:56 by lmeyer            #+#    #+#             */
/*   Updated: 2018/09/28 20:27:57 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_mlx.h"
#include <stdlib.h>

t_image		*init_image(void *mlx_ptr, int w, int h)
{
	t_image	*img;

	if (NULL == (img = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	ft_bzero(img, sizeof(t_image));
	if (NULL == (img->img_ptr = mlx_new_image(mlx_ptr, w, h)))
		return (NULL);
	if (NULL == (img->data_addr = mlx_get_data_addr(img->img_ptr,
					&(img->bits_per_pixel), &(img->size_line), &(img->endian))))
		return (NULL);
	img->chars_per_pixel = img->bits_per_pixel / 8;
	img->pixels_per_line = img->size_line / img->chars_per_pixel;
	img->w = w;
	img->h = h;
	return (img);
}

void		mlx_free_image(void *mlx_ptr, t_image *img)
{
	if (NULL != img->img_ptr)
		mlx_destroy_image(mlx_ptr, img->img_ptr);
	free(img);
}
