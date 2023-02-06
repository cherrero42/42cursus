/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:17:15 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/02 12:45:10 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// isalnum() function tests any character which isalpha(3) or isdigit(3) is true

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
