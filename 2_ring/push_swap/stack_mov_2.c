/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mov_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 08:45:10 by cherrero          #+#    #+#             */
/*   Updated: 2023/02/04 22:25:27 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_iter(t_stack **stack, char name_stack, int print, int iter)
{
	while (iter--)
		ft_rotate(stack, name_stack, print);
}

// reverse rotate - desplaza hacia abajo todos los elementos del stack una
// posición, de forma que el último elemento se convierte en el primero.

void	ft_reverse_rotate(t_stack **stack, char name_stack, int print)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	t_node	tmp_node;

	if (!(*stack) || !((*stack)->next))
		return ;
	ft_read_node(*stack, &tmp_node);
	(*stack)->len = 0;
	tmp = (*stack)->next;
	tmp2 = *stack;
	*stack = (*stack)->next;
	free(tmp2);
	while (tmp->next)
	{
		tmp->pos--;
		tmp = tmp->next;
	}
	ft_minus(tmp);
	(*stack)->len = tmp_node.len;
	ft_initnode(&tmp2, tmp_node.data, tmp_node.end_pos, 0);
	tmp2->pos = tmp_node.len;
	tmp2->next = NULL;
	tmp->next = tmp2;
	if (print)
		ft_printf("rr%c\n", name_stack);
}

void	ft_reverse_rotate_both(t_stack **stack_1, t_stack **stack_2, int print)
{
	ft_reverse_rotate(stack_1, 'a', 0);
	ft_reverse_rotate(stack_2, 'b', 0);
	if (print)
		ft_printf("rrr\n");
}

void	ft_reverse_rotate_both_iter(t_stack **stack_1, t_stack **stack_2,
	int print, int iter)
{
	while (iter--)
		ft_reverse_rotate_both(stack_1, stack_2, print);
}

void	ft_reverse_rotate_iter(t_stack **stack, char name_stack,
			int print, int iter)
{
	while (iter--)
		ft_reverse_rotate(stack, name_stack, print);
}
