/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:22:14 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/01 17:59:56 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// strlcat() functions concatenate strings with the same input parameters

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	length_src;
	size_t	length_dst;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	length_dst = i;
	length_src = ft_strlen(src);
	if (dstsize == 0 || dstsize <= i)
		return (length_src + dstsize);
	while (src[j] && j < dstsize - length_dst - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (length_dst + length_src);
}
