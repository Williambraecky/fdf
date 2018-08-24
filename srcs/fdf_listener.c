/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:55:31 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/24 16:06:02 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*
** TEMPORARY
*/

void	ft_handle_r_press(int button, int x, int y, t_fdf *fdf)
{
	(void)button;
	x -= 301;
	y -= 619;
	if (!fdf->menu->enabled || x >= 25 || y >= 255 || x < 0 || y < 0)
		return ;
	fdf->menu->red = y;
	ft_put_rgb_selector(fdf->menu);
	ft_put_menu(fdf, fdf->menu);
}

void	ft_handle_rgb_press(int button, int x, int y, t_fdf *fdf)
{
	(void)button;
	x -= 25;
	y -= 619;
	if (!fdf->menu->enabled || x >= 255 || y >= 255 || x < 0 || y < 0)
		return ;
	if (button == 1)
		fdf->menu->start_color = ft_rgb_to_color(fdf->menu->red, x, y);
	else if (button == 2)
		fdf->menu->end_color = ft_rgb_to_color(fdf->menu->red, x, y);
	else
		return ;
	ft_put_rgb_target(fdf->menu);
	ft_render(fdf);
}

int		ft_handle_mousepress(int button, int x, int y, t_fdf *fdf)
{
	(void)fdf;
	printf("Pressed: %d at x: %d y: %d\n", button, x, y);
	ft_handle_r_press(button, x, y, fdf);
	ft_handle_rgb_press(button, x, y, fdf);
	return (1);
}

int		ft_handle_keypress(int key, t_fdf *fdf)
{
	(void)fdf;
	printf("Pressed key:%d\n", key);
	if (key == ESC_KEY)
		exit(0);
	else if (key == M_KEY)
		fdf->menu->enabled ^= 1;
	else if (key == LEFT_KEY)
		fdf->map->y_rot -= 5;
	else if (key == RIGHT_KEY)
		fdf->map->y_rot += 5;
	else if (key == UP_KEY)
		fdf->map->x_rot += 5;
	else if (key == DOWN_KEY)
		fdf->map->x_rot -= 5;
	else if (key == PL_KEY)
		fdf->map->zoom += 2;
	else if (key == MN_KEY)
		fdf->map->zoom -= 2;
	else if (key == K9_KEY)
		fdf->map->heightmult--;
	else if (key == K0_KEY)
		fdf->map->heightmult++;
	ft_render(fdf);
	return (1);
}
