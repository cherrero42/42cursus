/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:25:31 by cherrero          #+#    #+#             */
/*   Updated: 2022/09/21 19:53:34 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fill a byte string with a byte value
//  writes len bytes of value c (converted to an unsigned char) to the string b

#include	<stddef.h>
//#include "libft.h"

void	*ft_memset(void *b, int c, size_t len);

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*st;

	st = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		st[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/*
void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*st;

	st = (char *)str;
	i = 0;
	while (i < n)
	{
		st[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
*/

/*

#include <stdio.h>
#include <string.h>

	//while ((unsigned char*)str[i] != '\0' && i < n)


int	main(void)
{
   char str[50];
   char str2[50];

   strcpy(str,"This is string.h library function");
   puts(str);

   memset(str,'$',7);
   puts(str);

   strcpy(str2,"This is string.h library function");
   puts(str2);

   memset(str2,'$',7);
   puts(str2);
//	ft_memset
//	memset();
}
*/
