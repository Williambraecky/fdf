/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_advanced.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 22:33:46 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/03 14:41:34 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_map_put_pixel(t_image *image, t_vector3d p, int color)
{
	int x;
	int y;
	int z;

	x = round(p.x);
	y = round(p.y);
	z = round(p.z);
	if (x < 0 || x >= image->width || y < 0 || y >= image->height)
		return ;
	if (*(int *)(image->data + (y * image->width + x) * image->bpp) != 0)
		if (image->points[y * image->width + x] < z)
			return ;
	image->points[y * image->width + x] = z;
	*(int *)(image->data + (y * image->width + x) * image->bpp) = color;
}

int		ft_should_draw_line(t_image *image, t_vector3d f, t_vector3d s)
{
	if ((f.x < 0 && s.x < 0) ||
			(f.x >= image->width && s.x >= image->width) ||
		(f.y < 0 && s.y < 0) ||
			(f.y >= image->height && s.y >= image->height))
		return (0);
	return (1);
}

void	ft_draw_line_gradient_pov(t_image *image, t_vector3d first,
		t_vector3d second, t_col_p col_p)
{
	t_vector3d	d;
	float		step;
	int			i;

	if (!ft_should_draw_line(image, first, second)
			|| (!ft_isinpov(first) && !ft_isinpov(second)))
		return ;
	d.x = (second.x - first.x);
	d.y = (second.y - first.y);
	if (fabsf(d.x) >= fabsf(d.y))
		step = fabsf(d.x);
	else
		step = fabsf(d.y);
	d.x = d.x / step;
	d.y = d.y / step;
	d.z = (second.z - first.z) / step;
	i = -1;
	while (++i <= step)
	{
		if (ft_isinpov(first))
			ft_map_put_pixel(image, first,
				ft_color_to_int(ft_col_p_lerp(col_p, (float)i / step)));
		ft_vec3d_add(&first, d.x, d.y, d.z);
	}
}
