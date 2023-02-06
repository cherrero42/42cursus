/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:22:14 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/08 11:27:19 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// compares byte string s1 against byte string s2.
// Both strings are assumed to be n bytes long
// returns zero if the two strings are identical, 
// otherwise returns the difference
// between the first two differing bytes

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*b1;
	unsigned char	*b2;
	size_t			i;

	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (b1[i] != b2[i])
			return (b1[i] - b2[i]);
		i++;
	}
	return (0);
}
