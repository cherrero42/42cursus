/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:01:43 by cherrero          #+#    #+#             */
/*   Updated: 2023/02/17 16:16:49 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <string.h>

//server
void	ft_read_signal(int sgnl, siginfo_t *info, void *ptr);
//client
void	ft_alert(int signal);
//static void	ft_send_str(int pid, char *str);
#endif
