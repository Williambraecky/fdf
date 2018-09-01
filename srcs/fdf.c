/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:18:46 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/01 14:56:01 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_listeners(t_fdf *fdf)
{
	mlx_key_hook(fdf->win_ptr, ft_handle_keypress, fdf);
	mlx_mouse_hook(fdf->win_ptr, ft_handle_mouseclicks, fdf);
	mlx_hook(fdf->win_ptr, BUTTONRELEASE, 0, ft_handle_mouseclicks, fdf);
	mlx_hook(fdf->win_ptr, MOTIONNOTIFY, BUTTON1MOTIONMASK,
			ft_handle_button_movement, fdf);
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
