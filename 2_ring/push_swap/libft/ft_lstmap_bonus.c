/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:40:25 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/02 15:47:58 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// iter list ’lst’ and apply 'f'. Return a list

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_ft;
	t_list	*final_lst;

	if (!lst || !f)
		return (NULL);
	final_lst = 0;
	while (lst != 0)
	{
		new_ft = ft_lstnew(f(lst->content));
		if (!new_ft)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&final_lst, new_ft);
		lst = lst->next;
	}
	return (final_lst);
}
