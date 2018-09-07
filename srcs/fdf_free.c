/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 15:12:24 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/07 16:56:26 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_menu(t_fdf *fdf, t_menu *menu)
{
	if (!menu)
		return ;
	if (menu->img)
		ft_destroy_image(fdf, menu->img);
	free(menu);
}

void	ft_free_map(t_fdf *fdf, t_map *map)
{
	int y;

	if (!map)
		return ;
	y = 0;
	while (y < map->height)
	{
		if (map->data && map->data[y])
			free(map->data[y]);
		if (map->points && map->points[y])
			free(map->points[y]);
		y++;
	}
	if (map->data)
		free(map->data);
	if (map->points)
		free(map->points);
	if (map->image)
		ft_destroy_image(fdf, map->image);
	free(map);
}

void	ft_free_fdf_exit(t_fdf *fdf)
{
	if (!fdf)
		return ;
	free(fdf->controls);
	ft_free_menu(fdf, fdf->menu);
	ft_free_map(fdf, fdf->map);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	free(fdf->mlx_ptr);
	free(fdf);
	while (1);
	exit(0);
}
