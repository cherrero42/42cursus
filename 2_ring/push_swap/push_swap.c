/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:15:32 by cherrero          #+#    #+#             */
/*   Updated: 2023/02/04 22:28:38 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

void	push_swap(int argc, char **argv)
{
	(void) argv;
	if (argc == 1)
		return ;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_sorted;
	int		gate;

	gate = 0;
	if (argc == 1)
		return (0);
	gate = ft_read_args(&stack_a, argc, argv);
	if (gate)
		return (gate);
	if (stack_a->len == 2)
		if (stack_a->data < stack_a->next->data)
			ft_swap(&stack_a, 'a', 1);
	if (stack_a->len == 1)
		return (0);
	if (ft_is_sorted(stack_a) || stack_a->len < 3)
		return (0);
	stack_sorted = ft_copy_stack(stack_a);
	ft_sort_stack_bubble(stack_sorted);
	ft_update_index(stack_a, stack_sorted);
	ft_sort_full(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (ft_free_stack(&stack_sorted), 0);
}
