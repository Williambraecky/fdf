/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:55:31 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/01 16:59:18 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		ft_handle_r_press(int x, int y, t_fdf *fdf)
{
	x -= 301;
	y -= 619;
	if (!fdf->menu->enabled || x >= 25 || y >= 255 || x < 0 || y < 0 ||
			!(fdf->controls->mouse & (1L << BUT1_KEY)) ||
			!fdf->controls->inside_menu)
		return (0);
	fdf->menu->red = y;
	ft_put_rgb_selector(fdf->menu);
	ft_put_menu(fdf, fdf->menu);
	return (0);
}

int		ft_handle_rgb_press(int x, int y, t_fdf *fdf)
{
	x -= 25;
	y -= 619;
	if (!fdf->menu->enabled || x >= 255 || y >= 255 || x < 0 || y < 0 ||
			!fdf->controls->inside_menu)
		return (0);
	if (fdf->controls->mouse & (1L << BUT1_KEY))
		fdf->menu->start_color = ft_rgb_to_color(fdf->menu->red, x, y);
	else if (fdf->controls->mouse & (1L << BUT2_KEY))
		fdf->menu->end_color = ft_rgb_to_color(fdf->menu->red, x, y);
	else
		return (0);
	ft_put_rgb_target(fdf->menu);
	ft_put_menu(fdf, fdf->menu);
	return (1);
}

int		ft_handle_button_movement(int x, int y, t_fdf *fdf)
{
	int count;
	int dx;
	int dy;

	dx = fdf->controls->last_x - x;
	dy = fdf->controls->last_y - y;
	fdf->controls->last_x = x;
	fdf->controls->last_y = y;
	ft_handle_r_press(x, y, fdf);
	count = ft_handle_rgb_press(x, y, fdf) ? 1 : 0;
	if (!fdf->controls->inside_menu && fdf->controls->mouse & (1L << BUT1_KEY))
	{
		count++;
		fdf->map->x_rot += (float)dy / 5;
		fdf->map->y_rot += (float)dx / 5;
	}
	else if (!fdf->controls->inside_menu &&
			fdf->controls->mouse & (1L << BUT2_KEY) && ++count)
	{
		fdf->map->x_off += -((float)dx / 2);
		fdf->map->y_off += -((float)dy / 2);
	}
	if (count)
		ft_render(fdf);
	return (1);
}

int		ft_handle_mouseclicks(int button, int x, int y, t_fdf *fdf)
{
	int count;

	if (x < 0 || y < 0)
		return (1);
	count = 0;
	if (fdf->controls->mouse == 0)
		fdf->controls->inside_menu = fdf->menu->enabled && x < MENU_WIDTH;
	if (button == BUT1_KEY || button == BUT2_KEY || button == BUT3_KEY)
		fdf->controls->mouse ^= (1L << button);
	count += ft_handle_r_press(x, y, fdf);
	count += ft_handle_rgb_press(x, y, fdf);
	if (!fdf->controls->inside_menu && button == SCROLLDOWN_KEY && ++count)
		fdf->map->zoom = ft_max(1, fdf->map->zoom - 2);
	else if (!fdf->controls->inside_menu && button == SCROLLUP_KEY && ++count)
		fdf->map->zoom += 2;
	if (count)
		ft_render(fdf);
	return (1);
}

int		ft_handle_keypress(int key, t_fdf *fdf)
{
	if (key == ESC_KEY)
		exit(0);
	else if (key == M_KEY)
		fdf->menu->enabled ^= 1;
	else if (key == MN_KEY)
		fdf->map->heightmult--;
	else if (key == PL_KEY)
		fdf->map->heightmult++;
	ft_render(fdf);
	return (1);
}
