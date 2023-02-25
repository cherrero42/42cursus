/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:22:14 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/02 10:47:58 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The strncmp() function compares not more than n characters.
//RETURN VALUES
//     The strcmp() and strncmp() functions return an integer greater than,
//     equal to, or less than 0, according as the string s1 is greater than,
//     equal to, or less than the string s2.  The comparison is done using
//     unsigned characters, so that `\200' is greater than `\0'

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			break ;
		++i;
	}
	return (0);
}
