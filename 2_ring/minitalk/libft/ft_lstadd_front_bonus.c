/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:16:45 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/02 12:57:06 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// add node ’new’ to the begin of lista ’lst’

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
