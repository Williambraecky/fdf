/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:25:32 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/05 10:59:11 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector3d	ft_asvector2d(float x, float y)
{
	return (ft_asvector3d(x, y, 0));
}

t_vector3d	ft_asvector3d(float x, float y, float z)
{
	t_vector3d res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

void		ft_destroy_image(t_fdf *fdf, t_image *image)
{
	image->width = 0;
	image->height = 0;
	free(image->points);
	mlx_destroy_image(fdf->mlx_ptr, image->img_ptr);
	free(image);
}

void		ft_check_map_image(t_fdf *fdf, t_map *map)
{
	int	width;

	width = fdf->menu->enabled ? WIN_WIDTH - MENU_WIDTH : WIN_WIDTH;
	if (map->image == NULL || map->image->width != width)
	{
		if (map->image != NULL)
			ft_destroy_image(fdf, map->image);
		map->image = ft_new_image(fdf, width, WIN_HEIGHT);
	}
	else
		ft_memset(map->image->data, 0,
				map->image->width * map->image->height * map->image->bpp);
}
