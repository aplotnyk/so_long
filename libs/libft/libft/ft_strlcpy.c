/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:37:25 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/02/13 17:33:54 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function copies up to size − 1 characters 
from the NUL terminated string src to dst
NUL-terminating the result. */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t s)
{
	size_t	i;

	i = 0;
	if (s != 0)
	{
		while (src[i] != '\0' && i < s - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
