/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 22:19:36 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/10 22:21:05 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int main(int argc, const char *argv[])
{
	ft_putnbr(ft_intmax(10, 0,1,2,3,4,-1000,6,7,8,9));
	return 0;
}