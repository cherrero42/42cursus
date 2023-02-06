/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:21:27 by cherrero          #+#    #+#             */
/*   Updated: 2023/02/04 15:39:22 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	unsigned int	is_sorted;

	is_sorted = 1;
	while (stack->next && is_sorted && stack->next->pos >= 0)
	{
		if (stack->data < stack->next->data)
			is_sorted = 0;
		stack = stack->next;
	}	
	return (is_sorted);
}

int	ft_stack_is_empty(t_stack *stack)
{
	if (stack)
		return (0);
	else
		return (1);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = tmp->next;
		free(tmp);
	}	
	*stack = NULL;
}

t_stack	*ft_last_node(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	ft_del_last_node(t_stack **stack)
{
	t_stack	*temp;

	if ((stack == NULL) || ((*stack) == NULL))
		return ;
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return ;
	}	
	temp = *stack;
	if (temp -> next == NULL)
		return (ft_free_stack(&temp));
	if (temp -> next == NULL)
	{	
		temp = NULL;
		*stack = NULL;
		return (free (temp));
	}
	while (temp->next->next)
		temp = temp -> next;
	free(temp->next);
	temp -> next = NULL;
	(*stack)->len--;
}
