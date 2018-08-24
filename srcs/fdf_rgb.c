/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 14:32:08 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/24 15:58:58 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_rgb_to_int(int r, int g, int b)
{
	int rgb;

	rgb = 0;
	rgb |= r << 16;
	rgb |= g << 8;
	rgb |= b;
	return (rgb);
}

int		ft_color_to_int(t_color color)
{
	int rgb;

	rgb = 0;
	rgb |= color.r << 16;
	rgb |= color.g << 8;
	rgb |= color.b;
	return (rgb);
}

t_color	ft_rgb_to_color(int r, int g, int b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color	ft_int_to_color(int rgb)
{
	t_color color;

	color.r = rgb >> 16 & 0xFF;
	color.g = rgb >> 8 & 0xFF;
	color.b = rgb & 0xFF;
	return (color);
}

t_color	ft_color_lerp(t_color start, t_color end, float percent)
{
	t_color color;

	color.r = start.r + (float)(end.r - start.r) * percent;
	color.g = start.g + (float)(end.g - start.g) * percent;
	color.b = start.b + (float)(end.b - start.b) * percent;
	return (color);
}
