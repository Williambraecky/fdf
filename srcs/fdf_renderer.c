/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:45:22 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/02 00:11:10 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_genpoint(t_map *map, t_menu *menu)
{
	int		y;
	int		x;
	float	trigo[4];

	trigo[SINX] = sin(ft_toradians(map->x_rot));
	trigo[COSX] = cos(ft_toradians(map->x_rot));
	trigo[SINY] = sin(ft_toradians(map->y_rot));
	trigo[COSY] = cos(ft_toradians(map->y_rot));
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->points[y][x] = ft_asvector3d(
					(x - map->offsetx) * map->zoom + map->image->width / 2 + map->x_off,
					(y - map->offsety) * map->zoom + map->image->height / 2 + map->y_off,
					1000 + -(map->data[y][x].height * map->heightmult * map->zoom));
			map->points[y][x] = ft_rotateaccordingly(map->points[y][x], trigo, map->rotating);
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
	int			y;
	int			x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < (map->width - 1))
				ft_draw_line_gradient(map->image, map->points[y][x],
						map->points[y][x + 1],
						ft_colors_to_p(map->data[y][x].color,
							map->data[y][x + 1].color));
			if (y < (map->height - 1))
				ft_draw_line_gradient(map->image, map->points[y][x],
						map->points[y + 1][x],
						ft_colors_to_p(map->data[y][x].color,
							map->data[y + 1][x].color));
			x++;
		}
		y++;
	}
}

void	ft_draw_map_pov(t_map *map)
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
			current = ft_to2dvector(map->points[y][x], map->eye);
			if (x < (map->width - 1))
				ft_draw_line_gradient_pov(map->image, current,
						ft_to2dvector(map->points[y][x + 1], map->eye),
						ft_colors_to_p(map->data[y][x].color,
							map->data[y][x + 1].color), map->eye);
			if (y < (map->height - 1))
				ft_draw_line_gradient_pov(map->image, current,
						ft_to2dvector(map->points[y + 1][x], map->eye),
						ft_colors_to_p(map->data[y][x].color,
							map->data[y + 1][x].color), map->eye);
			x++;
		}
		y++;
	}
}

void	ft_point_map(t_map *map)
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
			ft_map_put_pixel(map->image, current,
					ft_color_to_int(map->data[y][x].color));
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
	fdf->map->rotating = ft_asvector3d(fdf->map->image->width / 2 + fdf->map->x_off,
			fdf->map->image->height / 2 + fdf->map->y_off,
			1000 + -((fdf->map->maxheight - fdf->map->minheight) * fdf->map->heightmult * fdf->map->zoom / 2));
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
