/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:08:51 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/02/13 18:41:57 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
compares the first n characters of the object 
pointed to by str1 to the first n characters of the object pointed to by str2.
If the n characters of s1 and s2 are the same then it returns 0,
otherwise, it returns a non-zero value
*/

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = str1;
	s2 = str2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
