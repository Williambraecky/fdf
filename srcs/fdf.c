/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:18:46 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/22 18:55:18 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	ft_init_listeners(t_fdf *fdf)
{
	mlx_key_hook(fdf->win_ptr, ft_handle_keypress, fdf);
	mlx_mouse_hook(fdf->win_ptr, ft_handle_mousepress, fdf);
}

static void	ft_init_menu(t_fdf *fdf)
{
	if (!(fdf->menu = ft_new_image(fdf, MENU_WIDTH, WIN_HEIGHT)))
		ft_exit("Could not allocate enough memory");
	ft_draw_square(fdf->menu, ft_asvector2d(0, 0),
			ft_asvector2d(MENU_WIDTH, WIN_HEIGHT), MENU_COLOR);
	ft_draw_square(fdf->menu, ft_asvector2d(MENU_WIDTH - 3, 0),
			ft_asvector2d(MENU_WIDTH, WIN_HEIGHT), BORDER_COLOR);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
			fdf->menu->img_ptr, 0, 0);
}

int			main(int argc, char *argv[])
{
	t_fdf	*fdf;
	char	*str;

	if (argc == 0)
		ft_exit("Not enough arguments");
	fdf = ft_read_file(argv[1]);
	fdf->mlx_ptr = mlx_init();
	if (fdf->mlx_ptr == NULL)
		ft_exit("Could not initialize mlx");
	str = ft_strjoin("Fdf: ", argv[1]);
	if (str == NULL)
		ft_exit("Could not open window");
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, str);
	free(str);
	if (fdf->win_ptr == NULL)
		ft_exit("Could not open window");
	ft_init_listeners(fdf);
	ft_init_menu(fdf);
	ft_render(fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}