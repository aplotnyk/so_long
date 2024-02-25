/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:37:22 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/02/22 17:31:57 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t s)
{
	size_t	i;
	size_t	j;
	size_t	result;

	i = 0;
	j = 0;
	if (s <= 0)
		return (s + ft_strlen(src));
	while (dst[i] && i < s)
		i++;
	while (src[j])
		j++;
	if (s > i)
		result = i + j;
	else
		result = s + j;
	j = 0;
	while (src[j] && (i < s - 1) && s != 0)
		dst[i++] = src[j++];
	if (s > i)
		dst[i] = '\0';
	return (result);
}
