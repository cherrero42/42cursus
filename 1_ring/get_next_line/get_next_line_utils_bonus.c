/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:14:31 by cherrero          #+#    #+#             */
/*   Updated: 2022/11/22 11:22:24 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*aux;
	size_t	i;
	size_t	j;
	size_t	size_s1;
	size_t	size_s2;

	i = 0;
	j = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	aux = (char *) malloc (sizeof(char) * (size_s1 + size_s2 + 1));
	if (!aux)
		return (NULL);
	while (i < size_s1)
	{	
		aux[i] = s1[i];
		i++;
	}
	while (j < size_s2)
	{
		aux[i + j] = s2[j];
		j++;
	}
	aux[i + j] = '\0';
	return (free(s1), aux);
}

int	ft_strpos(const char *s, int c)
{
	unsigned char	chr;
	int				i;

	if (!s)
		return (-1);
	i = 0;
	chr = (unsigned char)c;
	while (s[i] != chr && s[i] != '\0')
		i++;
	if (s[i] == '\0' && (i) >= (int)ft_strlen(s))
			i = -1;
	return (i);
}
