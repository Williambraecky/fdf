/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:45:22 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/05 11:00:01 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_fill_trigo(t_map *map, float *trigo)
{
	trigo[SINX] = sin(ft_toradians(map->x_rot));
	trigo[COSX] = cos(ft_toradians(map->x_rot));
	trigo[SINY] = sin(ft_toradians(map->y_rot));
	trigo[COSY] = cos(ft_toradians(map->y_rot));
}

t_vector3d	ft_genvector(t_map *map, int x, int y, float trigo[])
{
	t_vector3d result;

	result = ft_asvector3d(
		(x - map->offsetx) * map->zoom + map->image->width / 2 + map->x_off,
		(y - map->offsety) * map->zoom + map->image->height / 2 + map->y_off,
		1000 + -(map->data[y][x].height * map->heightmult * map->zoom));
	result = ft_rotateaccordingly(result, trigo, map->rotating);
	return (result);
}

void		ft_genpoint(t_map *map, t_menu *menu)
{
	int		y;
	int		x;
	float	trigo[4];

	ft_fill_trigo(map, trigo);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->points[y][x] = ft_genvector(map, x, y, trigo);
			if (map->data[y][x].forced_color == 0)
			{
				map->data[y][x].color =
					ft_color_lerp(menu->start_color, menu->end_color,
							ft_ilerp(map->minheight, map->maxheight,
								map->data[y][x].height));
			}
			x++;
		}
		y++;
	}
}

void		ft_allocpoints(t_map *map)
{
	int y;

	if (!(map->points = malloc(sizeof(t_vector3d *) * map->height)))
		ft_exit("Could not allocate enough memory");
	y = 0;
	while (y < map->height)
		if (!(map->points[y++] = malloc(sizeof(t_vector3d) * map->width)))
			ft_exit("Could not allocate enough memory");
}

void		ft_render(t_fdf *fdf)
{
	ft_check_map_image(fdf, fdf->map);
	fdf->map->rotating = ft_asvector3d(
		fdf->map->image->width / 2 + fdf->map->x_off,
		fdf->map->image->height / 2 + fdf->map->y_off,
		1000 + -((fdf->map->maxheight - fdf->map->minheight) *
			fdf->map->heightmult * fdf->map->zoom / 2));
	fdf->map->eye = ft_asvector3d(fdf->map->image->width / 2,
			fdf->map->image->height / 2,
			1000);
	if (fdf->map->points == NULL)
		ft_allocpoints(fdf->map);
	ft_genpoint(fdf->map, fdf->menu);
	fdf->map->renderer(fdf->map);
	if (fdf->menu->enabled)
		ft_put_menu(fdf, fdf->menu);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
			fdf->map->image->img_ptr, fdf->menu->enabled ? MENU_WIDTH : 0, 0);
}
