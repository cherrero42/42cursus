/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:22:14 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/07 22:01:42 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// split s in substrings with delimiter c

#include "libft.h"

static int	ft_count_c(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			count++;
		i++;
	}
	return (count + 1);
}

static void	*ft_sweep(char **mat)
{
	free(mat);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**data;
	int		i;
	int		iword;
	int		begin;

	if (!s)
		return (NULL);
	data = (char **) malloc (sizeof(char *) * (ft_count_c(s, c) + 1));
	if (!data)
		return (ft_sweep(data));
	i = 0;
	iword = 0;
	while (s[i] && iword < ft_count_c(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		begin = i;
		while (s[i] && s[i] != c)
			i++;
		if (begin != i)
			data[iword++] = ft_substr(s, begin, (i - begin));
	}
	data[iword] = 0;
	return (data);
}
