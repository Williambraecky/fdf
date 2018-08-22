/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:55:31 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/22 19:50:06 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		ft_handle_mousepress(int button, int x, int y, t_fdf *fdf)
{
	(void)fdf;
	printf("Pressed: %d at x: %d y: %d\n", button, x, y);
	return (1);
}

int		ft_handle_keypress(int key, t_fdf *fdf)
{
	(void)fdf;
	printf("Pressed key:%d\n", key);
	if (key == ESC_KEY)
		exit(0);
	else if (key == M_KEY)
		fdf->menu_enabled ^= 1;
	else if (key == LEFT_KEY)
		fdf->map->y_rot -= 5;
	else if (key == RIGHT_KEY)
		fdf->map->y_rot += 5;
	else if (key == UP_KEY)
		fdf->map->x_rot += 5;
	else if (key == DOWN_KEY)
		fdf->map->x_rot -= 5;
	else if (key == PL_KEY)
		fdf->map->zoom += 2;
	else if (key == MN_KEY)
		fdf->map->zoom -= 2;
	else if (key == K9_KEY)
		fdf->map->heightmult--;
	else if (key == K0_KEY)
		fdf->map->heightmult++;
	ft_render(fdf);
	return (1);
}
