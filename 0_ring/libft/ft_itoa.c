/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:55:12 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/03 19:58:27 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int to string

#include "libft.h"

// return length (num of chars) of an integer

static int	ft_nbrlen(int n)
{
	int	length;

	length = 0;
	if (n < 0)
		length++;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

// add char c to the end of string st
// static char	*ft_addchr(char *st, char c)
// {
// 	char	*st_aux;

// 	ft_strcpy(st_aux, st);
//     st_aux[ft_strlen(st) + 0] = c;
//     st_aux[ft_strlen(st) + 1] = '\0';
//     return (st_aux);    
// }

char	*ft_itoa(int n)
{
	char	*str;
	int		length;

	length = ft_nbrlen(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *) malloc (sizeof(char) * (length + 1));
	if (!str)
		return (0);
	str[length--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		str[length--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

//int main(void)
//{
//    puts((char*)ft_itoa(87654));
//}