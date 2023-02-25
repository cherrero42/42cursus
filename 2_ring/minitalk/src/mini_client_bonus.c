/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_client_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:43:26 by cherrero          #+#    #+#             */
/*   Updated: 2023/02/24 12:59:19 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk_bonus.h"

void	ft_leaks(void)
{
	system("leaks -q client_bonus");
}

void	ft_alert(int signal)
{
	static int	num_bytes = 0;

	if (signal == SIGUSR2)
		num_bytes++;
	else
	{
		ft_printf("\n %d bytes received in server.\n\n", num_bytes);
		exit(0);
	}
}

static void	ft_send_str(int pid, char *str)
{
	int		bit;
	char	octet;

	while (*str)
	{
		bit = 8;
		octet = *str++;
		while (bit--)
		{
			if (octet >> bit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR2);
		usleep(10);
	}
}

int	main(int argc, char **argv)
{
	ft_printf("My PID Client: %i\n", getpid());
	signal(SIGUSR1, ft_alert);
	signal(SIGUSR2, ft_alert);
	if (argc != 3)
		return (ft_printf ("Incorrect number of arguments\n"), -1);
	ft_send_str(ft_atoi(argv[1]), argv[2]);
	ft_send_str(ft_atoi(argv[1]), "\0");
}
