/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:21:03 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/01 18:55:54 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// locates the first occurrence of c (converted to unsigned char) in string s

// revisar CP

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tab;
	unsigned char	ret;

	ret = (unsigned char)c;
	tab = (unsigned char *)s;
	while (n > 0)
	{
		if (*tab == ret)
		{
			return (tab);
		}
		tab++;
		n--;
	}
	return (NULL);
}
