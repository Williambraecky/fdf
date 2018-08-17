/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:13:37 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/17 13:02:19 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <math.h>

typedef struct s_vector2d	t_vector2d;
struct	s_vector2d
{
	float x;
	float y;
};

typedef struct s_vector3d	t_vector3d;
struct	s_vector3d
{
	float x;
	float y;
	float z;
};

typedef struct s_fdf_data	t_fdf_data;
struct	s_fdf_data
{
	int randomdata;
};

typedef struct s_fdf	t_fdf;
struct	s_fdf
{
	void *mlx_ptr;
	void *win_ptr;
};

/*
** Math functions
*/

float		ft_toradians(float degree);
t_vector3d	ft_rotateZ(t_vector3d point, float angle, t_vector3d around);
t_vector3d	ft_rotateY(t_vector3d point, float angle, t_vector3d around);
t_vector3d	ft_rotateX(t_vector3d point, float angle, t_vector3d around);
t_vector2d	ft_to2dvector(t_vector3d p, t_vector3d eye);

#endif
