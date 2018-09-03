/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 22:13:43 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/03 14:40:21 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_todegrees(float rad)
{
	return (rad * 180 / M_PI);
}

float	ft_toradians(float degree)
{
	return (degree * M_PI / 180);
}

void	ft_vec3d_add(t_vector3d *vec, float x, float y, float z)
{
	vec->x += x;
	vec->y += y;
	vec->z += z;
}

int		ft_isinpov(t_vector3d p)
{
	return (p.z > 0);
}
