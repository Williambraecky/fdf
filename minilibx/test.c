/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:32:28 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/16 18:06:47 by wbraeckm         ###   ########.fr       */
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

t_vector2d ft_rotate_vector(t_vector2d p, float angle, t_vector2d around);

float	angle;

int	ft_mousepress(int button, int x, int y, t_test *test)
{
	void *addr = test->mlx_ptr;
	void *window = test->window;
	mlx_clear_window(addr, window);
	int midx = 1280 / 2;
	int midy = 720 / 2;
	t_vector2d mid = {midx, midy};
	t_vector2d a = {midx - 100, midy};
	t_vector2d b = {midx, midy - 100};
	t_vector2d c = {midx + 100, midy};
	t_vector2d d = {midx, midy + 100};
	angle++;
	a = ft_rotate_vector(a, angle, mid);
	b = ft_rotate_vector(b, angle, mid);
	c = ft_rotate_vector(c, angle, mid);
	d = ft_rotate_vector(d, angle, mid);
	ft_draw_line(addr, window, a, b);
	ft_draw_line(addr, window, b, c);
	ft_draw_line(addr, window, c, d);
	ft_draw_line(addr, window, d, a);
	printf("Click: %d, x:%d, y:%d\n", button, x, y);
	/*if (button == 2)
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
	test->secondclick.x = 0;*/
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

double	ft_toradians(double angle)
{
	return (angle * M_PI / 180.0);
}

t_vector2d ft_rotate_vector(t_vector2d point, float angle, t_vector2d around)
{
	float s = sin(ft_toradians(angle));
	float c = cos(ft_toradians(angle));
	float x = (float)(point.x - around.x);
	float y = (float)(point.y - around.y);
	t_vector2d result;

	printf("Rotating x:%d y:%d by angle:%f, sin:%f, cos:%f\n", (int)x, (int)y, angle, s, c);

	result.x = round(x * c - y * s + around.x);
	result.y = round(y * c + x * s + around.y);
	printf("Result x:%d %f   y:%d %f  \n\n", (int)x, x, (int)y, y);
	return (result);
}

t_vector2d ft_new_vector(int x, int y)
{
	t_vector2d result = {x, y};
	return (result);
}

int main(int argc, const char *argv[])
{
	void *addr = mlx_init();
	void *window = mlx_new_window(addr, 1280, 720, "Testing");
	t_test *test = malloc(sizeof(t_test));
	if (!test)
		return 0;
	printf("%f %f\n", ft_toradians(45), sin(ft_toradians(45)));
	test->mlx_ptr = addr;
	test->window = window;
	test->firstclick.x = 0;
	test->secondclick.x = 0;
	int bits_per_pixel, size_line, endian;
	int midx = 1280 / 2;
	int midy = 720 / 2;
	t_vector2d mid = {midx, midy};
	t_vector2d a = {midx - 100, midy};
	t_vector2d b = {midx, midy - 100};
	t_vector2d c = {midx + 100, midy};
	t_vector2d d = {midx, midy + 100};
	angle = atoi(argv[1]);
	a = ft_rotate_vector(a, angle, mid);
	b = ft_rotate_vector(b, angle, mid);
	c = ft_rotate_vector(c, angle, mid);
	d = ft_rotate_vector(d, angle, mid);
	ft_draw_line(addr, window, a, b);
	ft_draw_line(addr, window, b, c);
	ft_draw_line(addr, window, c, d);
	ft_draw_line(addr, window, d, a);
	mlx_mouse_hook(window, ft_mousepress, test);
	mlx_key_hook(window, ft_keypress, addr);
	mlx_loop(addr);
	return 0;
}
