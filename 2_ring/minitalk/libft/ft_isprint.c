/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:19:34 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/02 12:51:18 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  isprint() function tests for any printing character, including space (` ')

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
