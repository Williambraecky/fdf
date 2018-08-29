/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:25:32 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/29 11:24:43 by wbraeckm         ###   ########.fr       */
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
