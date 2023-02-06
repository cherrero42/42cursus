/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:17:50 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/02 12:50:07 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The isascii() function shall test whether c is a 7-bit US-ASCII
//   character code.

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
