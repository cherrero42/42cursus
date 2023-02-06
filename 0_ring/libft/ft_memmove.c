/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:22:14 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/08 11:25:04 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// copies len bytes from string src to string dst
// returns the original value of dst

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < len)
	{
		if (dst < src)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		else
			((unsigned char *)dst)[len - i - 1]
				= ((unsigned char *)src)[len - i - 1];
		i++;
	}
	return (dst);
}
