/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:51:37 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/21 23:36:43 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_printi_char(char c, int *it);
void	ft_printi_str(char *str, int *it);
void	ft_printi_number(int n, int *it);
void	ft_printi_unsigned(unsigned int n, int *it);
void	ft_printi_hex(unsigned long long nbr, const char format, int *it);
void	ft_printi_ptr(unsigned long long n, int *it);
void	ft_printi_base(unsigned int n, const char *str, int base, int *it);
void	ft_printi_baselo(unsigned long long n, const char *str, int base,
			int *it);
void	ft_check(char car, va_list arg, int *count);
int		ft_printf(char const *str, ...);

#endif
