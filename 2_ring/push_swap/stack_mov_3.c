/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mov_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 08:45:10 by cherrero          #+#    #+#             */
/*   Updated: 2023/02/04 22:26:22 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_and_swap(t_stack **stack_a, char c, int print)
{
	ft_reverse_rotate(stack_a, c, print);
	ft_swap(stack_a, c, print);
}

void	ft_rotate_and_swap(t_stack **stack_a, char c, int print)
{
	ft_rotate(stack_a, c, print);
	ft_swap(stack_a, c, print);
}

void	ft_read_node(t_stack *stack, t_node *node)
{
	(*node).len = stack->len;
	(*node).data = stack->data;
	(*node).end_pos = stack->end_pos;
}

void	ft_minus(t_stack *tmp)
{
	tmp->pos--;
	tmp->len = 0;
}
