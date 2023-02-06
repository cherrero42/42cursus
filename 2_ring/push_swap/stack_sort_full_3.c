/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_full_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:48:52 by cherrero          #+#    #+#             */
/*   Updated: 2023/02/04 18:08:47 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_calc_near(t_stack *stack_b, int len)
{
	t_stack	*temp;

	temp = stack_b;
	while (temp)
	{
		ft_calc_moves(stack_b, temp, len);
		ft_calc_choose(temp);
		temp = temp->next;
	}
}

int	ft_min_endpos(t_stack *stack_a)
{
	t_stack	*temp;
	int		min;
	int		minpos;

	temp = stack_a;
	min = temp->end_pos;
	minpos = temp->pos;
	while (temp)
	{
		if (temp->end_pos < min)
		{
			minpos = temp->pos;
			min = temp->end_pos;
		}
		temp = temp->next;
	}
	return (minpos);
}

int	ft_find_endpos_in_stack(int ind, t_stack *stack_a)
{
	t_stack	*temp;
	int		pos;
	int		minmax;

	pos = 1;
	temp = stack_a;
	minmax = 9999;
	pos = ft_min_endpos(stack_a);
	while (temp)
	{
		if (ind < temp->end_pos)
		{
			if (temp->end_pos < minmax)
			{
				pos = temp->pos;
				minmax = temp->end_pos;
			}
		}
		temp = temp->next;
	}
	return (pos);
}

void	ft_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		choose;
	int		pos_b_to_move;
	int		done;

	choose = 0;
	done = 0;
	temp = *stack_b;
	while (temp)
	{
		if (temp->moves_total < choose || choose == 0)
		{
			choose = temp->moves_total;
			pos_b_to_move = temp->pos;
		}
		temp = temp->next;
	}
	temp = *stack_b;
	while (temp)
	{
		if (temp->pos == pos_b_to_move && !done++)
			ft_move2(temp, stack_a, stack_b);
		temp = temp->next;
	}
	ft_push(stack_b, stack_a, 'a', 1);
}

void	ft_move2(t_stack *temp, t_stack **stack_a, t_stack **stack_b)
{
	if (temp->moves_a < 0)
		ft_reverse_rotate_iter(stack_a, 'a', 1, temp->moves_a * -1);
	else
		ft_rotate_iter(stack_a, 'a', 1, temp->moves_a);
	if (temp->moves_b < 0)
		ft_reverse_rotate_iter(stack_b, 'b', 1, temp->moves_b * -1);
	else
		ft_rotate_iter(stack_b, 'b', 1, temp->moves_b);
}
