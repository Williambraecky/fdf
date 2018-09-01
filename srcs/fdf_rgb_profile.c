/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rgb_profile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 17:34:58 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/01 17:36:25 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_col_p		ft_colors_to_p(t_color start, t_color end)
{
	t_col_p	col_p;

	col_p.start = start;
	col_p.end = end;
	return (col_p);
}

t_color		ft_col_p_lerp(t_col_p col_p, float percent)
{
	return (ft_color_lerp(col_p.start, col_p.end, percent));
}
