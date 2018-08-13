/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:51:09 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/20 11:53:22 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

char		*ft_strrev(char *str)
{
	char	*start;
	char	*end;

	start = str;
	end = str + ft_strlen(str) - 1;
	while (start < end)
		ft_swap(start++, end--);
	return (str);
}
