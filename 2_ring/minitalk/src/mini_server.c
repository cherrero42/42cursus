/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:43:09 by cherrero          #+#    #+#             */
/*   Updated: 2023/02/24 12:59:36 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_leaks(void)
{
	system("leaks -q server");
}

void	ft_read_signal(int sgnl)
{
	static char	octet;
	static int	bit;

	if (sgnl == SIGUSR1)
		octet = octet | (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", octet);
		bit = 0;
		octet = 0;
	}
}

int	main(void)
{
	ft_printf("My PID Server: %i\n", getpid());
	while (1)
	{
		signal (SIGUSR1, ft_read_signal);
		signal (SIGUSR2, ft_read_signal);
		pause ();
	}
	return (0);
}
