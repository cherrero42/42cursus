/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:14:31 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/02 12:44:39 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// atoi() function converts the initial portion of the string pointed
//   to by str to int representation.
// string to integer

#include "libft.h"

static int	ft_is_tab(char st)
{
	int	flag;

	flag = 0;
	if (st == ' ' || st == '\n' || st == '\t' || st == '\v')
		flag = 1;
	if (flag == 0 && (st == '\f' || st == '\r'))
		flag = 1;
	return (flag);
}

int	ft_atoi(const char *str)
{
	int	rst;
	int	iter;
	int	neg;

	rst = 0;
	iter = 0;
	neg = 1;
	while (ft_is_tab(str[iter]))
	{
		iter++;
	}
	if ((str[iter] == '-') || (str[iter] == '+'))
	{
		if (str[iter] == '-')
			neg = -1;
		iter++;
	}
	while (str[iter] >= '0' && str[iter] <= '9')
	{
		rst = (rst * 10) + str[iter] - '0';
		iter++;
	}
	return (rst * neg);
}

/*
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>

int main (void)
{
	printf("%i\n", atoi("-2344225"));
	printf("%i\n", ft_atoi("-2344225"));
}*/