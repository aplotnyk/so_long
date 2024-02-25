/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:19:10 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/02/19 21:12:31 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
searches at most n characters to locate the first occurrence 
in the string pointed to by s1 of the sequence of characters
(excluding the terminating null character) in the string pointed to by s2.
Returns a pointer to the located string, 
or a null pointer if the string is not found. 
If s2 points to a string with zero length, strnstr returns s1.
*/

#include "libft.h"

static int	s2included(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (*s2 == '\0');
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	if (n == 0)
		return (NULL);
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i <= n - ft_strlen(s2))
	{
		if (s2included(&s1[i], s2))
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
