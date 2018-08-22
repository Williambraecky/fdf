/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:45:22 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/22 19:42:35 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_genpoint(t_map *map)
{
	int	y;
	int	x;

	if (!(map->points = malloc(sizeof(t_vector3d *) * map->height)))
		ft_exit("Could not allocate enough memory");
	y = 0;
	while (y < map->height)
	{
		x = 0;
		if (!(map->points[y] = malloc(sizeof(t_vector3d) * map->width)))
			ft_exit("Could not allocate enough memory");
		while (x < map->width)
		{
			map->points[y][x] = ft_asvector3d(
					(x - map->offsetx) * map->zoom + map->image->width / 2,
					(y - map->offsety) * map->zoom + map->image->height / 2,
					1000 + (map->data[y][x] * map->heightmult * map->zoom));
			map->points[y][x] = ft_rotatex(map->points[y][x],
					map->x_rot, map->rotating);
			map->points[y][x] = ft_rotatey(map->points[y][x],
					map->y_rot, map->rotating);
			x++;
		}
		y++;
	}
}

void	ft_delpoints(t_map *map)
{
	int	y;

	y = map->height;
	while (y--)
		free(map->points[y]);
	free(map->points);
	map->points = NULL;
}

void	ft_draw_map(t_map *map)
{
	t_vector2d	current;
	int			y;
	int			x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			current = ft_to2dvector(map->points[y][x], map->eye);
			if (x < (map->width - 1))
				ft_draw_line(map->image, current,
						ft_to2dvector(map->points[y][x + 1], map->eye), 16711680);
			if (y < (map->height - 1))
				ft_draw_line(map->image, current,
						ft_to2dvector(map->points[y + 1][x], map->eye), 16711680);
			x++;
		}
		y++;
	}
}

void	ft_render(t_fdf *fdf)
{
	if (fdf->map->image != NULL)
		ft_destroy_image(fdf, fdf->map->image);
	fdf->map->image = ft_new_image(fdf,
			fdf->menu_enabled ? WIN_WIDTH - MENU_WIDTH : WIN_WIDTH, WIN_HEIGHT);
	fdf->map->rotating = ft_asvector3d(fdf->map->image->width / 2,
			fdf->map->image->height / 2,
			1000 + (fdf->map->maxheight - fdf->map->minheight) * fdf->map->heightmult * fdf->map->zoom / 2);
	fdf->map->eye = ft_asvector3d(fdf->map->image->width / 2,
			fdf->map->image->height / 2,
			800);
	ft_genpoint(fdf->map);
	ft_draw_map(fdf->map);
	ft_delpoints(fdf->map);
	if (fdf->menu_enabled)
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->menu->img_ptr,
				0, 0);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
			fdf->map->image->img_ptr, fdf->menu_enabled ? MENU_WIDTH : 0, 0);
}
