/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_corrupt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:14:39 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/04 17:43:30 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <time.h>

void	ft_corrupt_menu(t_fdf *fdf)
{
	ft_put_xpm_file_to_image(fdf, "wbraeckm_logo_deepfried.xpm",
			fdf->menu->img, ft_asvector2d(25, 25));
}

void	ft_corrupt_map(t_map *map)
{
	int y;
	int x;

	y = 0;
	map->maxheight = 0;
	map->minheight = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->data[y][x].height = rand() % 100;
			map->maxheight = ft_max(map->data[y][x].height, map->maxheight);
			map->minheight = ft_min(map->data[y][x].height, map->minheight);
			map->data[y][x].forced_color = rand() % 2;
			if (map->data[y][x].forced_color)
				map->data[y][x].color =
					ft_int_to_color(rand() * rand() * rand());
			x++;
		}
		y++;
	}
	map->offsetx = (float)(map->width - 1) / 2.0;
	map->offsety = (float)(map->height - 1) / 2.0;
}

void	ft_corrupt(t_fdf *fdf)
{
	if (fdf->menu->corrupted)
		return ;
	fdf->menu->corrupted = 1;
	srand(time(NULL));
	ft_corrupt_map(fdf->map);
	ft_corrupt_menu(fdf);
	ft_render(fdf);
}

void	ft_handle_corruption(int x, int y, t_fdf *fdf)
{
	x -= 25;
	y -= 25;
	if ((x < 0 || x > 180 || y < 0 || y > 180)
			|| !(fdf->controls->mouse & (1L << BUT1_KEY)))
		return ;
	ft_corrupt(fdf);
}
