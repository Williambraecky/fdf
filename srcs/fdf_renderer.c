/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:45:22 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/29 16:25:36 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_genpoint(t_map *map, t_menu *menu)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->points[y][x] = ft_asvector3d(
					(x - map->offsetx) * map->zoom + map->image->width / 2,
					(y - map->offsety) * map->zoom + map->image->height / 2,
					1000 + (map->data[y][x].height * map->heightmult * map->zoom));
			map->points[y][x] = ft_rotatex(map->points[y][x],
					map->x_rot, map->rotating);
			map->points[y][x] = ft_rotatey(map->points[y][x],
					map->y_rot, map->rotating);
			if (map->data[y][x].forced_color == 0)
			{
				map->data[y][x].color =
					ft_color_lerp(menu->start_color, menu->end_color,
							ft_ilerp(map->minheight, map->maxheight, map->data[y][x].height));
			}
			x++;
		}
		y++;
	}
}

void	ft_allocpoints(t_map *map)
{
	int y;

	if (!(map->points = malloc(sizeof(t_vector3d *) * map->height)))
		ft_exit("Could not allocate enough memory");
	y = 0;
	while (y < map->height)
		if (!(map->points[y++] = malloc(sizeof(t_vector3d) * map->width)))
			ft_exit("Could not allocate enough memory");
}

void	ft_draw_map(t_map *map)
{
	t_vector3d	current;
	int			y;
	int			x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			current = map->points[y][x];
			if (x < (map->width - 1))
				ft_draw_line_gradient(map->image, current,
						map->points[y][x + 1],
						map->data[y][x].color, map->data[y][x + 1].color);
			if (y < (map->height - 1))
				ft_draw_line_gradient(map->image, current,
						map->points[y + 1][x],
						map->data[y][x].color, map->data[y + 1][x].color);
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
			fdf->menu->enabled ? WIN_WIDTH - MENU_WIDTH : WIN_WIDTH, WIN_HEIGHT);
	fdf->map->rotating = ft_asvector3d(fdf->map->image->width / 2,
			fdf->map->image->height / 2,
			1000 + (fdf->map->maxheight - fdf->map->minheight) * fdf->map->heightmult * fdf->map->zoom / 2);
	fdf->map->eye = ft_asvector3d(fdf->map->image->width / 2,
			fdf->map->image->height / 2,
			-800);
	if (fdf->map->points == NULL)
		ft_allocpoints(fdf->map);
	ft_genpoint(fdf->map, fdf->menu);
	ft_draw_map(fdf->map);
	if (fdf->menu->enabled)
		ft_put_menu(fdf, fdf->menu);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
			fdf->map->image->img_ptr, fdf->menu->enabled ? MENU_WIDTH : 0, 0);
}
