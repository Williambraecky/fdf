/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:46:35 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/22 18:47:23 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisnumber(char *str)
{
	if (*str == '-' && *(str + 1) != '\0')
		str++;
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}
