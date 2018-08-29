/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:03:58 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/29 11:49:34 by wbraeckm         ###   ########.fr       */
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

void	ft_draw_edges(t_image *image, t_vector2d start, t_vector2d end,
		int color)
{
	ft_draw_line(image, start, ft_asvector2d(end.x, start.y), color);
	ft_draw_line(image, start, ft_asvector2d(start.x, end.y), color);
	ft_draw_line(image, ft_asvector2d(start.x, end.y), end, color);
	ft_draw_line(image, ft_asvector2d(end.x, start.y), end, color);
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

	if ((first.x < 0 && second.x < 0) ||
			(first.x >= image->width && second.x >= image->width) ||
		(first.y < 0 && second.y < 0) ||
			(first.y >= image->height && second.y >= image->height))
		return ;
	dx = (second.x - first.x);
	dy = (second.y - first.y);
	if (fabsf(dx) >= fabsf(dy))
		step = fabsf(dx);
	else
		step = fabsf(dy);
	dx = dx / step;
	dy = dy / step;
	i = 0;
	while (i++ <= step)
	{
		ft_img_put_pixel(image, round(first.x), round(first.y), color);
		first.x += dx;
		first.y += dy;
	}
}

void	ft_draw_line_gradient(t_image *image, t_vector3d first, t_vector3d second,
		t_color start, t_color end)
{
	t_vector3d	d;
	float	step;
	int		i;

	if ((first.x < 0 && second.x < 0) ||
			(first.x >= image->width && second.x >= image->width) ||
		(first.y < 0 && second.y < 0) ||
			(first.y >= image->height && second.y >= image->height))
		return ;
	d.x = (second.x - first.x);
	d.y = (second.y - first.y);
	if (fabsf(d.x) >= fabsf(d.y))
		step = fabsf(d.x);
	else
		step = fabsf(d.y);
	d.x = d.x / step;
	d.y = d.y / step;
	i = 0;
	while (i++ <= step)
	{
		ft_img_put_pixel(image, round(first.x), round(first.y),
				ft_color_to_int(ft_color_lerp(start, end, (float)i/step)));
		first.x += d.x;
		first.y += d.y;
	}
}
