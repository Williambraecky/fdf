/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:13:37 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/01 17:41:10 by wbraeckm         ###   ########.fr       */
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
# define MENU_WIDTH 400
# define MENU_COLOR 0x25292E
# define TEXT_COLOR 0x52B7BA
# define BORDER_COLOR 0xC8C9CB
# define TRANSPARENT -16777216
# define COLOR_RED 0xFF0000
# define COLOR_WHITE 0xFFFFFF

typedef struct s_color	t_color;
struct			s_color
{
	int			r;
	int			g;
	int			b;
};

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

typedef struct s_point	t_point;
struct			s_point
{
	int			height;
	int			forced_color;
	t_color		color;
};

typedef struct s_col_p	t_col_p;
struct			s_col_p
{
	t_color		start;
	t_color		end;
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
	t_point		**data;
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
	float		x_off;
	float		y_rot;
	float		y_off;
};

typedef struct s_menu	t_menu;
struct			s_menu
{
	int			enabled;
	int			red;
	t_color		start_color;
	t_color		end_color;
	t_image		*img;
};

typedef struct s_control	t_control;
struct			s_control
{
	int			mouse;
	int			inside_menu;
	int			last_x;
	int			x;
	int			last_y;
	int			y;
};

typedef struct s_xpm	t_xpm;
struct			s_xpm
{
	void		*xpm_ptr;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			width;
	int			height;
};

typedef struct s_fdf	t_fdf;
struct			s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
	t_menu		*menu;
	t_control	*controls;
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
float			ft_get_anglez(t_vector3d from, t_vector3d to);
float			ft_get_angley(t_vector3d from, t_vector3d to);

/*
** Utilitaries
*/

void			ft_exit(char *str);
t_fdf			*ft_new_fdf(void);
t_map			*ft_new_map(void);
t_image			*ft_new_image(t_fdf *fdf, int width, int height);
void			ft_destroy_image(t_fdf *fdf, t_image *image);
t_menu			*ft_new_menu(t_fdf *fdf);
t_control		*ft_new_control(void);
t_vector2d		ft_asvector2d(float x, float y);
t_vector3d		ft_asvector3d(float x, float y, float z);

/*
** Parsing
*/

t_fdf			*ft_read_file(char *file);
int				ft_point_is_valid(char *str);
t_point			ft_read_point(char *str);

/*
** Listeners
*/

int				ft_handle_keypress(int key, t_fdf *fdf);
int				ft_handle_button_movement(int x, int y, t_fdf *fdf);
int				ft_handle_mouseclicks(int button, int x, int y, t_fdf *fdf);

/*
** Drawing
*/

void			ft_img_put_pixel(t_image *image, int x, int y, int color);
void			ft_draw_square(t_image *image, t_vector2d start, t_vector2d end,
		int color);
void			ft_draw_line(t_image *image, t_vector2d first,
		t_vector2d second, int color);
void			ft_draw_edges(t_image *image, t_vector2d start, t_vector2d end,
		int color);
void			ft_draw_line_gradient(t_image *image, t_vector3d first,
		t_vector3d second, t_col_p col_p);

/*
** Color
*/

int				ft_rgb_to_int(int r, int g, int b);
int				ft_color_to_int(t_color color);
t_color			ft_rgb_to_color(int r, int g, int b);
t_color			ft_int_to_color(int rgb);
t_color			ft_color_lerp(t_color start, t_color end, float percent);
t_col_p			ft_colors_to_p(t_color start, t_color end);
t_color			ft_col_p_lerp(t_col_p col_p, float percent);

/*
** Menu
*/

void			ft_init_menu(t_fdf *fdf);
void			ft_put_rgb_selector(t_menu *menu);
void			ft_put_menu(t_fdf *fdf, t_menu *menu);
void			ft_put_rgb_target(t_menu *menu);

/*
** Xpm utils
*/

void			ft_put_xpm_file_to_image(t_fdf *fdf, char *file, t_image *image,
		t_vector2d pos);

#endif
