/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:32:28 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/14 15:03:46 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "stdlib.h"
#include <stdio.h>
#include <math.h>

typedef struct s_vector2d t_vector2d;
struct s_vector2d
{
	int x;
	int y;
};

typedef struct s_test	t_test;
struct s_test
{
	void *mlx_ptr;
	void *window;
	t_vector2d firstclick;
	t_vector2d secondclick;
};

void ft_draw_line(void *mlx, void *window, t_vector2d first, t_vector2d second)
{
	float	dx;
	float	dy;
	float	step;
	float	x;
	float	y;
	int		i;

	dx = ((float)second.x - (float)first.x);
	dy = ((float)second.y - (float)first.y);
	if(fabsf(dx) >= fabsf(dy))
		step = fabsf(dx);
	else
		step = fabsf(dy);
	dx = dx / step;
	dy = dy / step;
	x = (float)first.x;
	y = (float)first.y;
	i = 1;
	while(i <= step) {
		mlx_pixel_put(mlx, window, x, y, 16711680);
		x = x + dx;
		y = y + dy;
		i = i + 1;
	}
}

void ft_fill_window(void *mlx, void *window, t_vector2d first, t_vector2d second)
{
	int y = first.y;
	while (first.x < second.x)
	{
		first.y = y;
		while (first.y < second.y)
		{
			mlx_pixel_put(mlx, window, first.x, first.y, 16711680);
			first.y++;
		}
		first.x++;
	}
}

int	ft_mousepress(int button, int x, int y, t_test *test)
{
	printf("Click: %d, x:%d, y:%d\n", button, x, y);
	if (button == 2)
	{
		mlx_clear_window(test->mlx_ptr, test->window);
		return 1;
	}
	if (test->firstclick.x == 0)
	{
		test->firstclick.x = x;
		test->firstclick.y = y;
		return 1;
	}
	if (test->secondclick.x == 0)
	{
		test->secondclick.x = x;
		test->secondclick.y = y;
	}
	printf("test\n");
	ft_draw_line(test->mlx_ptr,
			test->window, test->firstclick, test->secondclick);
	test->firstclick.x = 0;
	test->secondclick.x = 0;
	return (1);
}

int	ft_keypress(int key, void *mlx_ptr)
{
	printf("Keypress: %d\n", key);
	if (key == 53)
		exit(0);
	return (1);
}

void	ft_pixel_image_put(void *addr, char *image, int x, int y, int size_line)
{
	image[y * size_line + x * 4] = 255;
	image[y * size_line + x * 4 + 1] = 0;
	image[y * size_line + x * 4 + 2] = 0;
	image[y * size_line + x * 4 + 3] = 0;
}

void	fill_pixel(void *addr, void *window, int x1, int y1, int x2, int y2, int color)
{
	int y = y1;
	int bits_per_pixel, size_line, endian;
	char *image = mlx_get_data_addr(window, &bits_per_pixel, &size_line, &endian);
	while (x1 < x2)
	{
		y1 = y;
		while (y1 < y2)
		{
			ft_pixel_image_put(addr, image, x1, y1, size_line);
			//mlx_pixel_put(addr, window, x1, y1, color);
			y1++;
		}
		x1++;
	}
}

int main(int argc, const char *argv[])
{
	void *addr = mlx_init();
	void *window = mlx_new_window(addr, 1280, 720, "Testing");
	void *image = mlx_new_image(addr, 128, 720);
	void *image2 = mlx_new_image(addr, 128, 720);
	t_test *test = malloc(sizeof(t_test));
	if (!test)
		return 0;
	test->mlx_ptr = addr;
	test->window = window;
	test->firstclick.x = 0;
	test->secondclick.y = 0;
	int bits_per_pixel, size_line, endian;
	mlx_mouse_hook(window, ft_mousepress, test);
	mlx_key_hook(window, ft_keypress, addr);
	mlx_string_put(addr, window, 100, 200, 16711680, "Test test test");
	fill_pixel(addr, image, 0, 0, 128, 720, 16711680);
	mlx_put_image_to_window(addr, window, image, 0, 0);
	mlx_put_image_to_window(addr, window, image2, 50, 0);
	mlx_destroy_image(addr, image);
	mlx_loop(addr);
	return 0;
}
