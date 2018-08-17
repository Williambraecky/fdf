/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:13:37 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/17 16:38:57 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <stdlib.h>
# include "keycode.h"
# include <math.h>
# include <fcntl.h>

typedef struct s_vector2d	t_vector2d;
struct			s_vector2d
{
	float		x;
	float		y;
};

typedef struct s_vector3d	t_vector3d;
struct			s_vector3d
{
	float		x;
	float		y;
	float		z;
};

typedef struct s_map	t_map;
struct			s_map
{
	int			**data;
	t_vector3d	**points;
	ssize_t		width;
	ssize_t		height;
	t_vector3d	eye;
	t_vector3d	rotating;
	float		x_rot;
	float		y_rot;
};

typedef struct s_fdf	t_fdf;
struct			s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
};

/*
** Parsing funcitons
*/

t_fdf			*ft_read_file(char *file);

/*
** Math functions
*/

float			ft_toradians(float degree);
t_vector3d		ft_rotatez(t_vector3d point, float angle, t_vector3d around);
t_vector3d		ft_rotatey(t_vector3d point, float angle, t_vector3d around);
t_vector3d		ft_rotatex(t_vector3d point, float angle, t_vector3d around);
t_vector2d		ft_to2dvector(t_vector3d p, t_vector3d eye);

/*
** Utilitaries
*/

void			ft_exit(char *str);
t_fdf			*ft_new_fdf(void);
t_map			*ft_new_map(void);

#endif
