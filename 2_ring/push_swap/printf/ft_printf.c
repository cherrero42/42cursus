/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:51:37 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/21 23:35:35 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// like original printf() 
//
// %c 	Print a single character.
// %s 	Print a string of characters.
// %p 	The void * pointer argument is printed in hexadecimal.
// %d 	Print a decimal (base 10) number.
// %i 	Print an integer in base 10.
// %u 	Print an unsigned decimal (base 10) number.
// %x 	Print a number in hexadecimal (base 16), with lowercase.
// %X 	Print a number in hexadecimal (base 16), with uppercase.
// %% 	Print a percent sign.

#include "ft_printf.h"

/////////////////////////////////#include <stdio.h>

// evalua el modificador de la linea de argumentos e imprime la cadena

/// @brief 
/// @param car 
/// @param arg 
/// @param count 
void	ft_check(char car, va_list arg, int *count)
{
	if (car == 'c')
		ft_printi_char(va_arg(arg, int), count);
	else if (car == 's')
		ft_printi_str(va_arg(arg, char *), count);
	else if (car == 'p')
		ft_printi_ptr(va_arg(arg, unsigned long long), count);
	else if (car == 'd' || car == 'i')
		ft_printi_number(va_arg(arg, int), count);
	else if (car == '%')
		ft_printi_char('%', count);
	else if (car == 'u')
		ft_printi_unsigned(va_arg(arg, unsigned int), count);
	else if (car == 'X' || car == 'x')
		ft_printi_hex(va_arg(arg, int), car, count);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		count;
	va_list	arg;

	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{	
		while (str[i] != '%' && str[i])
		{
			ft_printi_char(str[i], &count);
			i++;
		}
		if (str[i] == '%')
		{
			i++;
			ft_check(str[i], arg, &count);
			i++;
		}
	}
	va_end(arg);
	return (count);
}

//  int main(void)
//  {
// 	ft_printf("Hola%p", 9223372036854775807);
// ft_printf("%p", " ");
// printf("%p", " ");
//  	//printf("Hola%s\n", "s");
//  	printf("->FL:%i<+--", ft_printf("Hola%i\n", 876));
//printf("->L :%i<---", printf("Hola%p\n", 9223372036854775807));
// 	printf("\n");
//  	printf("->FL:%i<+--", ft_printf("Hola%i_%i\n", 8, -1234));
//  	printf("->L :%i<---", printf("Hola%i_%i\n", 8, -1234));
//  }
