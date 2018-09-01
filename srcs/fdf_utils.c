/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:25:32 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/01 15:44:51 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector2d	ft_asvector2d(float x, float y)
{
	t_vector2d res;

	res.x = x;
	res.y = y;
	return (res);
}

t_vector3d	ft_asvector3d(float x, float y, float z)
{
	t_vector3d res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

float		ft_get_anglez(t_vector3d from, t_vector3d to)
{
	return (atan((to.z - from.z) / (to.x - from.x)));
}

float		ft_get_angley(t_vector3d from, t_vector3d to)
{
	return (atan((to.z - from.z) / (to.x - from.x)));
}

void		ft_destroy_image(t_fdf *fdf, t_image *image)
{
	image->width = 0;
	image->height = 0;
	mlx_destroy_image(fdf->mlx_ptr, image->img_ptr);
	free(image);
}
