/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_server_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:43:09 by cherrero          #+#    #+#             */
/*   Updated: 2023/02/24 11:41:49 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk_bonus.h"

void	ft_leaks(void)
{
	system("leaks -q server_bonus");
}

void	ft_read_signal(int sgnl, siginfo_t *info, void *ptr)
{
	static char	octet;
	static int	bit;

	(void)ptr;
	if (sgnl == SIGUSR1)
		octet = octet | (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (octet == '\0')
		{
			kill(info->si_pid, SIGUSR1);
			bit = 0;
			octet = 0;
			write(1, "\n", 1);
			return ;
		}
		write (1, &octet, 1);
		bit = 0;
		octet = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("My PID Server: %i\n", getpid());
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = ft_read_signal;
	while (1)
	{	
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
