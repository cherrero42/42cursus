/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:52:16 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/02 00:53:55 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// calloc() function contiguously allocates enough space for count objects 
//   that are size bytes of memory each and returns a pointer to the allocated
//   memory.  The allocated memory is filled with bytes of value zero.

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	p = (char *) malloc(sizeof(char) * (count * size));
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}
