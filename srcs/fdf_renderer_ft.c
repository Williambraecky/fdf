/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_renderer_ft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:36:02 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/03 15:36:56 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
							map->data[y][x + 1].color));
			if (y < (map->height - 1))
				ft_draw_line_gradient_pov(map->image, current,
						ft_to2dvector(map->points[y + 1][x], map->eye),
						ft_colors_to_p(map->data[y][x].color,
							map->data[y + 1][x].color));
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
