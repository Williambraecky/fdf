/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_allocations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:36:14 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/02 01:55:29 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_control	*ft_new_control(void)
{
	t_control	*control;

	if (!(control = ft_memalloc(sizeof(t_control))))
		return (NULL);
	return (control);
}

t_menu		*ft_new_menu(t_fdf *fdf)
{
	t_menu	*menu;

	if (!(menu = malloc(sizeof(t_menu))))
		return (NULL);
	menu->img = ft_new_image(fdf, MENU_WIDTH, WIN_HEIGHT);
	menu->enabled = 1;
	menu->red = 0;
	menu->start_color = ft_int_to_color(COLOR_WHITE);
	menu->end_color = ft_int_to_color(COLOR_RED);
	return (menu);
}

t_image		*ft_new_image(t_fdf *fdf, int width, int height)
{
	t_image		*img;

	if (!(img = malloc(sizeof(t_image))))
		return (NULL);
	img->img_ptr = mlx_new_image(fdf->mlx_ptr, width, height);
	if (img->img_ptr == NULL)
		ft_exit("Could not allocate enough memory");
	img->data = mlx_get_data_addr(img->img_ptr,
			&(img->bpp), &(img->size_line), &(img->endian));
	if (!(img->points = malloc(sizeof(int) * (width * height))))
		ft_exit("Could not allocate enough memory");
	img->bpp /= 8;
	img->width = width;
	img->height = height;
	return (img);
}

t_fdf		*ft_new_fdf(void)
{
	t_fdf	*fdf;

	if (!(fdf = malloc(sizeof(t_fdf))))
		return (NULL);
	if (!(fdf->controls = ft_new_control()))
		ft_exit("Could not alloacte enough memory");
	return (fdf);
}

t_map		*ft_new_map(void)
{
	t_map	*map;

	if (!(map = malloc(sizeof(t_map))))
		return (NULL);
	map->renderer = &ft_draw_map;
	map->points = NULL;
	map->image = NULL;
	map->maxheight = 0;
	map->heightmult = 1;
	map->zoom = 16;
	map->width = -1;
	map->height = -1;
	map->x_rot = 10;
	map->y_rot = 10;
	map->x_off = 0;
	map->y_off = 0;
	return (map);
}
