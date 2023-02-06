/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:51:37 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/21 23:36:07 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printi_hex(unsigned long long n, const char format, int *it)
{
	if (format == 'X')
		ft_printi_base(n, "0123456789ABCDEF", 16, it);
	else if (format == 'x')
		ft_printi_base(n, "0123456789abcdef", 16, it);
}

void	ft_printi_ptr(unsigned long long n, int *it)
{
	ft_printi_str("0x", it);
	ft_printi_baselo(n, "0123456789abcdef", 16, it);
}

void	ft_printi_base(unsigned int n, const char *str, int base, int *it)
{
	if (n >= (unsigned int) base)
		ft_printi_base(n / base, str, base, it);
	ft_printi_char(str[n % base], it);
}

void	ft_printi_baselo(unsigned long long n, const char *str,
			int base, int *it)
{
	if (n >= (unsigned long long) base)
		ft_printi_baselo(n / base, str, base, it);
	ft_printi_char(str[n % base], it);
}
