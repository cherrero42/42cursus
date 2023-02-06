/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:56:35 by cherrero          #+#    #+#             */
/*   Updated: 2023/02/04 13:34:33 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlen(s1))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i++] == '\0')
			break ;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		gate;

	gate = 0;
	if (argc == 1)
		return (0);
	gate = ft_read_args(&stack_a, argc, argv);
	if (gate)
	{
		if (gate == 9999)
			return (-99999);
		else
			return (gate);
	}
	if (ft_read_lines(&stack_a, &stack_b))
	{
		if (ft_is_sorted(stack_a) && (!stack_b || stack_b->len == 0))
			return (write(1, "OK\n", 3), 0);
		else
			return (write(1, "KO\n", 3), 255);
	}
}

int	ft_read_lines(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int		flag;

	flag = 1;
	while (flag)
	{
		line = get_next_line(0);
		if (!line)
			return (1);
		if (ft_read_lines_2(stack_a, stack_b, line))
			return (255);
	}
	return (0);
}

int	ft_read_lines_2(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strcmp(line, "pa\n") == 0)
		ft_push(stack_b, stack_a, 'a', 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_push(stack_a, stack_b, 'b', 0);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_rotate(stack_a, 'a', 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rotate(stack_a, 'b', 0);
	else if (ft_strcmp(line, "sa\n") == 0)
		ft_swap(stack_a, 'a', 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_swap(stack_b, 'b', 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_swap_both(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rotate_both(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_reverse_rotate(stack_a, 'a', 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_reverse_rotate(stack_b, 'b', 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_reverse_rotate_both(stack_a, stack_b, 0);
	else
		return (255);
	return (0);
}
