/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:43:26 by cherrero          #+#    #+#             */
/*   Updated: 2023/02/24 13:00:52 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_leaks(void)
{
	system("leaks -q client");
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
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (ft_printf ("Incorrect number of arguments\n"), -1);
	ft_send_str(ft_atoi(argv[1]), argv[2]);
}
