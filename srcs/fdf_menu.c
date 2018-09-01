/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:20:14 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/01 21:38:43 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_menu(t_fdf *fdf, t_menu *menu)
{
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
			menu->img->img_ptr, 0, 0);
}

void	ft_put_rgb_target(t_menu *menu)
{
	t_color	color;
	int		y;
	int		x;

	x = 0;
	while (x < 301)
	{
		y = 0;
		while (y < 25)
		{
			color = ft_color_lerp(menu->start_color, menu->end_color,
					(float)x / 306.0);
			ft_img_put_pixel(menu->img, x + 25, y + 569,
					ft_color_to_int(color));
			y++;
		}
		x++;
	}
}

void	ft_put_rgb_selector(t_menu *menu)
{
	int	y;
	int	x;

	y = -1;
	while (++y < 256)
	{
		x = -1;
		while (++x < 256)
			ft_img_put_pixel(menu->img,
					x + 25, y + 619, ft_rgb_to_int(menu->red, x, y));
	}
	y = -1;
	while (++y < 256)
	{
		x = -1;
		while (++x < 25)
			ft_img_put_pixel(menu->img,
					x + 301, y + 619, ft_rgb_to_int(y, 0, 0));
	}
}

void	ft_init_menu(t_fdf *fdf)
{
	if (!(fdf->menu = ft_new_menu(fdf)))
		ft_exit("Could not allocate enough memory");
	ft_draw_square(fdf->menu->img, ft_asvector2d(0, 0),
			ft_asvector2d(MENU_WIDTH, WIN_HEIGHT), MENU_COLOR);
	ft_draw_square(fdf->menu->img, ft_asvector2d(MENU_WIDTH - 3, 0),
			ft_asvector2d(MENU_WIDTH, WIN_HEIGHT), BORDER_COLOR);
	ft_draw_edges(fdf->menu->img, ft_asvector2d(24, 618),
			ft_asvector2d(281, 875), BORDER_COLOR);
	ft_draw_edges(fdf->menu->img, ft_asvector2d(300, 618),
			ft_asvector2d(326, 875), BORDER_COLOR);
	ft_draw_edges(fdf->menu->img, ft_asvector2d(24, 568),
			ft_asvector2d(326, 594), BORDER_COLOR);
	ft_put_rgb_selector(fdf->menu);
	ft_put_rgb_target(fdf->menu);
	ft_put_xpm_file_to_image(fdf, "wbraeckm_logo.xpm",
			fdf->menu->img, ft_asvector2d(25, 25));
	ft_put_xpm_file_to_image(fdf, "logo19.xpm",
			fdf->menu->img, ft_asvector2d(135, 140));
	ft_put_xpm_file_to_image(fdf, "text2.xpm",
			fdf->menu->img, ft_asvector2d(25, 190));
	ft_put_menu(fdf, fdf->menu);
}
