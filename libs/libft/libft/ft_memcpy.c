/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:31:19 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/02/17 21:06:56 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*newdest;
	char	*newsrc;

	if (!src && !dest)
		return (NULL);
	i = 0;
	newdest = (char *)dest;
	newsrc = (char *)src;
	while (i < n)
	{
		newdest[i] = newsrc[i];
		i++;
	}
	return ((void *)(dest));
}
