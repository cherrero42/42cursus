/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:14:31 by cherrero          #+#    #+#             */
/*   Updated: 2023/01/11 18:07:03 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static char	*read_buff(char *content, int fd)
{
	char	*temp;
	int		length;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	length = 999;
	while (length > 0 && ft_strpos(content, '\n') < 0)
	{
		length = read(fd, temp, BUFFER_SIZE);
		if (length == -1)
			return (free(temp), free(content), NULL);
		if (length == 0 && content)
			return (free(temp), content);
		if (length == 0 && !content)
			return (free(temp), NULL);
		temp[length] = '\0';
		if (!content)
			content = ft_strdup("");
		content = ft_strjoin_gnl(content, temp);
		if (!content)
			return (free(temp), NULL);
	}
	return (free(temp), content);
}

static char	*extract_line(char *content)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	j++;
	if (content[i] == '\0')
		return (NULL);
	while (content[i] != '\n' && content[i] != '\0')
		i++;
	temp = malloc (sizeof(char) * (i + 2));
	if (!temp)
		return (free(content), NULL);
	temp[i + 1] = '\0';
	while (i >= 0)
	{
		temp[i] = content[i];
		i--;
	}
	return (temp);
}

static char	*mant_line(char *content)
{
	char	*temp;
	int		i;
	int		it;

	i = 0;
	it = 1;
	while (content[i] != '\n' && content[i])
		i++;
	if (content[i] == '\0')
		return (free(content), NULL);
	temp = malloc(sizeof(char) * (ft_strlen(content) + 1 - i));
	if (!temp)
		return (NULL);
	while (content[i + it])
	{
		temp [it - 1] = content[i + it];
		it++;
	}
	temp[it - 1] = '\0';
	if (ft_strlen(temp) == 0)
		return (free(temp), free(content), NULL);
	return (free(content), temp);
}

char	*get_next_line(int fd)
{
	static char	*next;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next = read_buff(next, fd);
	if (!next)
		return (NULL);
	temp = extract_line(next);
	if (!temp)
		return (free(next), NULL);
	next = mant_line(next);
	if (!next)
		free(next);
	return (temp);
}
