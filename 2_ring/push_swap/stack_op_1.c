/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:21:27 by cherrero          #+#    #+#             */
/*   Updated: 2023/02/04 15:39:16 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initnode(t_stack **new, int data, int end_pos, int len)
{
	(*new) = (t_stack *)malloc(sizeof(t_stack));
	if (!(*new))
		return ;
	(*new)->data = data;
	(*new)->end_pos = end_pos;
	(*new)->len = len;
	(*new)->moves_a = 0;
	(*new)->moves_b = 0;
	(*new)->target_a = 0;
	(*new)->moves_total = 0;
	(*new)->flag_rotate = 0;
	(*new)->flag_reverse = 0;
	(*new)->next = NULL;
}

void	ft_addnode(t_stack **stack, int data, int end_pos)
{
	t_stack			*new;
	t_stack			*tmp;
	unsigned int	i;

	i = 1;
	ft_initnode(&new, data, end_pos, 0);
	if (*stack == NULL)
	{
		(*stack) = new;
		(*stack)->len = 1;
		(*stack)->pos = i;
	}
	else
	{
		i++;
		tmp = *stack;
		tmp->len++;
		while (tmp->next != NULL)
		{
			i++;
			tmp = tmp->next;
		}
		new->pos = i;
		tmp->next = new;
	}
}

static int	ft_is_tab(char st)
{
	int	flag;

	flag = 0;
	if (st == ' ' || st == '\n' || st == '\t' || st == '\v')
		flag = 1;
	if (flag == 0 && (st == '\f' || st == '\r'))
		flag = 1;
	return (flag);
}

long	ft_atol(const char *str)
{
	long	rst;
	int		iter;
	long	neg;

	rst = 0;
	iter = 0;
	neg = 1;
	while (ft_is_tab(str[iter]))
	{
		iter++;
	}
	if ((str[iter] == '-') || (str[iter] == '+'))
	{
		if (str[iter] == '-')
			neg = -1;
		iter++;
	}
	while (str[iter] >= '0' && str[iter] <= '9')
	{
		rst = (rst * 10) + str[iter] - '0';
		iter++;
	}
	return (rst * neg);
}

int	ft_check_input(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	if (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] != '\0')
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}
