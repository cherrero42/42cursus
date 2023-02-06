/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_full_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:48:52 by cherrero          #+#    #+#             */
/*   Updated: 2023/02/04 16:21:39 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_full(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_sorted;
	int		round;

	stack_sorted = ft_copy_stack(*stack_a);
	ft_sort_stack_bubble(stack_sorted);
	ft_update_index(*stack_a, stack_sorted);
	round = (*stack_a)->len;
	while ((*stack_a)->len > 3)
	{
		if ((--round > 3)
			&& ft_last_node(stack_a)->end_pos < ((*stack_a)->len / 2))
			ft_rotate(stack_a, 'a', 1);
		else
			ft_push(stack_a, stack_b, 'b', 1);
	}
	ft_sort_three(stack_a);
	ft_update_index(*stack_a, stack_sorted);
	while ((*stack_b) && (*stack_b)->len > 0)
		ft_exec_move(stack_a, stack_b);
	if (((*stack_a)->end_pos - (*stack_a)->pos > 0))
		ft_rotate_iter(stack_a, 'a', 1, (*stack_a)->end_pos - (*stack_a)->pos);
	else
		ft_reverse_rotate_iter(stack_a, 'a', 1,
			(*stack_a)->end_pos - (*stack_a)->pos);
	ft_free_stack(&stack_sorted);
}

void	ft_exec_move(t_stack **stack_a, t_stack **stack_b)
{
	ft_calc_target(*stack_b, *stack_a);
	ft_calc_near(*stack_b, (*stack_a)->len);
	ft_move(stack_a, stack_b);
}

void	ft_calc_target(t_stack *stack_b, t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_b;
	while (temp)
	{
		temp->target_a = ft_find_endpos_in_stack(temp->end_pos, stack_a);
		temp = temp->next;
	}
}

void	ft_calc_moves(t_stack	*stack_b, t_stack	*temp, int len)
{
	if (temp->pos > stack_b->len / 2)
		temp->moves_b = stack_b->len - temp->pos;
	else
		temp->moves_b = temp->pos * -1;
	if (temp->target_a > len / 2)
		temp->moves_a = len - temp->target_a + 1;
	else
		temp->moves_a = temp->target_a * -1 + 1;
	temp->flag_rotate = 0;
	temp->flag_reverse = 0;
}

void	ft_calc_choose(t_stack	*temp)
{
	int		any_choose;

	any_choose = 0;
	if (temp->moves_a < 0)
	{
		any_choose = temp->moves_a * -1;
		temp->flag_reverse++;
	}
	else
	{
		temp->flag_rotate++;
		any_choose = temp->moves_a;
	}
	if (temp->moves_b < 0)
	{
		any_choose += (temp->moves_b * -1);
		temp->flag_reverse++;
	}
	else
	{
		temp->flag_rotate++;
		any_choose += temp->moves_b;
	}
	temp->moves_total = any_choose;
}
