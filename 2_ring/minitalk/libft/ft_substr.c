/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:26:21 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/08 14:00:13 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// Reserves (with malloc) and returns a substring of the string ’s’. 
/// The substring begins in 'start’ and has a max ’len’.
/// s: string from where to create the substring. 
/// start: index of char in 's' from where to begin substring.
/// len: The max length of the substring.
/// Return: The substring of NULL if the memory reservation fails.

// returns a substring of the string 's'; 'start' and maximum length 'len'

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str1;
	unsigned int	i;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	str1 = (char *) malloc(sizeof(char) * (len + 1));
	if (!str1)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		str1[i] = s[i + start];
		i++;
	}
	str1[i] = 0;
	return (str1);
}
