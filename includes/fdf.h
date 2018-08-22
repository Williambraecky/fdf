/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:13:37 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/22 19:19:24 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <stdlib.h>
# include "keycode.h"
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include <stdio.h>

# define WIN_WIDTH 1600
# define WIN_HEIGHT 900
# define MENU_WIDTH 300
# define MENU_COLOR 0x25292E
# define TEXT_COLOR 0x52B7BA
# define BORDER_COLOR 0xC8C9CB
# define COLOR_RED 16711680

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

typedef struct s_image	t_image;
struct			s_image
{
	void		*img_ptr;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			width;
	int			height;
};

typedef struct s_map	t_map;
struct			s_map
{
	int			**data;
	t_vector3d	**points;
	t_image		*image;
	ssize_t		width;
	ssize_t		height;
	int			maxheight;
	int			minheight;
	float		offsetx;
	float		offsety;
	int			zoom;
	int			heightmult;
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
	int			menu_enabled;
	t_image		*menu;
};

/*
** Rendering
*/

void			ft_render(t_fdf *fdf);

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
t_image			*ft_new_image(t_fdf *fdf, int width, int height);
void			ft_destroy_image(t_fdf *fdf, t_image *image);
t_vector2d		ft_asvector2d(float x, float y);
t_vector3d		ft_asvector3d(float x, float y, float z);

/*
** Parsing
*/

t_fdf			*ft_read_file(char *file);

/*
** Listeners
*/

int				ft_handle_keypress(int key, t_fdf *fdf);
int				ft_handle_mousepress(int button, int x, int y, t_fdf *fdf);

/*
** Drawing
*/

void			ft_img_put_pixel(t_image *image, int x, int y, int color);
void			ft_draw_square(t_image *image, t_vector2d start, t_vector2d end,
		int color);
void			ft_draw_line(t_image *image, t_vector2d first,
		t_vector2d second, int color);

#endif
