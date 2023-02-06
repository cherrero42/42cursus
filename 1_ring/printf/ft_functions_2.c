/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:51:37 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/21 23:33:29 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printi_char(char c, int *it)
{
	write(1, &c, 1);
	(*it)++;
}

void	ft_printi_str(char *str, int *it)
{
	int	i;

	i = 0;
	if (str == NULL)
		ft_printi_str("(null)", it);
	else
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			(*it)++;
			i++;
		}
	}
}

void	ft_printi_number(int n, int *it)
{
	if (n == -2147483648)
		ft_printi_str("-2147483648", it);
	else if (n < 0)
	{
		ft_printi_char('-', it);
		n = -n;
	}
	if (n >= 0)
	{
		if (n > 9)
			ft_printi_number(n / 10, it);
		ft_printi_char((n % 10) + 48, it);
	}
}

void	ft_printi_unsigned(unsigned int n, int *it)
{
	if (n >= 10)
		ft_printi_unsigned(n / 10, it);
	ft_printi_char(n % 10 + '0', it);
}
