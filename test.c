/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 03:00:04 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/26 03:04:58 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

float	ft_rad_to_deg(float rad)
{
	return (rad * 180 / M_PI);
}

int main(int argc, const char *argv[])
{
	printf("%f\n", ft_rad_to_deg(ft_get_anglez(ft_asvector3d(0, 10, 10), ft_asvector3d(10, 20, 20))));
	return 0;
}
