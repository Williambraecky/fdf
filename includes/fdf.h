/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:13:37 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/14 16:18:10 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"

typedef struct s_vector2d	t_vector2d;
struct	s_vector2d
{
	int x;
	int y;
};

typedef struct s_vector3d	t_vector3d;
struct	s_vector3d
{
	int x;
	int y;
	int z;
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

#endif
