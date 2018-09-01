/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 22:13:43 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/02 00:05:25 by wbraeckm         ###   ########.fr       */
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

float		ft_get_anglez(t_vector3d from, t_vector3d to)
{
	return (atan2((to.x - from.x), (to.z - from.z)));
}

float		ft_get_angley(t_vector3d from, t_vector3d to)
{
	return (atan2((to.y - from.y), (to.z - from.z)));
}

int			ft_isinpov(t_vector3d p, t_vector3d eye)
{
	(void)eye;
	if (p.z < 0)
		return (0);
	return (1);
}
