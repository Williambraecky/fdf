/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_allocations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:36:14 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/17 16:42:10 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*ft_new_fdf(void)
{
	t_fdf	*fdf;

	if (!(fdf = malloc(sizeof(t_fdf))))
		return (NULL);
	return (fdf);
}

t_map	*ft_new_map(void)
{
	t_map	*map;

	if (!(map = malloc(sizeof(t_map))))
		return (NULL);
	map->width = -1;
	map->height = -1;
	return (map);
}
