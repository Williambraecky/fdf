/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:03:58 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/22 18:57:59 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_img_put_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= image->width || y < 0 || y >= image->height)
		return ;
	*(int *)(image->data + (y * image->width + x) * image->bpp) = color;
}

void	ft_draw_square(t_image *image, t_vector2d start, t_vector2d end,
		int color)
{
	int x;
	int y;

	y = start.y;
	while (y <= end.y)
	{
		x = start.x;
		while (x <= end.x)
		{
			ft_img_put_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_draw_line(t_image *image, t_vector2d first, t_vector2d second,
		int color)
{
	float	dx;
	float	dy;
	float	step;
	int		i;

	dx = (second.x - first.x);
	dy = (second.y - first.y);
	if (fabsf(dx) >= fabsf(dy))
		step = fabsf(dx);
	else
		step = fabsf(dy);
	dx = dx / step;
	dy = dy / step;
	i = 0;
	while (i <= step) {
		ft_img_put_pixel(image, round(first.x), round(first.y), color);
		first.x += dx;
		first.y += dy;
		i++;
	}
}
