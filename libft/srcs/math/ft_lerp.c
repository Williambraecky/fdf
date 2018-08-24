/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lerp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 16:43:42 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/24 16:44:25 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_lerp(float start, float end, float percent)
{
	if (percent == 0.00)
		return (start);
	else if (percent == 1.00)
		return (end);
	return (start + (end - start) * percent);
}
