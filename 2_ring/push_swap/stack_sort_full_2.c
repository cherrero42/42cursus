/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_full_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:48:52 by cherrero          #+#    #+#             */
/*   Updated: 2023/02/02 15:17:40 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_first_end_pos(t_stack *stack_a)
{
	if (stack_a->end_pos < stack_a->next->end_pos
		&& stack_a->end_pos < stack_a->next->next->end_pos)
		return (1);
	else
		return (0);
}

int	ft_second_end_pos(t_stack *stack_a)
{
	if ((stack_a->end_pos > stack_a->next->end_pos
			&& stack_a->end_pos < stack_a->next->next->end_pos)
		|| (stack_a->end_pos < stack_a->next->end_pos
			&& stack_a->end_pos > stack_a->next->next->end_pos))
		return (1);
	else
		return (0);
}

int	ft_third_end_pos(t_stack *stack_a)
{
	if (stack_a->end_pos > stack_a->next->end_pos
		&& stack_a->end_pos > stack_a->next->next->end_pos)
		return (1);
	else
		return (0);
}

int	ft_small_second_end_pos(t_stack *stack_a)
{
	if (stack_a->next->end_pos < stack_a->next->next->end_pos)
		return (1);
	else
		return (0);
}

void	ft_sort_three(t_stack **stack_a)
{
	if (ft_is_sorted(*stack_a))
		return ;
	if (ft_first_end_pos(*stack_a))
		ft_swap(stack_a, 'a', 1);
	else if (ft_second_end_pos(*stack_a))
		if (ft_small_second_end_pos(*stack_a))
			ft_reverse_rotate_and_swap(stack_a, 'a', 1);
	else
		ft_rotate(stack_a, 'a', 1);
	else if (ft_third_end_pos(*stack_a))
	{
		if (ft_small_second_end_pos(*stack_a))
			ft_reverse_rotate(stack_a, 'a', 1);
		else
			ft_rotate_and_swap(stack_a, 'a', 1);
	}
}
