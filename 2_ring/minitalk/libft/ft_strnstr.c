/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:22:14 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/08 11:17:30 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// Locates the first occurrence of the null-terminated string needle in 
/// the string haystack, where not more than len characters are searched.
/// Characters that appear after a '\0' character are not searched.
/// haystack: First string.
/// needle: Second string.
/// len: Number of bytes to be located.
/// return: s1 if needle is an empty string; if s2 occurs nowhere in s1, NULL 
/// is returned; otherwise a pointer to the first character of the first 
/// occurrence of s2 is returned.

// locate a substring in a string

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)&haystack[i]);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] != '\0' && haystack[i + j] == needle[j]
			&& i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
