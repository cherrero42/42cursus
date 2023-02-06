/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:21:27 by cherrero          #+#    #+#             */
/*   Updated: 2023/02/04 15:39:20 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_read_args(t_stack **stack, int argc, char **argv)
{
	int	i;

	if (argc > 2 || (argc == 2 && ft_check_input(argv[1])
			&& ft_is_integer(ft_atol(argv[1]))))
	{
		i = 1;
		while (i < argc)
			if (!ft_check_input(argv[i++]))
				return (ft_putstr_fd("Error\n", 2), 99);
		if (!ft_args_numbers(stack, argc, argv))
			return (ft_free_stack(stack), ft_putstr_fd("Error\n", 2), 255);
		else
			return (0);
	}
	if (argc == 2)
		if (!ft_args_string(stack, argc, argv))
			return (ft_free_stack(stack), ft_putstr_fd("Error\n", 2), 255);
	if (argc == 1)
		return (0);
	return (0);
}

int	ft_is_integer(long nb)
{
	if (nb >= INT_MIN && nb <= INT_MAX)
	{
		return (1);
	}
	else
		return (0);
}

int	ft_args_numbers(t_stack **stack, int argc, char **argv)
{
	int		i;
	long	nb;

	i = 1;
	while (i < argc)
	{	
		if (!ft_check_input(argv[argc - i]))
			return (ft_free_stack(stack), 0);
		nb = ft_atol(argv[argc - i++]);
		if (ft_is_integer(nb) && !ft_find_data_in_stack(nb, *stack))
		{
			ft_addnode(stack, nb, 0);
		}
		else
		{
			return (ft_free_stack(stack), 0);
		}
	}
	return (1);
}

int	ft_args_string(t_stack **stack, int argc, char **argv)
{
	char	**arr;
	int		i;
	long	nb;
	int		gate;

	(void)argc;
	i = 0;
	gate = 0;
	arr = ft_split(argv[1], ' ');
	while (arr[i])
		i++;
	while (--i > -1)
	{	
		if (!ft_check_input(arr[i]))
			return (ft_free_stack(stack), ft_free_array(arr), 0);
		nb = ft_atol(arr[i]);
		if (ft_is_integer(nb) && !ft_find_data_in_stack(nb, *stack))
		{
			ft_addnode(stack, nb, 0);
			gate = 1;
		}
		else
			return (ft_free_array(arr), ft_free_stack(stack), 0);
	}
	return (ft_free_array(arr), gate);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] && array[i++][0] != '\0')
		free(array[i - 1]);
	free(array);
}	
