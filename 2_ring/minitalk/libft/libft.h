/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:12:25 by cherrero          #+#    #+#             */
/*   Updated: 2022/10/02 15:24:35 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// alphabetic character test
int		ft_isalpha(int c);
// tests any character which isalpha(3) or isdigit(3) is true
int		ft_isalnum(int c);
// tests whether c is a 7-bit
int		ft_isascii(int c);
// tests for a decimal digit character
int		ft_isdigit(int c);
// tests for any printing character, including space
int		ft_isprint(int c);
// upper case to lower case letter conversion
int		ft_tolower(int c);
// lower case to upper case letter conversion
int		ft_toupper(int c);

// string to integer
int		ft_atoi(const char *str);
// write zeroes to a byte string
void	ft_bzero(void *s, size_t n);
// integer to string
char	*ft_itoa(int n);
// apply function 'f' on each character inside 's', out a new string
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// apply function 'f' on each character inside 's'
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
// send char to file descriptor
void	ft_putchar_fd(char c, int fd);
// send string to file descriptor
void	ft_putstr_fd(char *s, int fd);
// send string to file descriptor & \n
void	ft_putendl_fd(char *s, int fd);
// send integer to file descriptor
void	ft_putnbr_fd(int n, int fd);

// allocates count objects * size. is filled with bytes of value zero
void	*ft_calloc(size_t count, size_t size);
// allocates sufficient memory for a copy of the string
char	*ft_strdup(const char *s1);
// returns a substring of the string 's'; 'start' and maximum length 'len'
char	*ft_substr(char const *s, unsigned int start, size_t len);
// copies n bytes from memory area src to memory area dst
void	*ft_memcpy(void *dst, const void *src, size_t n);
// locates the first occurrence of c (converted to unsigned char) in string s
void	*ft_memchr(const void *s, int c, size_t n);
// compares byte string s1 against byte string s2
int		ft_memcmp(const void *s1, const void *s2, size_t n);
// returns len os string 's'
size_t	ft_strlen(const char *s);
// strlcpy() function copy strings with the same input parameters
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
// join s1, s2
char	*ft_strjoin(char const *s1, char const *s2);
// compares not more than n characters
int		ft_strncmp(char *s1, char *s2, unsigned int n);
// locate character in string
char	*ft_strchr(const char *s, int c);
// locates last occurrence of c (converted to char) in string pointed to by s
char	*ft_strrchr(const char *s, int c);
// locate a substring in a string
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
/**
 * Remove all characters from the string 'set'
 * from the beginning and from the end of 's1', until
 * find a character not belonging to 'set'
 */
char	*ft_strtrim(char const *s1, char const *set);
// fill a byte string with a byte value
void	*ft_memset(void *str, int c, size_t n);
// copies len bytes from string src to string dst
void	*ft_memmove(void *dst, const void *src, size_t len);

// split s in substrings with delimiter c
char	**ft_split(char const *s, char c);
// new node
t_list	*ft_lstnew(void *content);
// add node ’new’ to the begin of lista ’lst’
void	ft_lstadd_front(t_list **lst, t_list *new);
// number of nodes of list
int		ft_lstsize(t_list *lst);
// return last element of list
t_list	*ft_lstlast(t_list *lst);
// add node ’new’ to the end of lista ’lst’
void	ft_lstadd_back(t_list **lst, t_list *new);
// del and free node ’lst’
void	ft_lstdelone(t_list *lst, void (*del)(void *));
// del and free node ’lst’ and subsequents
void	ft_lstclear(t_list **lst, void (*del)(void *));
// iter list ’lst’ and apply 'f'
void	ft_lstiter(t_list *lst, void (*f)(void *));
// iter list ’lst’ and apply 'f'. Return a list
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
