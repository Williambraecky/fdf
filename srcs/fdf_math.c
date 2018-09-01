/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:20:42 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/02 00:06:29 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector3d	ft_rotateaccordingly(t_vector3d vec, float trigo[],
		t_vector3d around)
{
	t_vector3d	result;
	float		x;
	float		y;
	float		z;

	y = vec.y - around.y;
	z = vec.z - around.z;
	result.y = y * trigo[COSX] - z * trigo[SINX] + around.y;
	result.z = z * trigo[COSX] + y * trigo[SINX] + around.z;
	x = vec.x - around.x;
	z = result.z - around.z;
	result.x = x * trigo[COSY] - z * trigo[SINY] + around.x;
	result.z = z * trigo[COSY] + x * trigo[SINY] + around.z;
	return (result);
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

t_vector3d	ft_to2dvector(t_vector3d p, t_vector3d eye)
{
	t_vector3d result;

	result.x = (eye.z * (p.x - eye.x)) / (eye.z + p.z) + eye.x;
	result.y = (eye.z * (p.y - eye.y)) / (eye.z + p.z) + eye.y;
	result.z = p.z;
	return (result);
}
