/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 11:24:59 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/02 01:33:01 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_point_is_valid(char *str)
{
	if (*str == '-' && ft_isdigit(*(str + 1)))
		str++;
	while (ft_isdigit(*str))
		str++;
	if (!*str)
		return (1);
	if (!ft_strstartswith(str, ",0x"))
		return (0);
	str += 3;
	if (ft_strlen(str) > 6)
		return (0);
	while (*str && ft_strchr("0123456789ABCDEF", ft_toupper(*str)))
		str++;
	return (*str == '\0');
}

int		ft_ctoi(char c)
{
	char	*base;
	int		i;

	base = "0123456789ABCDEF";
	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

t_point	ft_read_point(char *str)
{
	t_point	point;
	int		color;
	int		i;

	point.height = ft_atoi(str);
	point.forced_color = 0;
	if (*str == '-' && ft_isdigit(*(str + 1)))
		str++;
	while (ft_isdigit(*str))
		str++;
	if (!*str)
		return (point);
	str += 3;
	point.forced_color = 1;
	color = 0;
	i = 6;
	while (i--)
	{
		color = color * 16;
		if (*str)
			color += ft_ctoi(ft_toupper(*str++));
	}
	point.color = ft_int_to_color(color);
	return (point);
}
