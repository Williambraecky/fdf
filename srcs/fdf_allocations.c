/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_allocations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:36:14 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/22 19:27:09 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_destroy_image(t_fdf *fdf, t_image *image)
{
	image->width = 0;
	image->height = 0;
	mlx_destroy_image(fdf->mlx_ptr, image->img_ptr);
	free(image);
}

t_image	*ft_new_image(t_fdf *fdf, int width, int height)
{
	t_image		*img;

	if (!(img = malloc(sizeof(t_image))))
		return (NULL);
	img->img_ptr = mlx_new_image(fdf->mlx_ptr, width, height);
	if (img->img_ptr == NULL)
		ft_exit("Could not allocate enough memory");
	img->data = mlx_get_data_addr(img->img_ptr,
			&(img->bpp), &(img->size_line), &(img->endian));
	img->bpp /= 8;
	img->width = width;
	img->height = height;
	return (img);
}

t_fdf	*ft_new_fdf(void)
{
	t_fdf	*fdf;

	if (!(fdf = malloc(sizeof(t_fdf))))
		return (NULL);
	fdf->menu_enabled = 1;
	return (fdf);
}

t_map	*ft_new_map(void)
{
	t_map	*map;

	if (!(map = malloc(sizeof(t_map))))
		return (NULL);
	map->image = NULL;
	map->maxheight = 0;
	map->heightmult = 1;
	map->zoom = 16;
	map->width = -1;
	map->height = -1;
	map->x_rot = 10;
	map->y_rot = 0;
	return (map);
}
