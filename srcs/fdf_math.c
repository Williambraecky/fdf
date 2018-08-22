/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:20:42 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/22 19:36:50 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		ft_toradians(float degree)
{
	return (degree * M_PI / 180);
}

t_vector3d	ft_rotatez(t_vector3d point, float angle, t_vector3d around)
{
	float s;
	float c;
	float x;
	float y;

	s = sin(ft_toradians(angle));
	c = cos(ft_toradians(angle));
	x = (point.x - around.x);
	y = (point.y - around.y);
	point.x = x * c - y * s + around.x;
	point.y = y * c + x * s + around.y;
	return (point);
}

t_vector3d	ft_rotatey(t_vector3d point, float angle, t_vector3d around)
{
	float s;
	float c;
	float x;
	float z;

	s = sin(ft_toradians(angle));
	c = cos(ft_toradians(angle));
	x = (point.x - around.x);
	z = (point.z - around.z);
	point.x = x * c - z * s + around.x;
	point.z = z * c + x * s + around.z;
	return (point);
}

t_vector3d	ft_rotatex(t_vector3d point, float angle, t_vector3d around)
{
	float s;
	float c;
	float y;
	float z;

	s = sin(ft_toradians(angle));
	c = cos(ft_toradians(angle));
	y = (point.y - around.y);
	z = (point.z - around.z);
	point.y = y * c - z * s + around.y;
	point.z = z * c + y * s + around.z;
	return (point);
}

t_vector2d	ft_to2dvector(t_vector3d p, t_vector3d eye)
{
	t_vector2d result;

	result.x = (eye.z * (p.x - eye.x)) / (eye.z + p.z) + eye.x;
	result.y = (eye.z * (p.y - eye.y)) / (eye.z + p.z) + eye.y;
	return (result);
}
