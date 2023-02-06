/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:22:14 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/02 15:34:45 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Remove all characters from the string 'set'
 * from the beginning and from the end of 's1', until
 * find a character not belonging to 'set'
 */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	int		i;
	int		length;

	if (!set)
		return (ft_strdup((char *)s1));
	if (!s1)
		return (0);
	length = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (length > 0 && ft_strchr(set, s1[length]))
		--length;
	tab = ft_substr(s1, i, (length - i + 1));
	return (tab);
}
